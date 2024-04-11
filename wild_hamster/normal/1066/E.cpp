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
vector<pii> f, f1;
int a[1000500], b[1005000];
int main() {
    //freopen("input.txt", "r", stdin);
    int n,m;
    cin >> n >> m;
    string s,t;
    cin >> s >> t;
    a[n-1] = s[n-1]-'0';
    int p = 1;
    for (int i = n-2; i >= 0; i--) {
        p = p*2 % MOD;
        a[i] = (a[i+1] + p*(s[i]-'0'))%MOD;
    }
    int pos = n-1;
    int ans = 0;
    for (int i = m-1; i >= 0; i--) {
        ans = (ans + (t[i]-'0')*a[pos])%MOD;
        pos--;
        if (pos < 0)
            pos = 0;
    }
    cout << ans << endl;
    return 0;
}