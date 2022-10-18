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

    set<ll> h, w;
    map<pll, ll> c;
    ll all = 0;

    for(int i = 0; i < n; i++){
        ll wi, hi, ci;
        cin >> wi >> hi >> ci;
        w.insert(wi);
        h.insert(hi);
        c[mp(hi, wi)] = ci;
        all = __gcd(all, ci);
    }

    map<ll, ll> hg, wg;
    for(ll i : h){
        for(ll j : w){
            if(c[mp(i, j)] == 0){
                cout << "0\n";
                return 0;
            }
            wg[j] = __gcd(wg[j], c[mp(i, j)]);
            hg[i] = __gcd(hg[i], c[mp(i, j)]);
        }
    }

    for(ll i : h){
        for(ll j : w){
            ll tmp = __gcd(wg[j], c[mp(i, j)]);
            if(hg[i] % (c[mp(i, j)] / tmp)){
//                cerr << "test " << i << " " << j << " " << c[mp(i, j)] << "\n";
                cout << "0\n";
                return 0;
            }
        }
    }

    for(ll i : h){
        ll lst = -1;
        for(ll j : w){
            if(lst == -1){
                lst = c[mp(i,j)]/ wg[j];
            }
            else if(c[mp(i,j)] / wg[j] != lst){
                cout << "0\n";
                return 0;
            }
        }
    }

    ll cnt = 0;
    for(ll i = 1; i * i <= all; i++){
        if(all % i) continue;
        if(all / i == i) cnt++;
        else cnt += 2;
    }

    cout << cnt << "\n";

    return 0;
}