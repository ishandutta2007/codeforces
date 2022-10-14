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
#define MOD 998244353
#define ROW 5
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,m,q,timer,mx, v,tot,x,y,INF, sz,ans;
const int alphabet = 12;
void add(ll &x, ll y) {
    x += y;
    if (x < 0)
        x += MOD;
    if (x >= MOD)
        x -= MOD;
}
int pn[3000500], cn[3000500], dp[3000500], pd[3000500];
int p[3000500], cnt[3000500], c[3000500];
char ss[1005000], ls[1005000], rs[1000500];
int z[2005000], zl[2005000], zr[2005000];
void z_function (string s) {
	int n = (int) s.size();
	for (int i = 0; i < n; i++)
        z[i] = 0;
	for (int i=1, l=0, r=0; i<n; ++i) {
		if (i <= r)
			z[i] = min (r-i+1, z[i-l]);
		while (i+z[i] < n && s[z[i]] == s[i+z[i]])
			++z[i];
		if (i+z[i]-1 > r)
			l = i,  r = i+z[i]-1;
	}
}

string s, l, r;
int L, R, S;

bool bigl(int pos, int bor) {
    int val = zl[pos+L];
    int diff = bor-pos;
    if (val >= diff)
        return true;
    if (s[pos+val] < l[val])
        return false;
    return true;
}

bool bigr(int pos, int bor) {
    int val = zr[pos+R];
    int diff = bor-pos;
    if (val >= diff)
        return true;
    if (s[pos+val] > r[val])
        return false;
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    char C;
    while (true) {
        C = getchar();
        if (C < '0' || C > '9')
            break;
        s.push_back(C);
    }
    while (true) {
        C = getchar();
        if (C < '0' || C > '9')
            break;
        l.push_back(C);
    }
    while (true) {
        C = getchar();
        if (C < '0' || C > '9')
            break;
        r.push_back(C);
    }
    char hyu = l[0];
    L = l.size();
    R = r.size();
    S = s.size();
    string t = l;
    t.append(s);
    z_function(t);
    for (int i = 0; i < L+S; i++)
        zl[i] = z[i];

    t = r;
    t.append(s);
    z_function(t);
    for (int i = 0; i < R+S; i++)
        zr[i] = z[i];

    /*for (int i = 0; i < L+S; i++)
        cout << zl[i];
    cout << endl;

    for (int i = 0; i < R+S; i++)
        cout << zr[i];
    cout << endl;*/

    dp[0] = 1;
    pd[1] = 1;
    //cout << s << endl;
    for (int i = 1; i <= S; i++) {
        int l = i-R;
        int r = i-L;
        //cout << i << " " << l << " " << r << endl;
        if (l < 0) {
            l = 0;
        } else if (!bigr(l, i)) {
            l++;
        }


        if (l > r) {
            pd[i+1] = pd[i];
            continue;
        }

        if (!bigl(r, i)) {
            r--;
        }

        if (l > r) {
            pd[i+1] = pd[i];
            continue;
        }

        //cout << i << " " << l << " " << r << " " << hyu << " " << L << endl;
        add(dp[i], pd[r+1]-pd[l]);
        if (s[i-1] == '0' && L == 1 && hyu == '0')
            add(dp[i], dp[i-1]);

        if (i == S)
            break;
        //cout << dp[i] << " " << (int)s[i-1] << " " << (int)s[S+1] << endl;
        pd[i+1] = pd[i];
        if (s[i] != '0')
            add(pd[i+1], dp[i]);

    }
    cout << dp[S] << endl;
    return 0;
}