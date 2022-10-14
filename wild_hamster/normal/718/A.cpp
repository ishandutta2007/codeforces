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
#define COL 30000
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y, INF;
ll a[1200005], d[1205000];
pii b[1205000];
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {

    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    if (s[i] == '.') {
        x = i;
    }
    k = -1;
    for (int i = x+1; i < n; i++) {
        if (s[i] >= '5') {
            k = i-1;
            m--;
            break;
        }
    }
    if (k == -1) {
        cout << s << endl;
        return 0;
    }
    i = k;
    while (m > 0 && i >= x+1 && s[i] == '4') {
        m--;
        i--;
    }
    if (i != x) {
        while (s[i] == '9' && i > x)
            s[i] = '0', i--;
    }
    if (i == x) {
        i--;
        while (i >= 0 && s[i] == '9') {
            s[i] = '0';
            i--;
        }
        if (i == -1)
            cout << 1;
        else
            s[i]++;
        cout << s.substr(0, x) << endl;
    } else {
        s[i]++;
        cout << s.substr(0, i+1) << endl;
    }
    return 0;
}