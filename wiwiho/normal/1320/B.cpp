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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1), r(n + 1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        r[v].eb(u);
    }

    int k;
    cin >> k;

    vector<int> p(k);
    for(int i = 0; i < k; i++) cin >> p[i];

    int s = p[0], t = p[k - 1];

    vector<int> dis(n + 1, -1);
    queue<int> q;
    q.push(t);
    dis[t] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i : r[v]){
            if(dis[i] != -1) continue;
            dis[i] = dis[v] + 1;
            q.push(i);
        }
    }

    int lst = dis[s];
    int mn = 0, mx = 0;
//    printv(dis, cerr);

    for(int i = 1; i < k; i++){
//        cerr << p[i - 1] << " " << p[i] << " " << lst << " " << dis[i] << "\n";
        if(dis[p[i]] != lst - 1) mn++, mx++;
        else{
            for(int j : g[p[i - 1]]){
                if(j != p[i] && dis[j] == lst - 1){
                    mx++;
                    break;
                }
            }
        }
        lst = dis[p[i]];
    }

    cout << mn << " " << mx << "\n";

    return 0;
}