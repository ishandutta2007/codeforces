#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 0
#define dout if(DEBUG) cout

const int MAXN = 1e5 + 5;
const int MAXT = 1e6 + 5;

int conference[MAXT];
int ee[MAXN][2];
vi g[MAXN];
int team[MAXN];

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &ee[i][0], &ee[i][1]);
        ee[i][0]--;
        ee[i][1]--;
    }
    int k;
    int v;
    int mx = 0;
    for(int i = 0; i < n; i++){
        scanf("%d", &k);
        for(int j = 0; j < k; j++){
            scanf("%d", &v);
            mx = max(mx, v);
            g[i].pb(v - 1);
        }
    }
    srand(23);
    for(;;){
        for(int i = 0; i < mx; i++){
            conference[i] = rand() & 1;
        }
        for(int i = 0; i < n; i++){
            int pos = rand() % ((int)g[i].size());
            team[i] = g[i][pos];
        }
        int ans = 0;
        for(int i = 0; i < m; i++){
            int c1 = conference[team[ee[i][0]]];
            int c2 = conference[team[ee[i][1]]];
            if(c1 != c2) ans++;
        }
        if(ans * 2 >= m) break;
    }
    for(int i = 0; i < n; i++) printf("%d ", team[i] + 1);
    printf("\n");
    for(int i = 0; i < mx; i++) printf("%d ", conference[i] + 1);
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
     //assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}