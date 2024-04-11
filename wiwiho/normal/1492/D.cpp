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
#define iceil(a, b) (((a) + (b) - 1) / (b))
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
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int a, b, k;
    cin >> a >> b >> k;

    if(k == 0){
        cout << "Yes\n";
        string ans;
        while(b--) ans += '1';
        while(a--) ans += '0';
        cout << ans << "\n";
        cout << ans << "\n";
        return 0;
    }
    if(a == 0 || b == 1){
        cout << "No\n";
        return 0;
    }
    if(b + a - 1 <= k){
        cout << "No\n";
        return 0;
    }

    string s1, s2;
    s1 += '1';
    s2 += '1';
    b--;

    s1 += '1';
    s2 += '0';
    b--; a--;
    while(k-- > 1){
        if(b){
            s1 += '1';
            s2 += '1';
            b--;
        }
        else{
            s1 += '0';
            s2 += '0';
            a--;
        }
    }
    s1 += '0';
    s2 += '1';
    while(b){
        s1 += '1';
        s2 += '1';
        b--;
    }
    while(a){
        s1 += '0';
        s2 += '0';
        a--;
    }

    cout << "Yes\n";
    cout << s1 << "\n" << s2 << "\n";

    return 0;
}