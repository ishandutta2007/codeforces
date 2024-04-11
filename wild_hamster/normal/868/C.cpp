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
//#define N 1000005
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[100500];
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (i = 0; i < n; i++)
    {
        ll cur = 0;
        for (j = 0; j < k; j++)
        {
            int x;
            scanf("%d",&x);
            cur += (x<<j);
        }
        //cout << cur << endl;
        a[cur] = 1;
    }
    for (i = 0; i < 16; i++)
        for (j = 0; j < 16; j++)
            if (a[i] && a[j] && (i&j) == 0)
    {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}