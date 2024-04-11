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

const ll INF = ll(1e18) + 123;

vll calc(int k, vll mult){
    vector<vector<pair<int, ll>>> adj(k);
    for(ll x : mult){
        ll d = x/k;
        for(int i = 0; i < k; i++){
            int to = (i+x)%k;
            adj[i].push_back({to, d+(to<i)});
        }
    }
    vll dist(k, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        pair<ll, int> p = pq.top();
        pq.pop();
        ll d;
        int idx;
        tie(d, idx) = p;
        if(dist[idx] != d) continue;
        for(auto pp : adj[idx]){
            if(dist[pp.first] > dist[idx] + pp.second){
                dist[pp.first] = dist[idx] + pp.second;
                pq.push({dist[idx] + pp.second, pp.first});
            }
        }
    }
    return dist;
}

void solve(){
    ll h;
    int n, q, k;
    cin >> h >> n >> q >> k;
    vll mult;
    vll pos(n);
    vi money(n);
    for(int i = 0; i < n; i++){
        cin >> pos[i];
        pos[i]--;
        cin >> money[i];
    }
    vll dist = calc(k, mult);
    vi taken(n);
    set<pii> poss;
    for(int i = 0; i < n; i++){
        if(!taken[i] && dist[pos[i]%k] <= pos[i]/k){
            poss.insert({money[i], -i});
        }
    }

    while(q--){
        debug(poss);
        int t;
        cin >> t;
        if(t == 1){
            ll x;
            cin >> x;
            mult.push_back(x);
            dist = calc(k, mult);
            poss.clear();
            for(int i = 0; i < n; i++){
                if(!taken[i] && dist[pos[i]%k] <= pos[i]/k){
                    poss.insert({money[i], -i});
                }
            }
        }else if(t == 2){
            int x, y;
            cin >> x >> y;
            x--;
            if(poss.find({money[x], -x}) != poss.end()){
                poss.erase({money[x], -x});
                poss.insert({money[x]-y, -x});
            }
            money[x] -= y;
        }else{
            if(poss.empty()){
                cout << 0 << endl;
            }else{
                cout << prev(poss.end())->first << endl;
                taken[-prev(poss.end())->second] = 1;
                poss.erase(prev(poss.end()));
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}