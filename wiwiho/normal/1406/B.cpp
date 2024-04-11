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
const ll MAX = 1LL << 60;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;

        vector<ll> mx(6, -MAX), mn(6,  MAX);
        mx[0] = mn[0] = 1;

        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;

            vector<ll> mx2 = mx, mn2 = mn;
            for(int j = 1; j <= 5; j++){
                if(mx[j - 1] == -MAX) continue;
                mx2[j] = max(mx2[j], mx[j - 1] * a);
                mn2[j] = min(mn2[j], mx[j - 1] * a);
            }
            for(int j = 1; j <= 5; j++){
                if(mn[j - 1] == MAX) continue;
                mx2[j] = max(mx2[j], mn[j - 1] * a);
                mn2[j] = min(mn2[j], mn[j - 1] * a);
            }

            mx = mx2;
            mn = mn2;

//            printv(mx, cerr);
//            printv(mn, cerr);

        }

        cout << mx[5] << "\n";
    }



    return 0;
}