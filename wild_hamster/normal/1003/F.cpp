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
#define COL 30000
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,tot,x,y,INF, ans, d, sz;
ll dp[305];
ll w[500500], col[505], abscol[305][305], wei[305][305], parent[100500], ran[100500], pa[505], we[100500];
pair<string, int> a[505];
vector<pii> g[100500];
string s;

int find_set (int v) {
	if (v == parent[v])
		return v;
	return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
	a = find_set (a);
	b = find_set (b);
	if (a != b) {
		if (ran[a] < ran[b])
			swap (a, b);
		parent[b] = a;
		if (ran[a] == ran[b])
			++ran[a];
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    cin >> n;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            abscol[i][j] = i*(n+1)+j;
    for (int i = 0; i <= (n+1)*(n+1); i++)
        parent[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> a[i].X;
        cnt += a[i].X.size();
        pa[i+1] = pa[i] + (int)(a[i].X.size());
        a[i].Y = i;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i+j <= n)
                wei[i][j] = pa[i+j]-pa[i] -1;
    cnt += n-1;
    sort(a, a+n);
    sz = 0;
    i = 0;
    while (i < n) {
        col[a[i].Y] = sz;
        while (i+1 < n && a[i].X == a[i+1].X) {
            i++;
            col[a[i].Y] = sz;
        }
        i++;
        sz++;
    }

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++) {
            k = 0;
            while (k+j < n) {
                if (col[i+k] == col[j+k]) {
                    k++;
                    union_sets(abscol[i][k], abscol[j][k]);
                } else
                    break;
            }
        }

    for (int i = 0; i < n; i++)
        for (int j = 1; i+j <= n; j++) {
                //cout << i << " " << j << " " << find_set(abscol[i][j]) << endl;
            g[find_set(abscol[i][j])].push_back(mp(i, i+j-1));
            we[find_set(abscol[i][j])] = wei[i][j];
        }
    ll sum = 0;
    for (int i = 0; i <= 100000; i++) {
        sort(g[i].begin(), g[i].end());
        if (g[i].size() > 1) {
        /*cout << i << endl;
        cout << we[i] << endl;
        for (int j = 0; j < g[i].size(); j++)
            cout << g[i][j].X << " " << g[i][j].Y << endl;*/
        } else {
            continue;
        }
        for (int j = 0; j <= n; j++)
            dp[j] = 0;
        int k = 0;
        for (int j = 0; j < n; j++) {
            dp[j+1] = max(dp[j+1], dp[j]);
            while (k < g[i].size() && g[i][k].X == j) {
                dp[g[i][k].Y+1] = max(dp[g[i][k].Y+1], dp[j] + 1);
                k++;
            }
        }
        if (dp[n] >= 2)
            sum = max(sum, dp[n] * we[i]);

    }
    cout << cnt-sum << endl;
    return 0;
}