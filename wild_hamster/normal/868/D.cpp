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
#define SQ 320
#define N 12
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l;
ll dp[205][14][4255];
string s[205], suf[205], pref[205];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> s[i];

        ll sz = s[i].size();
        for (j = 0; j < sz; j++)
        {
            for (k = 1; k+j <= sz && k <= N; k++)
            {
                ll cur = 0;
                for (l = j; l < j+k; l++)
                    cur += (s[i][l]-'0')*(1<<(l-j));
                dp[i][k][cur] = 1;
            }
        }
        if (sz >= N)
        {
            pref[i] = s[i].substr(0, N);
            suf[i] = s[i].substr(sz-N,N);
        } else
            suf[i] = pref[i] = s[i];
    }
    cin >> m;
    ll num = n;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        string cur = suf[x];
        cur.append(pref[y]);
        num++;
        ll sz = cur.size();
        for (j = 0; j < sz; j++)
        {
            for (k = 1; k+j <= sz && k <= N; k++)
            {
                ll tmp = 0;
                for (l = j; l < j+k; l++)
                    tmp += (cur[l]-'0')*(1<<(l-j));
                dp[num][k][tmp] = 1;
            }
        }
        if (suf[x].size() + suf[y].size() <= N)
            suf[num] = pref[num] = cur;
        else
        if (suf[x].size() >= N && suf[y].size() >= N)
        {
            pref[num] = pref[x];
            suf[num] = suf[y];
        } else
        if (suf[x].size() >= N)
        {
            pref[num] = pref[x];
            suf[num] = cur.substr(sz-N,N);
        } else
        if (pref[y].size() >= N)
        {
            pref[num] = cur.substr(0,N);
            suf[num] = suf[y];
        } else
        {
            pref[num] = cur.substr(0,N);
            suf[num] = cur.substr(sz-N,N);
        }
        for (j = N; j >= 1; j--)
        {
            for (l = 0; l < (1<<j); l++)
                dp[num][j][l] |= (dp[x][j][l]|dp[y][j][l]);
        }

        for (j = N; j >= 1; j--)
        {
            ll cur = 0;
            for (l = 0; l < (1<<j); l++)
                cur += dp[num][j][l];
            if (cur == (1<<j))
            {
                cout << j << endl;
                break;
            }
        }
        if (j == 0)
            cout << 0 << endl;
    }
    return 0;
}