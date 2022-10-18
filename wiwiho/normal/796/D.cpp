//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}


int main(){
    StarBurstStream

    int n, k, d;
    cin >> n >> k >> d;

    queue<int> q;
    vector<int> dis(n + 1, -1);
    for(int i = 0; i < k; i++){
        int p;
        cin >> p;
        dis[p] = 0;
        q.push(p);
    }

    vector<vector<int>> g(n + 1);
    map<pii, int> id;
    for(int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
        id[mp(u, v)] = i + 1;
        id[mp(v, u)] = i + 1;
    }

    set<int> ans;

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i : g[v]){
            if(dis[i] != -1) continue;
            dis[i] = dis[v] + 1;
            q.push(i);
        }
    }

    //printv(dis, cerr);
    for(int v = 1; v <= n; v++){
        bool r = false;
        for(int i : g[v]){
            if(dis[i] == dis[v]) ans.insert(id[mp(i, v)]);
            else if(dis[i] < dis[v]){
                if(!r) r = true;
                else ans.insert(id[mp(i, v)]);
            }
        }
    }

    cout << ans.size() << "\n";
    printv(ans, cout);

    return 0;
}