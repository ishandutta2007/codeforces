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

    vector<vector<int>> pos(2500001);
    vector<vector<int>> two;
    vector<pii> owo(5000001, mp(-1, -1));
    vector<int> a(n);
    for(int i = 1; i <= n; i++){
        cin >> a[i - 1];
        pos[a[i - 1]].eb(i);
    }
    for(int i = 1; i <= 2500000; i++){
        if(pos[i].size() >= 2) two.eb(pos[i]);
        if(pos[i].size() >= 4){
            cout << "YES\n";
            cout << pos[i][0] << ' ' << pos[i][1] << ' ' << pos[i][2] << ' ' << pos[i][3] << "\n";
            return 0;
        }
    }

    if(two.size() >= 2){
        cout << "YES\n";
        cout << two[0][0] << " " << two[1][0] << " " << two[0][1] << " " << two[1][1] << "\n";
        return 0;
    }

    lsort(a);
    uni(a);

    for(int i = 0; i < a.size(); i++){
        for(int j = i; j < a.size(); j++){
            int t1 = a[i], t2 = a[j];
            if(t1 == t2 && pos[t1].size() == 1) continue;

            int sum = t1 + t2;
            if(owo[sum] != mp(-1, -1)){
                cout << "YES\n";
                cout << owo[sum].F << " " << owo[sum].S << " " << pos[t1].front() << " " << pos[t2].back() << "\n";
                return 0;
            }
            else owo[sum] = mp(pos[t1][0], pos[t2][0]);
        }
    }
    cout << "NO\n";

    return 0;
}