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
const ll MAX = 100000000;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

void solve(){
    
    string s;
    cin >> s;

    int n = s.size();
    s = " " + s;

    vector<vector<int>> cnt(n + 1, vector<int>(10));
    vector<int> odd(n + 1);
    for(int i = 1; i <= n; i++){
        int now = s[i] - '0';
        cnt[i] = cnt[i - 1];
        odd[i] = odd[i - 1];
        if(cnt[i][now] % 2) odd[i]--;
        else odd[i]++;
        cnt[i][now]++;
    }

    //printv(odd, cerr);

    for(int i = n; i >= 1; i--){
        int now = s[i] - '0';

        for(int j = now - 1; j >= (i == 1); j--){
            
            vector<int> c = cnt[i - 1];
            int o = odd[i - 1];
            
            if(c[j] % 2) o--;
            else o++;
            c[j]++;
            
            if(o > n - i) continue;
            //printv(c, cerr);
            //cerr << o << "\n";
            
            s[i] = '0' + j;

            int k;
            for(k = n; o; k--){
                for(int t = 0; t <= 9; t++){
                    if(c[t] % 2 == 0) continue;
                    c[t]++;
                    o--;
                    s[k] = '0' + t;
                    break;
                }
            }
            for(; k > i; k--) s[k] = '9';

            cout << s.substr(1) << "\n";
            return;
        }

    }

    cout << string(n - 2, '9') << "\n";
    
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