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
#define tlll tuple<ll, ll, ll>
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

pll ft(ll n){
    ll now = 0;
    for(int i = 1; ; i++){
        now += (1LL << (2 * i));
        if(n <= now) return mp(i, now - (1LL << (2 * i)) + 1);
    }
}

ll fb(ll x, ll b, ll now){
    if(now == 0){
        return 2 * b;
    }

    ll B = fb(x / 4, b, now / 4);
    if(x % 4 == 1) B += 2 * (b / now);
    else if(x % 4 == 2) B += 3 * (b / now);
    else if(x % 4 == 3) B += 1 * (b / now);

    return B;
}

ll fc(ll x, ll b, ll now){
    if(now == 0){
        return 3 * b;
    }

    ll C = fc(x / 4, b, now / 4);
    if(x % 4 == 1) C += 3 * (b / now);
    else if(x % 4 == 2) C += 1 * (b / now);
    else if(x % 4 == 3) C += 2 * (b / now);

    return C;
}

int main(){
    StarBurstStream

    int T;
    cin >> T;

    while(T--){

        ll n;
        cin >> n;

        if(n <= 3){
            cout << n << "\n";
            continue;
        }
        ll m = n;
        n -= 3;
        n = iceil(n, 3);

        pll tmp = ft(n);
        ll b = tmp.F;
        ll st = tmp.S;

        ll A = (1LL << (2 * b)) + n - st;
        ll B = fb(n - st, (1LL << (2 * b)), (1LL << (2 * b))), C = fc(n - st, (1LL << (2 * b)), (1LL << (2 * b)));

        if(m % 3 == 1) cout << A << "\n";
        else if(m % 3 == 2) cout << B << "\n";
        else cout << C << "\n";

    }

    return 0;
}