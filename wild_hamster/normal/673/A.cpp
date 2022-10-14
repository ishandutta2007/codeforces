
 #include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define SQ 320
//#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,q,r,timer,mx;

ll t[100500], dp[100500], gg[100500], g[100500];
vector<pii> f[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> t[i];
    x = 0, i = 0;
    while (1) {
        x = min(x+15, 90);
        if (i == n || x < t[i]) {
            cout << x << endl;
            break;
        }
        while (i < n && t[i] <= x)
            i++;
        x = t[i-1];
    }
    return 0;
}