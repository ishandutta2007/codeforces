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

    vector<string> a(n);
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n / 4; j++){
            char t = s[j];
            if('0' <= t && t <= '9') a[i] += bitset<4>(t - '0').to_string();
            else a[i] += bitset<4>(t - 'A' + 10).to_string();
        }
    }
//    for(int i = 0; i < n; i++) cerr << a[i] << "\n";

    int ans = n;

    for(int i = 0; i < n; i++){
        int now = 1;
        for(int j = 1; j < n; j++){
            if(a[i][j] != a[i][j - 1]){
                ans = __gcd(ans, now);
                now = 1;
            }
            else now++;
        }
        ans = __gcd(ans, now);
    }

    for(int i = 0; i < n; i++){
        int now = 1;
        for(int j = 1; j < n; j++){
            if(a[j][i] != a[j - 1][i]){
                ans = __gcd(ans, now);
                now = 1;
            }
            else now++;
        }
        ans = __gcd(ans, now);
    }

    cout << ans << "\n";

    return 0;
}