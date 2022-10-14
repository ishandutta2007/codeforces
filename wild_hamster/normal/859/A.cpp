#include <bits/stdc++.h>
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
#define N 8388607
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,l,timer;
ll a[100500];
vector<ll> g[100500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> x;
        k = max(k,x);
    }
    cout << max(k-25,0) << endl;
    return 0;
}