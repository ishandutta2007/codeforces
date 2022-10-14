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
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll b[100500];
char c[105][105];
ll a[105][105];
string s;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i+k <= n) {
                ll flag = 1;
                for (int l = i; l < i+k; l++)
                    if (c[l][j] == '#')
                        flag = 0;
                if (flag) {
                    for (int l = i; l < i+k; l++)
                        a[l][j]++;
                }
            }

            if (j+k <= n) {
                ll flag = 1;
                for (int l = j; l < j+k; l++)
                    if (c[i][l] == '#')
                        flag = 0;
                if (flag) {
                    for (int l = j; l < j+k; l++)
                        a[i][l]++;
                }
            }
        }
    }
    ll mx = -1, ix = 0, jx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
    if (a[i][j] > mx) {
        mx = a[i][j];
        ix = i;
        jx = j;
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";

        }
        cout << endl;
    }*/
    cout << ix+1 << " " << jx+1 << endl;
    return 0;
}