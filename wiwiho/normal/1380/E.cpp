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

int main(){
    StarBurstStream
    cerr.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> t(n + 1);
    set<int> s;
    vector<set<int>> d(m + 1);
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 1; i <= n; i++){
        if(i == n || t[i + 1] != t[i]){
            s.insert(i);
            d[t[i]].insert(i);
        }
    }

    cout << s.size() - 1 << "\n";

    int q = m - 1;
    while(q--){

        int a, b;
        cin >> a >> b;

        if(d[a].size() < d[b].size()){
            d[a].swap(d[b]);
        }

        for(int i : d[b]){
            if(s.find(i) == s.end()) continue;
            int nxt = s.upper_bound(i) == s.end() ? -1 : *s.upper_bound(i);
            if(d[a].find(nxt) != d[a].end()){
                s.erase(i);
                i = nxt;
            }
            else{
                d[a].insert(i);
            }
            int lst = s.lower_bound(i) == s.begin() ? -1 : *prev(s.lower_bound(i));
            if(d[a].find(lst) != d[a].end()){
                s.erase(lst);
                d[a].erase(lst);
            }
            t[i] = a;
        }

//        printv(s, cerr);
        cout << s.size() - 1 << "\n";

    }


    return 0;
}