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
const int maxn=(1e6)+10;
int T;
int n,m,b[maxn];
ll a[maxn],ans;
ll sum[maxn],V[maxn];
int tot;
ll s[2][maxn];
ll S(int l,int r) {
	if (r%2==l%2) r--;
	if (l>=r) return 0;
	return s[l%2][r-1]-(l-2>=0?s[l%2][l-2]:0);
}
int main() {
	read(T);
	while (T--) {
		read(n),read(m);
		for (int i=1;i<=n;i++) read(a[i]);
		int g=0;
		for (int i=1;i<=m;i++) read(b[i]),g=__gcd(g,b[i]);
		if (g==1) { ans=0; for (int i=1;i<=n;i++) ans+=abs(a[i]); }
		else {
			for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
			ans=sum[n];
			for (int i=g;i<=n;i++) {
				ll tmp=sum[i]-sum[i-g];
				ans=max(ans,sum[n]-tmp*2);
			}
			ll now=0,N=0,mx=0;
			for (int i=1;i<=g;i++) {
				tot=0;
				for (int j=i;j<=n;j+=g) {
					V[++tot]=a[j];
				}
				sort(V+1,V+tot+1); V[0]=V[tot+1]=1e10;
				for (int st=1;st<=2&&st<=tot;st++) {
					for (int j=st;j<tot;j+=2)
						s[st&1][j]=(j==1?0:s[st&1][j-2])+2*max(0LL,-V[j]-V[j+1]);
				}
					//printf("> %lld\n",s[1][3]);
				ll nn=0;
				for (int j=1;j<tot;j+=2) if (-V[j]-V[j+1]>0) nn-=(V[j]+V[j+1])*2;
				now+=nn; mx=-1e18;
			//	for (int j=1;j<=tot;j++) printf("%lld ",V[j]); puts("");
				for (int j=1;j<=tot;j++) {
					int x=lower_bound(V+1,V+tot+1,-V[j])-V;
					ll tmp=-2*V[j];
					//printf("x=%d\n",x);
					V[j]*=-1;
					if (x!=j&&x!=j+1) {
						if (j<x) {
							int r=j-1,l=j+1;
							if (r%2==1) r--;
							tmp+=S(1,r); if (r!=j-1&&j+1<=tot) tmp+=2*max(0LL,-V[j-1]-V[j+1]),l++;
							r=x-1;
							if (r%2==l%2) r--;
							tmp+=S(l,r);
							l=x;
							//printf("%lld %lld\n",V[j],V[x]);
							if (r==x-1) tmp+=2*max(0LL,-V[j]-V[x]),l=x+1;
							else tmp+=2*max(0LL,-V[j]-V[r]),l=x;
							tmp+=S(l,tot);
						} else {
							int r=x-1,l;
							if (r%2==1) r--;
							tmp+=S(1,r);
							if (r==x-1) tmp+=2*max(0LL,-V[j]-V[x]),l=x+1;
							else tmp+=2*max(0LL,-V[j]-V[x-1]),l=x;
							r=j-1;
							if (r%2==l%2) r--;
							tmp+=S(l,r);
							if (r==j-1) l=j+1; else tmp+=2*max(0LL,-V[j-1]-V[j+1]),l=j-1;
							tmp+=S(l,tot);
						}
					}
					V[j]*=-1;
				//	printf("%d %lld %lld\n",j,V[j],tmp);
					//if (V[j]==5) exit(0);
					mx=max(mx,tmp);
				}
				N+=mx;
				//printf("mx=%lld %lld\n",mx,nn);
			}
			ans=max(ans,sum[n]+now);
			ans=max(ans,sum[n]+N);
		}
		printf("%lld\n",ans);
	}
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