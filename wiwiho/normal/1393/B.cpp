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

    int n;
    cin >> n;
    vector<int> cnt(100001);
    multiset<int> st;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(cnt[a]) st.erase(st.find(cnt[a]));
        cnt[a]++;
        st.insert(cnt[a]);
    }

    int q;
    cin >> q;
    while(q--){
        char c;
        cin >> c;
        int x;
        cin >> x;
        if(cnt[x]) st.erase(st.find(cnt[x]));
        if(c == '+') cnt[x]++;
        else cnt[x]--;
        if(cnt[x]) st.insert(cnt[x]);

        if(st.empty()){
            cout << "NO\n";
            continue;
        }
        if(*st.rbegin() < 4){
            cout << "NO\n";
            continue;
        }
        if(*st.rbegin() >= 8){
            cout << "YES\n";
            continue;
        }
        if(st.size() >= 2 && *st.rbegin() >= 6 && *next(st.rbegin()) >= 2){
            cout << "YES\n";
            continue;
        }
        if(st.size() >= 2 && *next(st.rbegin()) >= 4){
            cout << "YES\n";
            continue;
        }
        if(st.size() >= 3 && *next(next(st.rbegin())) >= 2){
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }

    return 0;
}