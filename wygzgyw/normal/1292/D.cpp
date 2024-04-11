#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=5010;
int n,cnt[maxn],pre[maxn][maxn];
int mx[maxn],a,d[maxn];
ll ans,tmp;
int main() {
//	freopen("1.txt","r",stdin);
	read(n); int x;
	for (int i=1;i<=n;i++) read(x),cnt[x]++;
	for (int i=1;i<maxn;i++) {
		for (int j=1;j<maxn;j++) pre[i][j]=pre[i-1][j];
		tmp=i;
		for (int j=2;j*j<=tmp;j++) {
			while (tmp%j==0) pre[i][j]++,tmp/=j;
		}
		if (tmp>1) pre[i][tmp]++;
	}
	for (int i=1;i<maxn;i++) {
		if (!cnt[i]) { mx[i]=1; continue; }
		mx[i]=1;
		for (int j=1;j<maxn;j++) {
			if (pre[i][j]) mx[i]=max(mx[i],j);
			ans+=(ll)pre[i][j]*cnt[i];
		}
	}
	tmp=ans;
	while (1) {
		a=0;
		for (int i=1;i<maxn;i++) a=max(a,mx[i]);
		if (a==1) break;
		memset(d,0,sizeof(d));
		for (int i=1;i<maxn;i++) d[mx[i]]+=cnt[i];
		a=1;
		for (int i=2;i<maxn;i++)
			if (d[a]<d[i]) a=i;
		if (d[a]*2<=n||a==1) break;
		tmp+=n-d[a]; tmp-=d[a];
		ans=min(ans,tmp);
		for (int i=1;i<maxn;i++) {
			if (mx[i]==a) {
				pre[i][a]--;
				while (mx[i]>1&&!pre[i][mx[i]]) mx[i]--;
			} else mx[i]=1;
		}
	}
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