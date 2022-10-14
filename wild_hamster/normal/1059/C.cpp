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
#define MOD 1000000007
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer, v,x,y,xx, yy,INF, sz,n,m, cnt, even, flag, ans;
vector<vector<pii> > g;
int used[1005];
vector<int> f;
int gcd(int a, int b) {
    return b==0?a:gcd(b,a%b);
}
int main() {
    //freopen("input.txt", "r", stdin);

    cin >> n;
    if (n == 1) {
        cout << 1 << endl;
    } else if (n == 2) {
        cout << 1 << " " << 2 << endl;
    } else if (n == 3) {
        cout << 1 << " " << 1 << " " << 3 << " " << endl;
    } else {
        int nn = n;
        for (int j = 0; j < 30; j++) {
            int p = n-n/2;
            for (int i = 0; i < p; i++)
                f.push_back(1<<j);
            n /= 2;
        }
        //cout << nn << endl;
        f[nn-1] = (nn/f[nn-2])*f[nn-2];
        for (int i = 0; i < f.size(); i++)
            printf("%d ", f[i]);
    }
    return 0;
}