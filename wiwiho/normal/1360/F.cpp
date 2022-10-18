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

    int T;
    cin >> T;
    while(T--){

        int n, m;
        cin >> n >> m;

        vector<string> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        vector<string> dp(1 << n, "-1");
        dp[0] = "";
        for(int i = 0; i < m; i++){
            vector<string> dp2(1 << n, "-1");
            for(char c = 'a' ; c <= 'z'; c++){
                int t = 0;
                for(int j = 0; j < n; j++){
                    if(c != a[j][i]) t |= (1 << j);
                }
                for(int j = 0; j < (1 << n); j++){
                    if(dp[j] == "-1") continue;
                    if(t & j) continue;
                    dp2[t | j] = dp[j] + c;
                }
            }
            dp = dp2;
        }

        for(string s : dp){
            if(s != "-1"){
                cout << s << "\n";
                goto nxt;
            }
        }
        cout << "-1\n";

        nxt:;
    }

    return 0;
}