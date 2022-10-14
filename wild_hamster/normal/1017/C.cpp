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
typedef long long ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
ll a[200500], b[2000500], answers[200500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
        if (i*i > n)
            break;
    i--;
    for (int j = 0; j < i; j++)
        f.push_back(i);
    ll sum = n-i*i;
    if (sum >= i) {
        f.push_back(i);
        sum -= i;
    }
    j = 0;
    while (sum > 0) {
        f[j]++;
        sum--;
        j++;
    }
    for (int j = 0; j < f.size(); j++) {
        ll cur = f[j];
        for (int k = n-cur+1; k <= n; k++)
            cout << k << " ";
        n -= cur;
    }
    return 0;
}