#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,a[maxn],pos[maxn],id[maxn];
vector<pair<int,int> > ans;
void change(int i,int j) {
	if (i==j) return;
	pos[a[i]]=j,pos[a[j]]=i;
	swap(a[i],a[j]);
	ans.push_back(make_pair(i,j));
}
bool cmp(int x,int y) {
	if (a[x]==a[y]) return x<y;
	return a[x]<a[y];
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++) a[id[i]]=i;
	for (int i=1;i<=n;i++) pos[a[i]]=i;
	
	for (int i=n;i>=1;i--) {
		for (int j=a[i];j<=i;j++) {
			change(pos[j],i);
		}
		//for (int j=1;j<=n;j++) printf("%d ",a[j]); printf("\n");
	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++) printf("%d %d\n",ans[i].first,ans[i].second);
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