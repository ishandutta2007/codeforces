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
ostream &operator<<(ostream &o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

template<typename T>
int gup(T& c, int b){
    auto it = upper_bound(iter(c), b);
    return it == c.end() ? MAX : *it;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        string s, t;
        cin >> s >> t;

        vector<vector<int>> pos(26);
        for(int i = 0; i < s.size(); i++){
            pos[s[i] - 'a'].eb(i);
        }

        int n = t.size();
        t = " " + t;

        bool ans = false;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, MAX));
        for(int i = 1; i <= n; i++){
            dp[0][i] = -1;

            for(int j = 1; j <= i; j++) dp[j][i] = gup(pos[t[j] - 'a'], dp[j - 1][i]);
            for(int j = i + 1; j <= n; j++) dp[0][j] = gup(pos[t[j] - 'a'], dp[0][j - 1]);

            for(int j = 1; j <= i; j++){
                for(int k = i + 1; k <= n; k++){
                    dp[j][k] = min(gup(pos[t[j] - 'a'], dp[j - 1][k]),
                                      gup(pos[t[k] - 'a'], dp[j][k - 1]));
                }
            }

            //cerr << "test " << i << "\n";
            //for(int j = 0; j <= i; j++) printv(dp[i][j], cerr);

            if(dp[i][n] < s.size()){
                ans = true;
                break;
            }
        }

        if(ans) cout << "YES\n";
        else cout << "NO\n";

    }

    return 0;
}