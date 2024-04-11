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
ll a[300500],b[250005], c[200500];
vector<ll> ans;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    cout << 1;
    int pos = n-1;
    for (int i = 0; i < n; i++) {
        scanf("%d",&x);
        a[x-1] = 1;
        while (pos >= 0 && a[pos] == 1)
            pos--;
        printf(" %d",(i+2)-(n-1-pos));
    }
    return 0;
}