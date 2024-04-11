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
const double eps=1e-6;
const double pie=acos(-1.0);
const int maxn=3010;
int n,ans,tot;
ll R,x[maxn],y[maxn];
bool ok[maxn][maxn];
pair<ll,int> d[maxn*4],Q[maxn];
double query(double y,double x) {
	double res=atan2(y,x);
	if (res<0) res+=2*pie;
	return res;
}
ll F(double &x) { return (ll)(x*1e9); }
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(R);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	for (int i=1;i<=n;i++) {
		tot=0; int all=0;
		int pos=0,now=0;
		for (int k=1;k<=n;k++) {
			if (k!=i&&(x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k])>R*R) {
				all++;
				double theta=query(y[k]-y[i],x[k]-x[i]);
				double tmp=sqrt(((x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k])-R*R)*1.0);
				double alpha=query(R,tmp);
				double l=theta-alpha,r=theta+alpha;
				if (l<0) l+=2*pie; if (r>=2*pie) r-=2*pie;
				if (l<r) d[++tot]=MP(F(l),1),d[++tot]=MP(F(r),-1);
				else {
					now++,d[++tot]=MP(F(r),-1),d[++tot]=MP(F(l),1);
				}
			}
		}
		int cnt=0;
		for (int j=1;j<=n;j++) if (j!=i) {
			double res=atan2(y[j]-y[i],x[j]-x[i]);
			if (res<0) res+=2*pie;
			Q[++cnt]=MP(F(res),j);
		}
		sort(Q+1,Q+cnt+1); sort(d+1,d+tot+1);
		for (int j=1;j<=cnt;j++) {
			while (pos<tot&&d[pos+1].first<=Q[j].first) now+=d[pos+1].second,pos++;
			if (now==all) ok[i][Q[j].second]=1;//,printf("? %d %d\n",i,Q[j].second);
		}
	}
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) if (ok[i][j]&&ok[j][i]) ans++;
	printf("%d\n",ans);
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