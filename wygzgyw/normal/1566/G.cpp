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
const int maxn=(1e5)+10;
int n,m;
set<pair<int,int> > w[maxn];
set<pair<int,pair<int,int> > > edges,edges2;
map<pair<int,int>,int> M;
multiset<ll> ans1;
ll ans;
vector<pair<int,int> > g[maxn],h[maxn];
void update(int x) {
	ll sum=0;
	for (auto [w,y] : g[x]) sum+=w;
	if ((int)g[x].size()>=3) ans1.erase(ans1.find(sum));
	g[x].clear(); sum=0;
	set<pair<int,int> > :: iterator it=w[x].begin();
	while ((int)g[x].size()<3&&it!=w[x].end()) {
		int y=(*it).second;
		g[x].push_back(*it),sum+=(*it).first,it++;
	}
	if ((int)g[x].size()>=3) ans1.insert(sum);
	
}
void update2(int x) {	
	for (auto [w,y] : h[x]) {
		pair<int,pair<int,int> > A=MP(w,MP(min(x,y),max(x,y)));
		//if (x==55&&y==3) printf("HI %d %d\n",edges2.count(A),w);
		if (edges2.count(A)) edges2.erase(A);
	}
	h[x].clear();
	for (auto [w,y] : g[x]) {
		bool flag=0;
		for (auto [w2,x2] : g[y]) if (x2==x) { flag=1; break; }
		if (flag) {
			edges2.insert(MP(w,MP(min(x,y),max(x,y)))),h[x].push_back(MP(w,y));
		//	if (x==3) printf("> %d %d\n",y,w);
		}
	}
}
void add(int x,int y,int z) {
	if (x>y) swap(x,y);
	w[x].insert(MP(z,y)),w[y].insert(MP(z,x));
	edges.insert(MP(z,MP(x,y)));
	update(x),update(y);
	update2(x),update2(y);
	M[MP(x,y)]=z;
}
void del(int x,int y) {
	if (x>y) swap(x,y);
	int z=M[MP(x,y)]; M[MP(x,y)]=0;
	w[x].erase(MP(z,y)),w[y].erase(MP(z,x));
	edges.erase(MP(z,MP(x,y)));
	update(x),update(y);
	update2(x),update2(y);
}
void chkmin(ll &x,ll y) { if (x>y) x=y; }
void solve() {
	if ((int)ans1.size()>0) ans=*ans1.begin();
	else ans=INF;
	pair<int,pair<int,int> > A=*edges.begin();
	//for (auto B : edges) printf("%d %d\n",B.second.first,B.second.second);
	int x=A.second.first,y=A.second.second,z=A.first;
	for (auto [w1,a] : g[x]) for (auto [w2,b] : g[y])
		if (a!=y&&b!=x&&a!=b) chkmin(ans,w1+w2);
	//printf("z=%d %d %d %lld\n",z,x,y,ans);
	vector<pair<int,pair<int,int> > > bad;
	bad.push_back(MP(z,MP(x,y)));
	for (auto [w,a] : h[x]) bad.push_back(MP(w,MP(min(a,x),max(a,x))));
	for (auto [w,b] : h[y]) bad.push_back(MP(w,MP(min(b,y),max(b,y))));
	
	//for (auto A : g[55]) printf("?? %d\n",A.second);
	//for (auto A : edges2) printf("?? %d %d\n",A.second.first,A.second.second);
	
	for (auto A : bad) if (edges2.count(A)) edges2.erase(A); //else puts("?");
	
	//for (auto A : bad) printf("%d %d\n",A.second.first,A.second.second);
	
	if ((int)edges2.size()>0) {
		chkmin(ans,z+(*edges2.begin()).first);
	//	printf("?? %d %d\n",(*edges.begin()).second.first,(*edges.begin()).second.second);
	}
	for (auto A : bad) edges2.insert(A);
	printf("%lld\n",ans);
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(m);
	int x,y,z;
	for (int i=1;i<=m;i++) {
		read(x),read(y),read(z);
//	printf("x=%d,y=%d\n",x,y);
		add(x,y,z);
	}
	solve();
	int q; read(q);
	while (q--) {
		int op; read(op);
		read(x),read(y);
		if (op==1) read(z),add(x,y,z);
		else del(x,y);
		solve();
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