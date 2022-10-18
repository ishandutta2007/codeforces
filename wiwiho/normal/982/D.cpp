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

    vector<int> a(n);
    map<int, vector<int>, greater<>> pos;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pos[a[i]].eb(i);
    }

    set<int> s;
    s.insert(-1);
    s.insert(n);
    multiset<int> len;
    len.insert(n);

    int ans = pos.begin()->F + 1, ansp = 1;
    for(auto& i : pos){
        if(len.empty() || *len.begin() == *len.rbegin()){
            if(len.size() >= ansp) ansp = len.size(), ans = i.F + 1;
        }
        for(int j : i.S){
            auto it2 = s.upper_bound(j);
            auto it = prev(it2);
//            cerr << "test " << i.F << " " << j << " " << *it << " " << *it2 << "\n";
            len.erase(len.find(*it2 - *it - 1));
            len.insert(*it2 - j - 1);
            len.insert(j - *it - 1);
            s.insert(j);
//            printv(len, cerr);
//            printv(s, cerr);
        }
        len.erase(0);
    }
    cout << ans << "\n";

    return 0;
}