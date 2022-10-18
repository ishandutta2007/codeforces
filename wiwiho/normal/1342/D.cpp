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
    cerr.tie(0);

    int n, k;
    cin >> n >> k;

    multiset<int> m;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        m.insert(t);
    }

    vector<int> c(k + 2);
    for(int i = 1; i <= k; i++) cin >> c[i];
    c[0] = MAX;
    c[k + 1] = 0;

    vector<vector<int>> ans;
    while(!m.empty()){
//        cerr << "test\n";
        vector<int> a;

        while(a.size() < c[1]){
            int it = prev(lower_bound(iter(c), a.size(), greater<>())) - c.begin();
//            cerr << it << " " << c[it] << " " << a.size() << "\n";
            auto it2 = m.upper_bound(it);
            if(it2 == m.begin()) break;
            it2--;
            a.eb(*it2);
            m.erase(it2);
        }

        if(a.empty()) break;
        ans.eb(a);
    }

    cout << ans.size() << "\n";
    for(auto& i : ans){
        cout << i.size() << " ";
        printv(i, cout);
    }

    return 0;
}