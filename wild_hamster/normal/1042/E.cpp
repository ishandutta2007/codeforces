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
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz;
vector<pair<ll, pii> > f;
int ans[1005000];
int binpow(int x, int y) {
    if (y == 0)
        return 1;
    int tmp = binpow(x, y/2);
    tmp = 1LL*tmp*tmp%MOD;
    if (y % 2 == 0)
        return tmp;
    return 1LL*x*tmp%MOD;
}
void add(int &a, int b) {
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int Abs(int x) {
    return x>0?x:-x;
}
int a[1005], b[1005], tmpa[1005], tmpb[1005];
vector<pii> saved;

int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        int x;
        scanf("%d", &x);
        f.push_back(mp(x, mp(i, j)));
    }
    sort(f.begin(), f.end());
    int sz = f.size();
    int sum = 0;
    for (int i = 0; i < sz; i++) {
        int j = i;
        while (j+1 < sz && f[j].X == f[j+1].X)
            j++;

        int cur = i;
        if (cur != 0)
            cur = binpow(cur, MOD-2);

        for (int k = i; k <= j; k++) {
            ans[k] = sum;
            for (int l = 0; l < saved.size(); l++) {
                add(ans[k], (saved[l].X - f[k].Y.X)*(saved[l].X - f[k].Y.X) +
                (saved[l].Y - f[k].Y.Y)*(saved[l].Y - f[k].Y.Y));
            }
            add(ans[k], a[f[k].Y.X]);
            add(ans[k], b[f[k].Y.Y]);
            ans[k] = 1LL*ans[k]*cur%MOD;
        }
        for (int k = i; k <= j; k++)
            saved.push_back(f[k].Y);


        if (saved.size() > 50) {
            for (int j = 0; j <= 1000; j++)
                tmpa[j] = tmpb[j] = 0;
            for (int j = 0; j < saved.size(); j++) {
                int x = saved[j].X;
                int y = saved[j].Y;
                tmpa[x]++;
                tmpb[y]++;
            }
            int cnt, sum, to_add;

            cnt = 0, sum = 0, to_add = 0;
            for (int j = 0; j < n; j++) {
                add(to_add, cnt*2);
                add(cnt, tmpa[j]);
                add(sum, to_add);
                add(a[j], sum);
                add(to_add, MOD-tmpa[j]);
            }

            cnt = 0, sum = 0, to_add = 0;
            for (int j = n-1; j >= 0; j--) {
                add(to_add, cnt*2);
                add(cnt, tmpa[j]);
                add(sum, to_add);
                add(a[j], sum);
                add(to_add, MOD-tmpa[j]);
            }

            cnt = 0, sum = 0, to_add = 0;
            for (int j = 0; j < m; j++) {
                add(to_add, cnt*2);
                add(cnt, tmpb[j]);
                add(sum, to_add);
                add(b[j], sum);
                add(to_add, MOD-tmpb[j]);
            }

            cnt = 0, sum = 0, to_add = 0;
            for (int j = m-1; j >= 0; j--) {
                add(to_add, cnt*2);
                add(cnt, tmpb[j]);
                add(sum, to_add);
                add(b[j], sum);
                add(to_add, MOD-tmpb[j]);
            }
            saved.clear();
        }

        for (int k = i; k <= j; k++) {
            add(sum, ans[k]);
        }
        i = j;
    }
    int x, y;
    cin >> x >> y;
    x--; y--;
    for (int i = 0; i < sz; i++)
    if (f[i].Y == mp(x, y)) {
        cout << ans[i] << endl;
        return 0;
    }
    return 0;
}