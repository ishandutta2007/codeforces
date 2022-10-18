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

    int T;
    cin >> T;

    while(T--){

        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = 0;
        int lst = -1;
        for(int i = 0; i < n; i++){
            if(s[i] == '0') continue;

            if(lst == -1){
                ans += iceil(max(0, i - k), k + 1);
                lst = i;
//                cerr << i << " " << i - k << "\n";
            }
            else{
                ans += iceil(max(0, i - lst - 1 - 2 * k), k + 1);
                lst = i;
//                cerr << i << " " << i - lst - 1 - 2 * k << "\n";
            }
        }

        if(lst != -1){
            ans += iceil(max(0, n - 1 - lst - k), k + 1);
//            cerr << n << " " << n - 1 - lst - k << "\n";
        }
        else{
            ans += iceil(n, k + 1);
//            cerr << n << " " << n << "\n";
        }

        cout << ans << "\n";

    }

    return 0;
}