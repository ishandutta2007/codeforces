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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[15];
int main() {
    //freopen("input.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (j = 0; j < 10; j++)
        a[j] = 2;
    for (i = 0; i < n; i++) {
        char c;
        cin >> c >> x;
        if (c == '&') {
            for (int j = 0; j < 10; j++)
                if ((x&(1<<j)) == 0)
                    a[j] = 0;
        } else
        if (c == '|') {
            for (int j = 0; j < 10; j++)
                if ((x&(1<<j)) != 0)
                    a[j] = 1;
        } else {
            for (int j = 0; j < 10; j++)
                if ((x&(1<<j)) != 0)
                    a[j] ^= 1;
                else
                    a[j] ^= 0;
        }
    }
    cout << 3 << endl;
    y = 0;
    for (int j = 0; j < 10; j++)
        if (a[j] == 3)
            y |= (1<<j);
    cout << "^ " << y << endl;

    y = 0;
    for (int j = 0; j < 10; j++)
        if (a[j] == 1)
            y |= (1<<j);
    cout << "| " << y << endl;

    y = 0;
    for (int j = 0; j < 10; j++)
        if (a[j] == 0) {

        } else
            y |= (1<<j);
    cout << "& " << y << endl;
    return 0;
}