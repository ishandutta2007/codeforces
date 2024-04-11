#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(8e5)+10;
int n,now;
map<pair<ll,ll>,int> M;
ll gcd(ll x,ll y) {
	if (!x||!y) return x+y;
	return gcd(y,x%y);
}
int insert(ll x,ll y) {
	ll g=gcd(x,y); x/=g,y/=g;
	//printf("(%lld,%lld)\n",x,y);
	if (M.find(make_pair(x,y))!=M.end()) return M[make_pair(x,y)];
	M[make_pair(x,y)]=++now; return now;
}
vector<pair<int,int> > ans;
int vis[maxn],used[maxn];
int head[maxn],nxt[maxn],to[maxn],tot;
void add(int x,int y) {
	tot++; nxt[tot]=head[x]; head[x]=tot; to[tot]=y; used[tot]=0;
}

void dfs(int u,int p,int ID) {
	int lst=0,id=0; vis[u]=1;
	for (int i=head[u],v;i;i=nxt[i]) {
		v=to[i];
		if (used[i]||v==p) continue;
		if (!vis[v]) dfs(v,u,i);
		if (used[i]) continue;
		if (lst) {
			used[i]=used[i^1]=used[id]=used[id^1]=1;
			ans.push_back(make_pair(i/2,id/2));
			lst=0;
		} else lst=v,id=i;
	}
	if (lst&&p) {
		ans.push_back(make_pair(id/2,ID/2));
		used[id]=used[id^1]=used[ID]=used[ID^1]=1;
	}
}
ll a,b,c,d;
int x,y;
int main() {
//	freopen("1.txt","r",stdin);
	read(n); tot=1;
	for (int i=1;i<=n;i++) {
		read(a),read(b),read(c),read(d);
		x=insert(d*(a+b),b*c);
		y=insert(a*d,(c+d)*b);
		add(x,y),add(y,x);
		//printf("%d %d\n",x,y);
	}
	for (int i=1;i<=now;i++) if (!vis[i]) dfs(i,0,0);
	printf("%d\n",(int)ans.size());
	for (pair<int,int> A : ans) printf("%d %d\n",A.first,A.second);
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