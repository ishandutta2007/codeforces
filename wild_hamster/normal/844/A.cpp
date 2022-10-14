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
ll n,i,j,k,x,y,z,m,Q, mx,used[200500], w[200500], W[200500], start;
string s;
set<char> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> s >> k;
    n = s.size();
    if (n < k)
    {
        cout << "impossible" << endl;
        return 0;
    }
    for (i = 0; i < n; i++)
        f.insert(s[i]);
    cout << max(0, (int)(k-f.size())) << endl;
    return 0;
}