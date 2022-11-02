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
const int maxn=(2e5)+10;
const double eps=1e-7;
const double PIE=acos(-1.0);
int n;
ll m;
double X[maxn],Y[maxn];
double rem[maxn];
int tot;
pair<double,int> d[maxn];
pair<int,int> inter[maxn];
int tr[maxn];
void add(int x,int delta) { for (;x<maxn;x+=x&(-x)) tr[x]+=delta; }
int query(int x) { int res=0; for (;x;x-=x&(-x)) res+=tr[x]; return res; }
ll solve(double mid) {
	ll ans=0; tot=0;
	for (int i=1;i<=n;i++) {
		double dis=sqrt(X[i]*X[i]+Y[i]*Y[i]);
		if (dis<=mid) continue;
		double alpha=rem[i];
		if (alpha<0) alpha+=2*PIE;
		double theta=acos(mid/dis);
		double l=alpha-theta,r=alpha+theta;
		if (l<0) l+=2*PIE;
		if (r>2*PIE) r-=2*PIE;
		if (l>r) swap(l,r);
		d[++tot]=MP(l,-i),d[++tot]=MP(r,i);
	}
	if (tot) {
		//printf("%d %.5lf\n",tot,mid);
		for (int i=1;i<=n;i++) inter[i]=MP(1,0);
		sort(d+1,d+tot+1);
		for (int i=1;i<=tot;i++) {
			if (d[i].second<0) inter[-d[i].second].first=i;
			else inter[d[i].second].second=i;
		}
		tot=0;
		for (int i=1;i<=n;i++) if (inter[i].first<=inter[i].second) inter[++tot]=inter[i];
		sort(inter+1,inter+tot+1);
		memset(tr,0,sizeof(tr));
		for (int i=tot;i>=1;i--) {
		//	printf("%d %d\n",inter[i].first,inter[i].second);
			ans+=query(inter[i].second);
			add(inter[i].first,1),add(inter[i].second,-1);
		}
	}
	return (ll)n*(n-1)/2-ans;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(X[i]),read(Y[i]),rem[i]=atan2(Y[i],X[i]);
	double l=0,r=1e5,mid;
	for (int i=1;i<=50;i++) {
		mid=(l+r)*0.5;
		if (solve(mid)>=m) r=mid;
		else l=mid;
	}
	printf("%.8lf\n",(l+r)*0.5);
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