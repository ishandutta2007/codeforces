#include <bits/stdc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll MOD = 1000000007;
const ll MAX = 1000000001;

int main(){

    StarBurstStream

    int n, m;
    cin >> n >> m;

    int a[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    int b[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }

    bool ans = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            int mi = min(a[i][j], b[i][j]);
            int ma = max(a[i][j], b[i][j]);
            a[i][j] = mi;
            b[i][j] = ma;
            if(j > 0 && (a[i][j] <= a[i][j - 1] || b[i][j] <= b[i][j - 1])){
                ans = false;
                goto out;
            }
            if(i > 0 && (a[i][j] <= a[i - 1][j] || b[i][j] <= b[i - 1][j])){
                ans = false;
                goto out;
            }
        }
    }
    out:
    cout << (ans ? "Possible" : "Impossible") << "\n";

    return 0;
}