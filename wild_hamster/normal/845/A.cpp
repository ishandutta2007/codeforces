#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
typedef long long ll;
using namespace std;
ll n,i,j,k, a[505000], b[500000], ans[500500];
pii c[500500], d[500500];
string s;
int main() {
    cin >> n;
    for (i = 0; i < 2*n; i++)
        cin >> a[i];
    sort( a, a+2*n);
    if (a[n-1] == a[n])
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
    return 0;
}