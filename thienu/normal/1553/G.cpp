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

const int N = 1e6 + 2;
vi pr, lp(N);

vi factorize(int n){
    vi ans;
    int last = -1;
    while(n > 1){
        if(lp[n] != last) ans.push_back(lp[n]);
        last = lp[n];
        n /= lp[n];
    }
    return ans;
}

void solve(){
    for(int i = 2; i < N; i++){
        if(lp[i] == 0){
            lp[i] = i;
            pr.push_back(i);
        }
        for(int j = 0; j < pr.size() && i*pr[j] < N && pr[j] <= lp[i]; j++){
            lp[i*pr[j]] = pr[j];
        }
    }
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    vvi adj(N);
    for(int i = 0; i < n; i++){
        vi f = factorize(v[i]);
        for(int j : f){
            if(v[i] != j){
                adj[v[i]].push_back(j);
                adj[j].push_back(v[i]);
            }
        }
    }
    vi comp(N, -1);
    int ccnt = 0;
    queue<int> qu;
    for(int i = 0; i < N; i++){
        if(comp[i] == -1){
            qu.push(i);
            comp[i] = ccnt;
            while(!qu.empty()){
                int u = qu.front();
                qu.pop();
                for(int v : adj[u]){
                    if(comp[v] != -1) continue;
                    comp[v] = ccnt;
                    qu.push(v);
                }
            }
            ccnt++;
        }
    }
    debug(comp[2], comp[10], comp[3]);
    
    vector<set<int>> eadj(ccnt);
    for(int i = 0; i < n; i++){
        set<int> clique;
        vi f = factorize(v[i]+1);
        clique.insert(comp[v[i]]);
        for(int i : f){
            clique.insert(comp[i]);
        }
        for(int i : clique){
            for(int j : clique){
                if(i == j) continue;
                eadj[i].insert(j);
            }
        }
    }

    while(q--){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if(comp[v[x]] == comp[v[y]]){
            cout << 0 << endl;
        }else if(eadj[comp[v[x]]].find(comp[v[y]]) != eadj[comp[v[x]]].end()){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}