#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int mod=(1e9)+7;
const int maxn=5010;
int n,m,a[maxn],c1[maxn],c2[maxn];
vector<int> g[maxn];
int ans,mx,tmp,sum;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	int x,y;
	for (int i=1;i<=m;i++) {
		read(x); read(y);
		g[x].push_back(y);
	}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	int flag;
	for (int i=0;i<=n;i++) {
		memset(c1,0,sizeof(c1));
		memset(c2,0,sizeof(c2));
		for (int j=1;j<=i;j++) c1[a[j]]++;
		for (int j=i+1;j<=n;j++) c2[a[j]]++;
		flag=0;
		for (int j=0;j<g[a[i]].size();j++)
			if (g[a[i]][j]==c1[a[i]]) { flag=1; break; }
		if (!flag&&i) continue;
		tmp=0; sum=1;
		if (i) tmp++;
		for (int j=1;j<=n;j++) {
			x=y=0;
			while (x<g[j].size()&&g[j][x]<=c1[j]) x++;
			while (y<g[j].size()&&g[j][y]<=c2[j]) y++;
			if (j==a[i]) x=0,y-=(c2[j]>=c1[j]);
			if (!x&&!y) continue;
			if (x>y) swap(x,y);
			if (!x) sum=(ll)sum*y%mod,tmp++;
			else if (y==1) sum=sum*2%mod,tmp++;
			else sum=(ll)sum*x%mod*(y-1)%mod,tmp+=2;
		}
		if (tmp==mx) ans=(ans+sum)%mod;
		else if (mx<tmp) mx=tmp,ans=sum;
	}
	printf("%d %d\n",mx,ans);
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