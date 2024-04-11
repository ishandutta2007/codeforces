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
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

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

void solve(){
    int n, m;
    cin >> n >> m;

    vector<string> g(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> g[i];
        g[i] = ' '+ g[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            if(g[i][j] != g[j][i]) continue;
            vector<int> v ={i, j};
            cout << "YES\n";
            for(int k = 0; k <= m; k++){
                cout << v[k % 2] << " ";
            }
            cout << "\n";
            return;
        }
    }

    if(m % 2){
        vector<int> v = {1, 2};
        cout << "YES\n";
        for(int j = 0; j <= m; j++){
            cout << v[j % 2] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        int a = -1, b = -1;
        for(int j = 1; j <= n; j++){
            if(i == j) continue;
            if(g[i][j] == 'a') a = j;
            else b = j;
        }
        if(a == -1 || b == -1) continue;
        cout << "YES\n";
        if(m % 4) cout << a << " ";
        cout << i << " ";
        for(int j = 0; j < m / 4; j++) cout << a << " " << i << " ";
        for(int j = 0; j < m / 4; j++) cout << b << " " << i << " ";
        if(m % 4) cout << b << " ";
        cout << "\n";
        return;
    }

    cout << "NO\n";
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}