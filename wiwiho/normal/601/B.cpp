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

    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) cin >> a[i];

    vector<int> d(n + 1);
    for(int i = 1; i < n; i++) d[i] = abs(a[i] - a[i + 1]);

    //printv(d, cerr);

    while(q--){
        int l, r;
        cin >> l >> r;

        vector<pii> t(n + 1);

        vector<int> st;

        for(int i = l; i < r; i++){
            while(!st.empty() && d[st.back()] < d[i]) st.pob;
            if(st.empty()) t[i].F = l - 1;
            else t[i].F = st.back();
            st.eb(i);
        }

        st.clear();

        for(int i = r - 1; i >= l; i--){
            while(!st.empty() && d[st.back()] <= d[i]) st.pob;
            if(st.empty()) t[i].S = r + 1;
            else t[i].S = st.back() + 1;
            st.eb(i);
        }

        //printv(t, cerr);

        ll ans = 0;
        for(int i = l; i < r; i++) ans += (ll) d[i] * (i - t[i].F) * (t[i].S - i - 1);

        cout << ans << "\n";

    }

    return 0;
}