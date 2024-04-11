// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const ll INF=1e18;
const int maxn=(1e4)+10;
int n;
ll a[maxn],ans;
int L[maxn],R[maxn],tot,st[maxn];
pair<int,ll> d[maxn],e[maxn];
int t1,t2;
ll D[maxn],E[maxn];
ll suf[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=n;i>=1;i--) {
		ll mn=INF;
		for (int j=i;j<=n;j++) {
			if (mn>a[j]) mn=a[j]; ans=max(ans,mn*(j-i+1));
		}
		suf[i]=ans;
	}
	ll mx=0;
	for (int i=1;i<=n;i++) {
		ll mn=INF;
		for (int j=i;j>=1;j--) {
			if (mn>a[j]) mn=a[j]; mx=max(mx,mn*(i-j+1));
		}
		ans=max(ans,mx+suf[i+1]);
	}
	for (int i=1;i<=n;i++) {
		while (tot&&a[st[tot]]>a[i]) tot--;
		if (tot) L[i]=st[tot]+1; else L[i]=1; st[++tot]=i;
	}
	tot=0;
	for (int i=n;i>=1;i--) {
		while (tot&&a[st[tot]]>=a[i]) tot--;
		if (tot) R[i]=st[tot]-1; else R[i]=n; st[++tot]=i;
	}
	for (int i=1;i<=n;i++) {
		int l=L[i],r=R[i];
		ll mn=a[i]; t1=t2=0;
		d[++t1]=MP(l,a[i]);
		for (int j=l;j>=1;j--) {
			if (mn>a[j]) mn=a[j],d[++t1]=MP(j,mn);
		}
		d[t1+1].first=0;
		D[t1+1]=0;
		for (int j=t1;j>=1;j--) {
			D[j]=max(D[j+1],d[j].second*(r-d[j+1].first));
		}
		e[++t2]=MP(r,a[i]);
		mn=a[i];
		for (int j=r;j<=n;j++) {
			if (mn>a[j]) mn=a[j],e[++t2]=MP(j,mn);
		}
		e[t2+1].first=n+1;
		E[t2+1]=0;
		for (int j=t2;j>=1;j--) {
			E[j]=max(E[j+1],e[j].second*(e[j+1].first-l));
		}
		int pos=1,p2=t2+1;
		for (int j=t1;j>=1;j--) {
			ll bd=a[i]-d[j].second,tmp=d[j].second*(r-d[j+1].first);
			while (pos<=t2&&e[pos].second>bd) pos++;
			while (p2>1&&e[p2-1].second<d[j].second) p2--;
			//if (l==2&&r==4&&j==t1) printf("?%d %lld p2=%d %d\n",pos,(r-l+1)*(a[i]-d[j].second),p2,(e[p2].first-d[j+1].first-1));
			if (pos<=t2) ans=max(ans,E[pos]+tmp);
			if (pos>1) ans=max(ans,bd*(e[pos].first-l)+tmp);
			ans=max(ans,(r-l+1)*(a[i]-d[j].second)+(e[p2].first-d[j+1].first-1)*d[j].second);
		}
		//2 2 3 5 4 5
		//printf("%d %d\n",l,r);
		//printf("%lld\n",ans);
		//for (int j=1;j<=t1;j++) printf("(%d,%lld)",d[j].first,d[j].second); puts("");
		//for (int j=1;j<=t2;j++) printf("(%d,%lld)",e[j].first,e[j].second); puts("");
		pos=1,p2=t1+1;
		for (int j=t2;j>=1;j--) {
			ll bd=a[i]-e[j].second,tmp=e[j].second*(e[j+1].first-l);
			while (pos<=t1&&d[pos].second>bd) pos++;
			while (p2>1&&d[p2-1].second<e[j].second) p2--;
			if (pos<=t1) ans=max(ans,D[pos]+tmp);
			if (pos>1) ans=max(ans,bd*(r-d[pos].first)+tmp);
			ans=max(ans,(r-l+1)*(a[i]-e[j].second)+(e[j+1].first-d[p2].first-1)*e[j].second);
			//if (l==6&&r==6) printf("?%d %lld %d\n",j,ans,p2);
		}
		//printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/