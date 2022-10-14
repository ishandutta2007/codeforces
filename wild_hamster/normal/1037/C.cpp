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
const int INF = 1000*1000*1000;
ll n,m,k,x,y;
ll a[1000500];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    string s,t;
    cin >> s;
    cin >> t;
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (s[i] != t[i]) {
            if (i+1 < n && s[i+1] != t[i+1] && s[i] != s[i+1]) {
                i++;
                cnt++;
            } else {
                cnt++;
            }
        }
    cout << cnt << endl;
	return 0;
}