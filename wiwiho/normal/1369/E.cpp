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
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
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

    int n, m;
    cin >> n >> m;

    vector<vector<pii>> g(n + 1);
    vector<int> s(n + 1);
    vector<int> w(n + 1);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(mp(v, i));
        g[v].eb(mp(u, i));
        s[u]++;
        s[v]++;
    }

    vector<bool> d(n + 1), c(n + 1);
    vector<int> ans;
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(s[i] <= w[i]){
            q.push(i);
            d[i] = true;
        }
    }

    while(!q.empty()){
        int now = q.front();
        q.pop();
        c[now] = true;
        for(pii i : g[now]){
            if(c[i.F]) continue;
            ans.eb(i.S);
            s[i.F]--;
            if(!d[i.F] && s[i.F] <= w[i.F]){
                q.push(i.F);
                d[i.F] = true;
            }
        }
    }

    for(int i = 1; i <= n; i++){
        if(!d[i]){
            cout << "DEAD\n";
            return 0;
        }
    }
    reverse(iter(ans));

    cout << "ALIVE\n";
    printv(ans, cout);

    return 0;
}