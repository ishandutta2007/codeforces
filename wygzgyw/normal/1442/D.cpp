#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int n,k;
ll sum[3010],ans;
vector<int> a[3010];
ll f[20][3010];
void update(ll *t,int sz,ll v) {
	for (int i=k;i>=sz;i--)
		t[i]=max(t[i],t[i-sz]+v);
}
void solve(int l,int r,int dep) {
	if (l==r) {
		ll tmp=0;
		for (int i=0;i<=a[l].size();i++) {
			ans=max(ans,f[dep][k-i]+tmp);
			if (i==(int)a[l].size()) break;
			tmp+=a[l][i];
		}
		return;
	}
	int mid=(l+r)/2;
	memcpy(f[dep+1],f[dep],sizeof(ll)*(k+1));
	for (int i=mid+1;i<=r;i++) update(f[dep+1],(int)a[i].size(),sum[i]);
	solve(l,mid,dep+1);
	memcpy(f[dep+1],f[dep],sizeof(ll)*(k+1));
	for (int i=l;i<=mid;i++) update(f[dep+1],(int)a[i].size(),sum[i]);
	solve(mid+1,r,dep+1);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k);
	int t,x;
	for (int i=1;i<=n;i++) {
		read(t);
		while (t--) {
			read(x),a[i].push_back(x);
		}
		while ((int)a[i].size()>k) a[i].pop_back();
		for (int j=0;j<a[i].size();j++) sum[i]+=a[i][j];
	}
	solve(1,n,0);
	printf("%lld\n",ans);
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