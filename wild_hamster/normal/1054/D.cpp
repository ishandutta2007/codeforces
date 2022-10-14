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
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
int a[10050], b[10050], used[10050], d[10050];
map<int, int> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    int val = 0;
    int su = (1<<k)-1;
    f[0]++;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (f[val^x] > f[val^su^x])
            x ^= su;
        val ^= x;
        ans += f[val];
        f[val]++;
    }
    cout << 1LL*n*(n+1)/2 - ans << endl;
    return 0;
}