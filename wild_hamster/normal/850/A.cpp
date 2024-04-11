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
#define SQ 2000
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,w,h,l,timer;
ll a[100500], b[100500], typ[100500], x1[100500], x2[100500];
ll points[1005][5];
vector<ll> ans;
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    if (n > 100)
    {
        cout << 0 << endl;
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < 5; j++)
            cin >> points[i][j];
    }
    for (i = 0; i < n; i++)
    {
        ll flag  = 1;
        for (j = 0; j < n; j++)
            for (k = j+1; k < n; k++)
                if (i != j && i != k)
                {
                    ll tmp = 0;
                    for (l = 0; l < 5; l++)
                        tmp += (points[j][l]-points[i][l])*(points[k][l]-points[i][l]);
                    if (tmp > 0)
                        flag = 0;
                }
        if (flag)
            ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}