//#define NDEBUG

#include <bits/stdc++.h>

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
#define B back()
#define FR front()
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

const ll MOD = 1000000007;
const ll MAX = 2147483647;

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;

    vector<pii> mn(1 << m);
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cin >> a[i][j];
        for(int j = 0; j < (1 << m); j++){
            int t = MAX;
            for(int k = 0; k < m; k++){
                if((1 << k) & j) t = min(t, a[i][k]);
            }
            mn[j] = max(mn[j], mp(t, i));
        }
    }

    pii ans;
    int ansv = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int v = a[i][j];
            if(v <= ansv) continue;

            int t = 0;
            for(int k = 0; k < m; k++){
                if(a[i][k] < v) t += (1 << k);
            }
            if(mn[t].F >= v){
                ansv = v;
                ans = mp(i + 1, mn[t].S + 1);
            }
        }
    }

    //cerr << ansv << "\n";
    cout << ans.F << " " << ans.S << "\n";

    return 0;
}