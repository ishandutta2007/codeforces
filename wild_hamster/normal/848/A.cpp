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
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q, mx,a[300500], pa[600500];
vector<ll> g[200500];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    if (n == 0)
    {
        cout << "a" << endl;
        return 0;
    }
    string s;
    char c = 'a';
    while (n)
    {
        for (i = 0; n >= i; i++)
        {
            n -= i;
            s.push_back(c);
        }
        c++;
    }
    cout << s << endl;
    return 0;
}