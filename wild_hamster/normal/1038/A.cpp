#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,y, sz, t;
string s;
ll a[55555];
int main()
{
    //freopen("input.txt", "r", stdin);
    //cin >> s;
    //cout << s.find("hyu") << endl;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        a[s[i]-'A']++;
    ll ans = a[0];
    for (char i = 1; i < k; i++)
        ans = min(ans, a[i]);
    cout << ans*k << endl;
	return 0;
}