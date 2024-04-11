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

struct Comp{
    bool operator()(pii a, pii b){
        return a.F == b.F ? a.S < b.S : a.F > b.F;
    }
};

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<pii> t;
    int lst = -1;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a != lst) t.eb(mp(0, a));
        t.back().F++;
        lst = a;
    }

    int cnt = t.size();
    vector<int> l(cnt, -1), r(cnt, -1);
    set<pii, Comp> st;
    for(int i = 0; i < cnt; i++){
        if(i) l[i] = i - 1;
        if(i != cnt - 1) r[i] = i + 1;
        st.insert(mp(t[i].F, i));
    }
//    printv(t, cerr);

    int ans = 0;
    while(!st.empty()){
        int id = st.begin()->S;
        st.erase(st.begin());
        ans++;

        if(l[id] != -1 && r[id] != -1 && t[l[id]].S == t[r[id]].S){
            st.erase(mp(t[l[id]].F, l[id]));
            st.erase(mp(t[r[id]].F, r[id]));
            t[l[id]].F += t[r[id]].F;
            r[l[id]] = r[r[id]];
            if(r[r[id]] != -1) l[r[r[id]]] = l[id];
            st.insert(mp(t[l[id]].F, l[id]));
        }
        else if(l[id] != -1 && r[id] != -1){
            r[l[id]] = r[id];
            l[r[id]] = l[id];
        }
        else if(l[id] != -1){
            r[l[id]] = r[id];
        }
        else if(r[id] != -1){
            l[r[id]] = l[id];
        }
//        cerr << id << "\n";
//        printv(t, cerr);
//        printv(l, cerr);
//        printv(r, cerr);
//        printv(st, cerr);
    }

    cout << ans << "\n";

    return 0;
}