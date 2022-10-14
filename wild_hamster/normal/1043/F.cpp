#include <bits/stdc++.h>
#define mp make_pair
#define pii pair<ll,ll>
#define X first
#define Y second
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define INF 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,x,y,n,m,  x1,y1,x2,y2,z;
ll p[300500], dp[300500], w[300500], a[300500], b[305];
vector<int> prd[300500];
vector<int> f;
int main() {
    //freopen("input.txt", "r", stdin);
    //srand(time(0));
    for (int i = 2; i <= 300000; i++)
        p[i] = 1;
    for (int i = 2; i <= 300000; i++) {
        if (p[i]) {
            prd[i].push_back(i);
            for (int j = i*2; j <= 300000; j+=i) {
                p[j] = 0;
                prd[j].push_back(i);
            }
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
        int v = prd[x].size();
        for (int j = 1; j < (1<<v); j++) {
            int val = 1;
            for (int k = 0; k < v; k++) {
                if ((j>>k)&1)
                    val *= prd[x][k];
            }
            w[val]++;
        }
    }
    for (int i = 1; i <= 300000; i++)
        dp[i] = INF;
    for (int i = 0; i < n; i++)
        dp[a[i]] = 1;
    for (int i = 300000; i >= 2; i--) {
            if (dp[i] == INF)
                continue;
        int v = prd[i].size();
        for (int j = 1; j < (1<<v); j++) {
            int val = 1;
            int sz = 0;
            for (int k = 0; k < v; k++) {
                if ((j>>k)&1) {
                    val *= prd[i][k];
                    b[sz++] = prd[i][k];
                }
            }



            int sum = 0;
            for (int k = 1; k < (1<<sz); k++) {
                int val1 = 1;
                int bits = 0;
                for (int l = 0; l < sz; l++)
                    if ((k>>l)&1) {
                        val1 *= b[l];
                        bits++;
                    }
                if (bits&1)
                    sum += w[val1];
                else
                    sum -= w[val1];
            }
            if (sum != n) {
                dp[i/val] = min(dp[i/val], dp[i]+1);
            }
        }
    }

    if (dp[1] == INF)
        dp[1] = -1;
    cout << dp[1] << endl;
    return 0;
}