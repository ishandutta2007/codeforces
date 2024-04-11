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
#define N 310
typedef int ll;
using namespace std;
ll n,i,j,k,x,y,z,m,Q,w,h;
ll a[100500], b[100500];
pii ans[100500];
struct info {
    int diff;
    int x;
    int num;
    info(){}
    info(int x, int num){
        this->x = x;
        this->num = num;
    }
};
vector<info> g[2][200500];
bool cmp(info x, info y)
{
    return x.x<y.x;
}
int main() {
    int offset = 100000;
    //freopen("input.txt", "r", stdin);
    int n,w,h;
    cin >> n >> w >> h;
    for (i = 0; i < n; i++)
    {
        int x, tim, test;
        cin >> test >> x >> tim;
        test--;
        g[test][x-tim+offset].push_back(info(x, i));
    }
    for (i = 0; i <= 200000; i++)
    {
        for (j = 0; j < 2; j++)
            sort(g[j][i].begin(), g[j][i].end(), cmp);
        k = 0;
        for (j = 0; j < g[k][i].size(); j++)
        {
            int x = j;
            int sz2 = g[1-k][i].size();
            int sz1 = g[k][i].size();
            //cout << i << " " << sz1 << " " << sz2 << endl;
            int pos = sz1-x-1;
            if (pos < sz2)
                ans[g[k][i][j].num] = mp(w, g[1-k][i][pos].x);
            else
                ans[g[k][i][j].num] = mp(g[k][i][sz1-1-(pos-sz2)].x, h);
        }
        k = 1;
        for (j = 0; j < g[k][i].size(); j++)
        {
            int x = j;
            int sz2 = g[1-k][i].size();
            int sz1 = g[k][i].size();
            //cout << i << " " << sz1 << " " << sz2 << endl;
            int pos = sz1-x-1;
            if (pos < sz2)
                ans[g[k][i][j].num] = mp(g[1-k][i][pos].x, h);
            else
                ans[g[k][i][j].num] = mp(w, g[k][i][sz1-1-(pos-sz2)].x);
        }
    }
    for (i = 0; i < n; i++)
        cout << ans[i].X << " " << ans[i].Y << endl;
    return 0;
}