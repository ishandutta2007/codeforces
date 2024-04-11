//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> h(n);
    map<int, vector<int>> pos;
    for(int i = 0; i < n; i++) cin >> h[i], pos[h[i]].eb(i);

    vector<vector<int>> g(n);

    set<int> now;
    for(auto& i : pos){
        for(int j : i.S) now.insert(j);
        for(int j : i.S){
            auto it = now.lower_bound(j);
            if(next(it) != now.end()){
                int nxt = *next(it);
                g[j].eb(nxt);
            }
            if(it != now.begin()){
                int prv = *prev(it);
                g[prv].eb(j);
            }
        }
    }

    now.clear();
    for(auto tt = pos.rbegin(); tt != pos.rend(); tt++){
        auto& i = *tt;
        for(int j : i.S) now.insert(j);
        for(int j : i.S){
            auto it = now.lower_bound(j);
            if(next(it) != now.end()){
                int nxt = *next(it);
                g[j].eb(nxt);
            }
            if(it != now.begin()){
                int prv = *prev(it);
                g[prv].eb(j);
            }
        }
    }

    vector<int> dis(n, -1);
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty()){
        int v = q.front();
        int d = dis[v];
        q.pop();
        for(int i : g[v]){
            if(dis[i] != -1) continue;
            dis[i] = d + 1;
            q.push(i);
        }
    }

    cout << dis[n - 1] << "\n";

    return 0;
}