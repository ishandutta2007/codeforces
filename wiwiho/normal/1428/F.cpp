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
#define topos(a) (((a) % MOD + MOD) % MOD)
#define uni(a) a.resize(unique(iter(a)) - a.begin())
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

    multiset<pll> st;
    ll now = 0;

    ll ans = 0;
    ll tmp = 0;
    for(int i = 0; i < n ;i++){
        if(s[i] == '0'){
            for(int j = 1; j <= now; j++) st.insert(mp(j, 1));
            tmp += (now + 1) * now / 2;
            now = 0;
            st.insert(mp(0, 1));
        }
        else{
            now++;
            ll cnt = 0;
            while(!st.empty() && st.begin()->F <= now){
                cnt += st.begin()->S;
                tmp -= st.begin()->F * st.begin()->S;
                st.erase(st.begin());
            }
            if(cnt) st.insert(mp(now, cnt));
            tmp += now * cnt;
        }
//        cerr << "test " << i << "\n";
//        printv(st, cerr);
//        cerr << now << "\n";
        ans += tmp + (now + 1) * now / 2;
    }

    cout << ans << "\n";

    return 0;
}