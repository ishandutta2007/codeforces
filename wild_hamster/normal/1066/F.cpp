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
ll i,j,k,z,q,timer,x,y,n,m, cnt, even, flag, x1,y1,x2,y2, boom,r,c;
pii a[1005000];
map<int, vector<pii> > f;
long long dp[500500][2];
bool cmp(pii x, pii y) {
    if (x.X < y.X)
        return true;
    if (x.X > y.X)
        return false;
    if (x.Y > y.Y)
        return true;
    return false;
}
int Abs(int x) {
    return x>0?x:-x;
}
int dist(pii x, pii y) {
    return Abs(x.X - y.X) + Abs(x.Y - y.Y);
}
int main() {
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        f[max(x,y)].push_back(mp(x, y));
    }
    for (int i = 0; i <= 500000; i++)
        for (int j = 0; j < 2; j++)
            dp[i][j] = (long long)1e+18;
    pii lstl, lstr;
    f[0].push_back(mp(0, 0));
    int i = 0;
    for (auto itr = f.begin(); itr != f.end(); itr++) {
        sort((*itr).Y.begin(), (*itr).Y.end(), cmp);
        long long val = 0;
        for (int i = 0; i+1 < (*itr).Y.size(); i++) {
            val += dist((*itr).Y[i], (*itr).Y[i+1]);
        }
        //cout << (*itr).X << " " << val << endl;
        pii curl = (*itr).Y[0], curr = (*itr).Y[(*itr).Y.size()-1];
        if (i == 0) {
            dp[i][0] = dp[i][1] = 0;
            lstl = lstr = mp(0, 0);
            i++;
        } else {
            //cout << curl.X << " " << curl.Y << " " << curr.X << " " << curr.Y << endl;
            dp[i][0] = min(dp[i][0], dp[i-1][1] + dist(curl, lstl));
            dp[i][0] = min(dp[i][0], dp[i-1][0] + dist(curl, lstr));

            dp[i][1] = min(dp[i][1], dp[i-1][1] + dist(curr, lstl));
            dp[i][1] = min(dp[i][1], dp[i-1][0] + dist(curr, lstr));
            dp[i][0] += val;
            dp[i][1] += val;
            lstl = curl;
            lstr = curr;
            i++;
        }
    }
    cout << min(dp[i-1][0], dp[i-1][1]) << endl;
    return 0;
}