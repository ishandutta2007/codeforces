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
    cin >> n;
    ll val = n*(n+1)/2;
    for (int i = 2; i*i <= val && i < val; i++) {
        if (val % i == 0) {
            cout << "Yes" << endl;
            ll sum = i;
            ll cnt = 0;
            for (int j = n; j >= 1; j--) {
                if (sum >= j)
                    a[j] = 1, sum -= j, cnt++;
            }
            cout << cnt << " ";
            for (int i = 1; i <= n; i++)
                if (a[i])
                    cout << i << " ";
            cout << endl << n-cnt << " ";
            for (int i = 1; i <= n; i++)
                if (!a[i])
                    cout << i << " ";
            cout << endl;
            return 0;

        }
    }
    cout << "No" << endl;
	return 0;
}