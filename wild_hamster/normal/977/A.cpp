#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define MOD 1000000007
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
pair<pii,ll> a[300500];
ll t[1005000];
vector<ll> f;

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    while (k--) {
        if (n%10 == 0)
            n /= 10;
        else
            n--;
    }
    cout << n << endl;
    return 0;
}