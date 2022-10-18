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

    int T;
    cin >> T;

    while(T--){

        int n;
        cin >> n;
        map<int, vector<int>> tpos;
        for(int i = 0; i < n; i++){
            int a;
            cin >> a;
            tpos[a].eb(i);
        }

        vector<vector<int>> pos, dp1, dp2, dp3;
        for(auto& i : tpos){
            pos.eb(i.S);
            dp1.eb(vector<int>(i.S.size(), 1));
            dp2.eb(vector<int>(i.S.size(), 1));
            dp3.eb(vector<int>(i.S.size(), 1));
        }

        int ans = n - 1;
        for(int i = 0; i < pos.size(); i++){

            for(int j = 0; j < pos[i].size(); j++){
                if(i == 0 && j == 0) continue;
                if(j){
                    dp1[i][j] = dp1[i][j - 1] + 1;
                    dp2[i][j] = dp2[i][j - 1] + 1;
                    dp3[i][j] = dp3[i][j - 1] + 1;
                }
                else{
                    if(pos[i][j] > pos[i - 1].back()) dp2[i][j] = dp2[i - 1].back() + 1;
                }
                if(i == 0) continue;
                auto it = lower_bound(iter(pos[i - 1]), pos[i][j]);
                if(it != pos[i - 1].begin()){
                    int id = it - pos[i - 1].begin() - 1;
//                    dp2[i][j] = max(dp2[i][j], dp1[i - 1][id] + 1);
                    dp3[i][j] = max(dp3[i][j], dp1[i - 1][id] + 1);
//                    if(id == dp2[i - 1].size() - 1) dp2[i][j] = max(dp2[i][j], dp2[i - 1].back() + 1);
                    if(j == 0) dp2[i][j] = max(dp2[i][j], dp1[i - 1][id] + 1);
                    if(id == pos[i - 1].size() - 1) dp3[i][j] = max(dp3[i][j], dp2[i - 1].back() + 1);
                }
            }
            for(int j = 0; j < pos[i].size(); j++) ans = min({ans, n - dp1[i][j], n - dp2[i][j], n - dp3[i][j]});

//            cerr << "pos  ";
//            printv(pos[i], cerr);
//            cerr << "dp1  ";
//            printv(dp1[i], cerr);
//            cerr << "dp2  ";
//            printv(dp2[i], cerr);

        }

        cout << ans << "\n";

    }

    return 0;
}