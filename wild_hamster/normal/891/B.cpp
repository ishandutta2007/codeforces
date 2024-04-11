#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
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
typedef int ll;
using namespace std;

ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500], b[100500];
map<ll,ll> f;
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);
    for (int i = 0; i < n; i++)
        f[b[i]] = b[(i+1)%n];
    for (i = 0; i < n; i++)
        a[i] = f[a[i]];
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}