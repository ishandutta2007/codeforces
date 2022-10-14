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
ll b[100500], a[1000500];
string s;
vector<ll> f;
int main() {
    //freopen("input.txt","r",stdin);
    x = 1;
    cin >> n >> m;
    for (int i = 30; i >= 1; i--) {
        while (n-((1<<i)-1) >= 0) {
            for (int j = 0; j < i; j++) {
                f.push_back(x);
            }
            x += m+1;
            n -= ((1<<i)-1);
        }
    }
    cout << f.size() << endl;
    for (int i = 0; i < f.size(); i++) {
        cout << f[i] << " ";
    }
    cout << endl;
    return 0;
}