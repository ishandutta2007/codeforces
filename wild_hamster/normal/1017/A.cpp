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
#define ROW 5
#define N 1000005
#define IN 5
#define OR 10
#define AND 15
#define XOR 20
#define NOT 25
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
ll b[2000500], answers[200500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> x;
            b[i] += x;
        }
    }
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        if (b[0] < b[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}