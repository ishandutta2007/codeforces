//pC Gauntlet 100/100 (unofficial)

//#define NDEBUG

#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
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
#define modadd(a, b) (((a % MOD) + (b % MOD)) % MOD)
#define modtimes(a, b) (((a % MOD) * (b % MOD)) % MOD)

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000000;

int main(){
    StarBurstStream

    int n , m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];

    vector<pii> ans;
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < m - 1; j++){
            if(a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1]){
                ans.pb(mp(i + 1, j + 1));
                b[i][j] = 1; b[i + 1][j] = 1; b[i][j + 1] = 1; b[i + 1][j + 1] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] != b[i][j]){
                cout << "-1\n";
                return 0;
            }
        }
    }

    cout << ans.size() << "\n";
    for(pii p : ans){
        cout << p.F << " " << p.S << "\n";
    }
 
    return 0;
}