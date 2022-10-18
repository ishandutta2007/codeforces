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
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

multiset<ll> ans;

void add(ll a, set<ll>& st){
    if(st.empty()){
        st.insert(a);
        return;
    }
    auto it1 = st.lower_bound(a);
    if(it1 == st.begin()){
        ans.insert(*it1 - a);
        st.insert(a);
        return;
    }
    auto it2 = prev(it1);
    if(it1 == st.end()){
        ans.insert(a - *it2);
        st.insert(a);
        return;
    }
    ans.erase(ans.find(*it1 - *it2));
    ans.insert(*it1 - a);
    ans.insert(a - *it2);
    st.insert(a);
}

void del(ll a, set<ll>& st){
    if(st.size() == 1){
        st.clear();
        return;
    }
    auto it = st.lower_bound(a);
    auto it1 = st.upper_bound(a);
    if(it == st.begin()){
        ans.erase(ans.find(*it1 - a));
        st.erase(a);
        return;
    }
    auto it2 = prev(it);
    if(it1 == st.end()){
        ans.erase(ans.find(a - *it2));
        st.erase(a);
        return;
    }
    ans.erase(ans.find(a - *it2));
    ans.erase(ans.find(*it1 - a));
    ans.insert(*it1 - *it2);
    st.erase(a);
}

ll solve(set<ll>& st){
    if(st.size() <= 2) return 0;
    return *st.rbegin() - *st.begin() - *ans.rbegin();
}

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;

    set<ll> st;
    for(int i = 0; i < n; i++){
        int p;
        cin >> p;
        add(p, st);
    }

    cout << solve(st) << "\n";

    while(q--){
        int t, x;
        cin >> t >> x;
        if(t == 0) del(x, st);
        else add(x, st);
        cout << solve(st) << "\n";
    }

    return 0;
}