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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500];
using namespace std;
ll gcd(ll a, ll b) {
    return (b==0?a:gcd(b,a%b));
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1)
            k++;
    }
    ll x = a[0];
    for (int i = 1; i < n; i++)
        x = gcd(x, a[i]);
    if (x != 1) {
        cout << -1 << endl;
        return 0;
    }
    if (k > 0) {
        cout << n-k << endl;
        return 0;
    }
    ll min_ans = MOD;
    for (int i = 0; i < n; i++) {
        ll start = a[i];
        for (int j = i + 1; j < n; j++) {
            start = gcd(start, a[j]);
            if (start == 1) {
                min_ans = min(min_ans, j-i-1);
            }
        }
    }
    cout << min_ans+n << endl;
    return 0;
}