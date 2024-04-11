#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=2e18;
const int maxn=(1e5)+10;
int T,n,ans[maxn];
ll k,mi[maxn];
int now;
void solve(int n) {
	ll sum,hi;
	for (int i=1;i<=n;) {
		sum=0; int lst=n;
		for (int j=i;j<=n;j++) {
			hi=sum;
			if (j==n) sum++;
			else sum+=mi[n-j-1];
			if (sum>=k) { lst=j; break; }
		}
		k-=hi;
	//	printf("%d %d %lld\n",i,lst,sum);
	//	if (i==2) break;
		int cnt=lst;
		for (int j=i;j<=lst;j++)
			ans[j]=cnt,cnt--;
		i=lst+1;
	}
	//for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
}
int main() {
	//freopen("1.txt","r",stdin);
	mi[0]=1;
	for (int i=1;i<maxn;i++) {
		if (mi[i-1]>INF/2) mi[i]=INF;
		else mi[i]=mi[i-1]*2;
	}
	read(T);
	while (T--) {
		read(n),read(k);
		if (mi[n-1]<k) { puts("-1"); continue; }
		int bd=max(n-65,1);
		solve(n-bd+1);
		for (int i=1;i<=n;i++) {
			if (i<bd) printf("%d ",i);
			else printf("%d ",ans[i-bd+1]+bd-1);
		}
		puts("");
	}
	/*read(n);
	for (int i=1;i<=n;i++) p[i]=i;
	do {
		int flag=1;
		for (int i=2;i<=n;i++)
			if (p[i]<p[i-1]-1) { flag=0; break; }
		if (flag) {
			for (int i=1;i<=n;i++) printf("%d ",p[i]);
			puts("");
			ans++;
		}
	} while (next_permutation(p+1,p+n+1));
	printf("%d\n",ans);*/
	return 0;
}
/*
  REMEMBER:
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Array size? Integer overflow? Time complexity? Memory usage? Precision error?
*/