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
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx;
ll a[100500];
string t[105] , s;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> s;
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> t[i];
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
    {
        string cur = t[i];
        cur.append(t[j]);
        for (k = 0; k <= 2; k++)
            if (cur.substr(k, 2) == s)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}