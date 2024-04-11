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
#define MOD 998244353
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c,z;
int a[200500], used[200500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        used[a[i]] = i+1;
    }
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        x = used[x];
        int ans = max(x-mx, 0);
        mx = max(mx, x);
        printf("%d ", ans);
    }
    return 0;
}