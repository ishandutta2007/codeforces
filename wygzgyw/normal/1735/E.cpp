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
const int maxn=2010;
int T,n;
ll d[maxn],e[maxn];
bool flag;
struct node {
	ll a; int b,c;
} D[maxn];
bool cmp(node A,node B) { return A.a<B.a; }
int tot,mat[2][maxn];
set<pair<ll,int> > s[2];
void solve(ll p) {
	if (flag) return;
	s[0].clear(),s[1].clear();
	for (int i=1;i<=n;i++) s[0].insert(MP(d[i],i)),s[1].insert(MP(e[i],i));
	for (int i=tot;i>=1;i--) {
		ll x=D[i].a; int op=D[i].c,id=D[i].b;
		if (!s[op].count(MP(x,id))) continue;
		ll y;
		if (x>p) y=x-p;
		else y=p-x;
		set<pair<ll,int> > :: iterator it=s[op^1].lower_bound(MP(y,0));
		if (it==s[op^1].end()||(*it).first!=y) return;
		int id2=(*it).second;
		mat[op][id]=id2,mat[op^1][id2]=id;
		s[op^1].erase(it),s[op].erase(MP(x,id));
	}
	puts("YES");
	vector<ll> vec;
	for (int i=1;i<=n;i++) {
		ll x=d[i],y=e[mat[0][i]];
		if (x+y==p) vec.push_back(x);
		else if (x-y==p) vec.push_back(x);
		else if (y-x==p) vec.push_back(-x);
		else assert(0);
	}
	ll mn=0;
	for (ll &x : vec) mn=min(mn,x);
	for (ll &x : vec) printf("%lld ",x-mn); puts("");
	printf("%lld %lld\n",-mn,p-mn);
	flag=1;
	return;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(d[i]);
		for (int i=1;i<=n;i++) read(e[i]);
		sort(d+1,d+n+1),sort(e+1,e+n+1),flag=0;
		tot=0; for (int i=1;i<=n;i++) D[++tot]=(node){d[i],i,0},D[++tot]=(node){e[i],i,1};
		sort(D+1,D+tot+1,cmp);
		for (int i=1;i<=n;i++) solve(d[1]+e[i]),solve(abs(d[1]-e[i]));
		if (!flag) puts("NO");
	}
	return 0;
}