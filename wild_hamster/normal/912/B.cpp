#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <time.h>
#include <fstream>
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
typedef long long ll;
using namespace std;

ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500];

int main() {
    // cout << setprecision(20);
    // ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    ll x = 1;
    while (x*2 <= n) {
        x *= 2, y++;
    }
    if (k == 1)
    cout << n << endl;
    else
        cout << (1LL<<y+1)-1 << endl;
    return 0;
}