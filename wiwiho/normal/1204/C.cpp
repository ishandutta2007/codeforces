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

    int n;
    cin >> n;

    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        for(int j = 0; j < n; j++){
            if(s[j] == '1') g[i][j] = 1;
            else g[i][j] = MAX;
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    //for(int i = 0; i < n; i++) printv(g[i], cerr);

    int m;
    cin >> m;
    vector<int> p(m);

    vector<bool> c(m);
    c[0] = true;
    c[m - 1] = true;

    for(int i = 0; i < m; i++){
        cin >> p[i];
        p[i]--;
    }

    int lst = 0;
    for(int j = lst + 1; j < m; j++){
        if(g[p[lst]][p[j]] < j - lst || p[j] == p[lst]){
            //cerr << j << " " << lst << "\n";
            c[j - 1] = true;
            lst = j - 1;
            j = lst;
        }
    }

    int cnt = 0;
    for(int i = 0; i < m; i++) if(c[i]) cnt++;
    cout << cnt << "\n";

    for(int i = 0; i < m; i++){
        if(c[i]){
            cout << p[i] + 1 << " ";
        }
    }
    cout << "\n";
 
    return 0;
}