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

        ll n, x, y;
        cin >> n >> x >> y;

        ll ans = MAX;
        ll ansp = -1;

        for(int i = 1; i <= y - x; i++){
            if((y - x) % i) continue;

            int cnt = 0;
            for(ll j = y; j > 0; j -= i){
                cnt++;
            }

            ll t;
            if(cnt >= n){
                t = y;
                cnt = n;
            }
            else{
                t = y + i * (n - cnt);
            }
            ll f = y - (cnt - 1) * i;
            if(f > x) continue;

            if(t < ans){
                ans = t;
                ansp = i;
            }

        }

        int cnt = 0;
        vector<int> a;
        for(ll j = y; j > 0; j -= ansp){
            a.eb(j);
        }
        if(a.size() >= n){
            a.resize(n);
        }
        reverse(iter(a));
        while(a.size() < n) a.eb(a.back() + ansp);

        printv(a, cout);

    }

    return 0;
}