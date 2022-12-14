#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//ll rnd(ll l,ll r){return uniform_int_distribution<ll>(l,r)(rng);}
template<class T>void Min(T &a,const T b){if(a>b)a=b;}
template<class T>void Max(T &a,const T b){if(a<b)a=b;}
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
//#define endl '\n'
#ifdef ONLINE_JUDGE
#define freopen(a,b,c)
#define K(a...)
#endif
typedef pair<int,int>pii;
typedef pair<ll,ll>pll;
typedef vector<int>vi;
typedef vector<ll>vl;
const ll linf=0x3f3f3f3f3f3f3f3f;
const int inf=0x3f3f3f3f;
const int N=5000+10;
const ll mod=1e9+7;
template <class Cap, class Cost>struct zkwflow {
	struct E { int v,re; Cap f; Cost w; };
	int n, s, t;
	vector<int>cur;vector<bool>vis;vector<Cost>dis;
	vector<vector<E>>e;

	zkwflow(int _n, int _s, int _t):n(_n),s(_s),t(_t) {e.assign(n,{});}
	void add_edg(int u, int v, Cap f, Cost w) {
        assert(u>=0&&u<n&&v>=0&&v<n);
		e[u].push_back({v,(int)e[v].size(), f, w});
		e[v].push_back({u,(int)e[u].size()-1, 0, -w});
	}
	bool augment() {
		dis.assign(n,numeric_limits<Cost>::max());
		vis.assign(n,false);
		dis[s] = 0;
		deque<int> dq = {s};
		while (!dq.empty()) {
			int u = dq.front(); dq.pop_front();
			vis[u] = false;
			for (auto &it : e[u]) {
				if (it.f > 0 && dis[it.v] > dis[u] + it.w) {
					dis[it.v] = dis[u] + it.w;
					if (!vis[it.v]) {
						vis[it.v] = true;
						if (dq.size() && dis[it.v] < dis[dq.front()])
                            dq.push_front(it.v);
						else dq.push_back(it.v);
					}
				}
			}
		}
		return dis[t] != numeric_limits<Cost>::max();
	}
	Cap DFS(int u, Cap nf) {
		if (u == t) return nf;
		vis[u] = true;
		Cap ret = 0;
		for (int &i = cur[u]; i < e[u].size(); i++) {
			auto &it = e[u][i];
			if (it.f > 0 && dis[it.v] == dis[u] + it.w && !vis[it.v]) {
				Cap tf = DFS(it.v, min(nf, it.f));
				ret += tf, nf -= tf, it.f -= tf;
				e[it.v][it.re].f += tf;
				if (nf == 0) {vis[u] = false;break;}
			}
		}
		return ret;
	}
	pair<Cap, Cost> solve() {
		Cap flow = 0; Cost cost = 0;
		while (augment()) {
            cur.assign(n,0);
			Cap d = DFS(s, numeric_limits<Cap>::max());
			flow += d; cost += dis[t] * d;
		}
		return {flow, cost};
	}
};
mt19937 rnd(time(0));
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("A.in","r",stdin);
    int n,k;cin>>n>>k;
    Min(k,1<<n-1);
    vi ar(1<<n);for(auto &i:ar)cin>>i;

    vector<bool>vis(1<<n);
    for(int i=0;i<n;i++){
        vi rk(1<<n);iota(rk.begin(),rk.end(),0);
        nth_element(rk.begin(),rk.begin()+2*k,rk.end(),[&](int a,int b){
            return ar[a]+ar[a^1<<i]>ar[b]+ar[b^1<<i];
        });
        for(int j=0;j<2*k;j++){
            vis[rk[j]]=1;
        }
    }
    int cnt=0;
    vi id(1<<n);
    for(int i=0;i<1<<n;i++)if(vis[i]){
        id[i]=cnt++;
    }
    zkwflow<int,int>sw(cnt+3,cnt+1,cnt+2);
    sw.add_edg(sw.s,cnt,k,0);
    for(int i=0;i<1<<n;i++)if(vis[i]){
        if(__builtin_popcount(i)&1)sw.add_edg(cnt,id[i],1,-ar[i]);
        else sw.add_edg(id[i],sw.t,1,-ar[i]);
    }
    for(int i=0;i<1<<n;i++)if(__builtin_popcount(i)&1&&vis[i]){
        for(int t=0;t<n;t++){
            int j=i^1<<t;
            if(vis[j])sw.add_edg(id[i],id[j],1,0);
        }
    }
    cout<<-sw.solve().se;
}