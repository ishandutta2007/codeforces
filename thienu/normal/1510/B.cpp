#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

// kactl, khun's algorithm
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
bool find(int j, vector<vi>& g, vi& btoa, vi& vis) {
	if (btoa[j] == -1) return 1;
	vis[j] = 1; int di = btoa[j];
	for (int e : g[di])
		if (!vis[e] && find(e, g, btoa, vis)) {
			btoa[e] = di;
			return 1;
		}
	return 0;
}
int dfsMatching(vector<vi>& g, vi& btoa) {
	vi vis;
	rep(i,0,sz(g)) {
		vis.assign(sz(btoa), 0);
		for (int j : g[i])
			if (find(j, g, btoa, vis)) {
				btoa[j] = i;
				break;
			}
	}
	return sz(btoa) - (int)count(all(btoa), -1);
}

int at(int x, int pos){
    return (x >> pos) & 1;
}

void solve(){
    int d, n;
    cin >> d >> n;
    vi targets(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < d; j++){
            targets[i] <<= 1;
            targets[i] += (s[j] - '0');
        }
    }
    debug(targets);
    sort(targets.begin(), targets.end(), [&](int a, int b){return __builtin_popcount(a) > __builtin_popcount(b);});
    debug(targets);
    vvi adj(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            // i -> j iff i is a subset of j
            if((targets[i] | targets[j]) == targets[j]){
                adj[i].push_back(j);
            }
        }
    }
    debug(adj);

    vi btoa(n, -1);
    dfsMatching(adj, btoa);
    debug(btoa);

    vi atob(n, -1);
    for(int i = 0; i < n; i++){
        if(btoa[i] != -1){
            atob[btoa[i]] = i;
        }
    }
    debug(atob);

    vvi ans;
    for(int i = 0; i < n; i++){
        if(btoa[i] != -1) continue;
        int num = 0;
        int cur = i;
        vi seq;
        while(cur != -1){
            // change num to targets[cur]
            for(int j = 0; j < d; j++){
                if(at(targets[cur], j) == 1 && at(num, j) == 0){
                    seq.push_back(j);
                    num |= (1 << j);
                }
            }
            cur = atob[cur];
        }
        ans.push_back(seq);
    }
    debug(ans);

    int ops = 0;
    for(vi &v : ans){
        ops += v.size();
        ops++;
    }
    cout << --ops << endl;
    for(int i = 0; i < ans.size(); i++){
        for(int j : ans[i]){
            cout << d-1-j << ' ';
        }
        if(i + 1 != ans.size()){
            cout << "R ";
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}