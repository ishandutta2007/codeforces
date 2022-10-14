#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 998244353
#define ROW 5
typedef int ll;
using namespace std;
ll n,i,j,k,m,q,timer,mx, v,tot,x,y,INF, sz,ans;
int a[300050];

const int N = 15000001;
int lp[N+15], b[N+15];
int gcd(int a, int b) {
    return b==0?a:gcd(b,a%b);
}
vector<int> pr;

int main() {
    //freopen("input.txt", "r", stdin);
    for (int i=2; i<=N; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back (i);
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=lp[i] && i*pr[j]<=N; ++j)
            lp[i * pr[j]] = pr[j];
    }

    cin >> n;

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int g = a[0];
    for (int i = 1; i < n; i++)
        g = gcd(g, a[i]);
    int flag = 0;

    for (int i = 0; i < n; i++) {
        a[i] /= g;
        if (a[i] != 1)
            flag = 1;
        int x = a[i];
        while (x != 1) {
            int j = lp[x];
            b[j]++;
            while (x % j == 0)
                x /= j;
        }
    }
    if (!flag) {
        cout << -1 << endl;
        return 0;
    }
    int ans = n+15;
    for (int i = 0; i <= N; i++)
        ans = min(ans, n-b[i]);
    cout << ans << endl;
    return 0;
}