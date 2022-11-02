#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
int n;
vector<pair<int,int> > ans,A;
vector<pair<int,int> > solve(int l,int r) {
	vector<pair<int,int> > res,A; res.clear();
	if (l==r) return res;
	if (l+1==r) {
		res.push_back(make_pair(l,r));
		return res;
	}
	int mid=(l+r)/2;
	A=solve(l,mid);
	for (int i=0;i<(int)A.size();i++) res.push_back(A[i]);
	for (int i=0;i<(int)A.size();i++) res.push_back(make_pair(A[i].first+mid+1-l,A[i].second+mid+1-l));
	for (int i=l;i<=mid;i++) res.push_back(make_pair(i,i+mid+1-l));
	return res;
}

int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	int x=1; while (x*2<=n) x*=2;
	ans=solve(1,x);
	if (x<n) {
		A=solve(n-x+1,n);
		for (int i=0;i<(int)A.size();i++) ans.push_back(A[i]);
	}
	printf("%d\n",(int)ans.size());
	for (int i=0;i<(int)ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);	
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/