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

void qq(vector<int>& c, vector<int> d){
    vector<vector<int>> t(d.size());
    queue<int> q;
    for(int i : c) q.push(i);
    for(int i = 0; i < d.size(); i++){
        while(d[i]--){
            t[i].eb(q.front());
            q.pop();
        }
    }
    c.clear();
    reverse(iter(t));
    for(int i = 0; i < d.size(); i++){
        for(int j : t[i]) c.eb(j);
    }
}

int main(){
    StarBurstStream

    int n;
    cin >> n;

    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<vector<int>> ans;
    for(int i = 1; i <= n; i++){
        vector<int> d;
        if((n - i) % 2){
            for(int j = 0; j < n; j++){
                if(c[j] < i){
                    d.eb(1);
                    if(j != n - 1 && c[j + 1] >= i) d.eb();
                }
                else if(c[j] == i){
                    if(d.empty()) d.eb();
                    d.back()++;
                    if(j != n - 1) d.eb();
                }
                else{
                    if(d.empty()) d.eb();
                    d.back()++;
                }
            }
        }
        else{
            for(int j = 0; j < n; j++){
                if(c[j] < i){
                    d.eb(1);
                }
                else if(c[j] == i){
                    d.eb(1);
                }
                else{
                    if(d.empty()) d.eb();
                    d.back()++;
                }
            }
        }
        if(d.size() > 1){
            ans.eb(d);
            qq(c, d);
        }
//        cerr << "test " << i << "\n";
//        printv(c, cerr);
//        printv(d, cerr);
    }

    cout << ans.size() << "\n";
    for(auto& i : ans){
        cout << i.size() << " ";
        printv(i, cout);
    }

    return 0;
}