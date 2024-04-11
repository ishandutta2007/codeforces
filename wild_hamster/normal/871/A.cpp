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
#define N 12
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll a[200500],b[25005], w[200500];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (k <= 11) {
            if (k == 4 || k == 6 || k == 9)
                cout << 1 << endl;
            else
            if (k == 8 || k == 10)
                cout << 2 << endl;
            else
                cout << -1 << endl;
        } else {
            if (k%4 == 0)
                cout << k/4 << endl;
            else
            if (k%4 == 1)
                cout << 1+(k-9)/4 << endl;
            else
            if (k%4 == 2)
                cout << k/4 << endl;
            else
                cout << 2+(k-15)/4 << endl;
        }
    }
    return 0;
}