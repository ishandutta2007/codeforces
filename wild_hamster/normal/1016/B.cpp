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
typedef int ll;
using namespace std;
ll n,i,j,k,m,q,r,timer,v,tot,x,y,xx, yy,INF, sz;
ll a[200500], z[200500];
string s,t;
void z_function (string s) {
	int n = (int) s.size();
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
}

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m >> q;
    cin >> s >> t;
    t.append(s);
    z_function(t);
    for (int i = 0; i < q; i++) {
        ll ans = 0;
        cin >> x >> y;
        x--; y--;
        for (int j = x; j+m-1 <= y; j++) {
            if (z[j+m] >= m)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}