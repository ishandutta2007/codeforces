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

    deque<pll> dq;
    stack<int> st;
    vector<int> ans(n);
    int ts = 0;
    for(int i = 0; i < 2 * n; i++){
        string s;
        cin >> s;

        if(s == "+"){
            if(!dq.empty() && dq.back().F == 0) dq.back().S++;
            else dq.eb(mp(0, 1));
            st.push(ts++);
            continue;
        }

        ll c;
        cin >> c;

        ll cnt = 0;
        while(!dq.empty() && dq.back().F <= c){
            cnt += dq.back().S;
            dq.pob;
        }
        if(cnt == 0){
            cout << "NO\n";
            return 0;
        }
        cnt--;
        ans[st.top()] = c;
//        cerr << st.top() << " " << c << "\n";
        st.pop();
        if(cnt) dq.eb(mp(c, cnt));
    }

    cout << "YES\n";
    printv(ans, cout);

    return 0;
}