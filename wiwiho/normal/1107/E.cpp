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

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<vector<ll>>> dp0(n, vector<vector<ll>>(n, vector<ll>(n + 1, -(1LL << 60))));
    vector<vector<vector<ll>>> dp1(n, vector<vector<ll>>(n, vector<ll>(n + 1, -(1LL << 60))));
    vector<vector<ll>> ans(n, vector<ll>(n));

    for(int i = 0; i < n; i++){
        dp0[i][i][0] = dp1[i][i][0] = ans[i][i] = a[1];
        if(s[i] == '1') dp1[i][i][1] = 0;
        else dp0[i][i][1] = 0;
    }

    for(int len = 1; len < n; len++){
        for(int i = 0; i + len < n; i++){
            int l = i, r = i + len;

            for(int m = l; m <= r; m++){
                if(s[m] != '0') continue;
                for(int c = 1; c <= r - l + 1; c++){
                    if(m - l < c - 1) continue;
                    ll tmp = 0;
                    if(m > l) tmp += dp0[l][m - 1][c - 1];
                    if(m < r) tmp += ans[m + 1][r];
                    dp0[l][r][c] = max(dp0[l][r][c], tmp);
                }
            }
            for(int m = l; m <= r; m++){
                if(s[m] != '1') continue;
                for(int c = 1; c <= r - l + 1; c++){
                    if(m - l < c - 1) continue;
                    ll tmp = 0;
                    if(m > l) tmp += dp1[l][m - 1][c - 1];
                    if(m < r) tmp += ans[m + 1][r];
//                    if(l == 0 && r == 2) cerr << m << " " << c << " " << tmp << "\n";
                    dp1[l][r][c] = max(dp1[l][r][c], tmp);
                }
            }
            for(int m = l; m < r; m++){
                ans[l][r] = max(ans[l][r], ans[l][m] + ans[m + 1][r]);
            }
            for(int c = 1; c <= r - l + 1; c++){
                ans[l][r] = max({ans[l][r], dp0[l][r][c] + a[c], dp1[l][r][c] + a[c]});
            }
            dp0[l][r][0] = dp1[l][r][0] = ans[l][r];

        }
    }

//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cerr << i << " " << j << "  ";
//            printv(dp0[i][j], cerr);
//        }
//    }
//    for(int i = 0; i < n; i++){
//        for(int j = 0; j < n; j++){
//            cerr << i << " " << j << "  ";
//            printv(dp1[i][j], cerr);
//        }
//    }

    cout << ans[0][n - 1] << "\n";

    return 0;
}