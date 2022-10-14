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
#define MAXN 1000005
typedef int ll;
using namespace std;
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom;

ll used[1005], d[605][605], used2[1005], dr[50][50];
vector<ll> comp[3];
vector<int> g, tmp;
int query(vector<int> &f) {
    int sz = f.size();
    cout << "? " << sz << endl;
    for (int i = 0; i < sz; i++) {
        cout << f[i];
        if (i + 1 != sz)
            cout << " ";
    }
    cout << endl;
    fflush(stdout);
    int ans = 0;
    /*for (int i = 0; i < f.size(); i++)
        for (int j = 0; j < f.size(); j++)
            ans += dr[f[i]][f[j]];
    ans /= 2;
    cout << ans << endl;
    cout << endl;*/
    cin >> ans;
    return ans;
}
void dfs(int v, int col) {
    used[v] = col;
    while (1) {
        vector<int> f;
        for (int i = 1; i <= n; i++)
        if (!used[i]) {
            f.push_back(i);
        }
        if (f.empty())
            return;

        tmp.clear();
        for (int i = 0; i < f.size(); i++)
            tmp.push_back(f[i]);
        int ans1 = query(tmp);
        tmp.push_back(v);
        int ans = query(tmp);
        if (ans == ans1)
            return;

        int sz = f.size();
        int l = 0, r = sz-1;
        while (l < r) {
            int mid = (l+r)/2;
            tmp.clear();
            for (int i = l; i <= mid; i++) {
                tmp.push_back(f[i]);
            }
            int ans1 = query(tmp);

            tmp.push_back(v);
            int ans2 = query(tmp);

            if (ans2 > ans1)
                r = mid;
            else
                l = mid+1;
        }
        tmp.clear();
        tmp.push_back(v);
        tmp.push_back(f[l]);
        assert(query(tmp) == 1);
        d[v][f[l]] = d[f[l]][v] = 1;
        //cout << "goto " << v << " " << f[l] << endl;
        dfs(f[l], col%2+1);
    }
}

void dfs1(int v) {
    if (used2[v])
        return;
    used2[v] = 1;
    g.push_back(v);
    if (v == boom) {
        cout << "N " << g.size() << endl;
        for (int i = 0; i < g.size(); i++)
            cout << g[i] << " ";
        exit(0);
    }
    for (int i = 1; i <= n; i++) {
        if (d[v][i] == 1)
            dfs1(i);
    }
    g.pop_back();
}

void find_bad(int x) {
    int sz = comp[x].size();
    int tot = query(comp[x]);

    int badv = 0;
    for (int j = 0; j < sz; j++) {
        int v = comp[x][j];
        tmp.clear();
        for (int i = 0; i < sz; i++)
            if (i != j)
                tmp.push_back(comp[x][i]);
        int ans1 = query(tmp);
        if (tot > ans1) {
            badv = comp[x][j];
            break;
        }
    }

    for (int j = 0; j < sz; j++) {
        int v = comp[x][j];
        if (v != badv) {
            tmp.clear();
            tmp.push_back(v);
            tmp.push_back(badv);
            int ans1 = query(tmp);
            boom = badv;
            if (ans1 == 1) {
                dfs1(v);
            }
        }
    }
}

void inp() {
    dr[1][4] = dr[4][1] = dr[1][3] = dr[3][1] = dr[2][3] = dr[3][2] = dr[2][4] = dr[4][2] = 1;
    dr[1][2] = dr[2][1] = 1;
}
int main() {
    //freopen("input.txt", "r", stdin);
    //inp();
    cin >> n;
    if (n == 1) {
        cout << "Y 1\n1\n";
        return 0;
    }
    dfs(1, 1);
    //cout << "used" << endl;
    for (int i = 1; i <= n; i++) {
        //cout << used[i] << " ";
        comp[used[i]].push_back(i);
    }
    //cout << endl;
    int ans1, ans2;
    for (int jj = 1; jj <= 2; jj++) {
        int ans1 = query(comp[jj]);
        if (ans1 != 0) {
            find_bad(jj);
            return 0;
        }
    }
    cout << "Y " << comp[1].size() << endl;
    for (int i = 0; i < comp[1].size(); i++)
        cout << comp[1][i] << " ";
    return 0;
}