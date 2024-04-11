#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <time.h>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <queue>
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF ((ll)1e+15)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll i,j,n,p,m,k,k1,k2,y,x,xs,ys,zs,xf,yf,zf,x1,y1,x2,y2,x3,y3,kk,l,r,a[1005][1005];
string s;
vector <string> f;
vector <ll> edges;
vector <pair<ll,ll> > ans;
int main()
{
    //cout << C(29,15) << endl;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    if (n%2 == 0)
    {
     cout << "NO" << endl;
     return 0;
    }
    cout << "YES" << endl;
    for (i = 2; i < 2 + n - 1; i++)
        for (j = 2 + n - 1; j < 2 + n - 1 + n - 1; j++)
            ans.push_back(mp(i,j));
    for (j = 2 + n - 1; j < 2 + n - 1 + n - 1 - 1; j+=2)
        ans.push_back(mp(j,j+1));
    for (i = 2; i < 2 + n - 1; i++)
        ans.push_back(mp(1,i));
    for (i = 2*n + 1; i < 2*n + 1 + n - 1; i++)
        for (j = 2*n + 1 + n - 1; j < 2*n + 1 + n - 1 + n - 1; j++)
            ans.push_back(mp(i,j));
    for (j = 2*n + 1 + n - 1; j < 2*n + 1 + n - 1 + n - 1 - 1; j+=2)
        ans.push_back(mp(j,j+1));
    for (i = 2*n + 1; i < 2*n + 1 + n - 1; i++)
        ans.push_back(mp(2*n,i));
    ans.push_back(mp(1,2*n));
    cout << 2*n + 1 + n - 1 + n - 1 - 1 << " " << ans.size() << endl;
    for (i = 0; i < ans.size(); i++)
        cout << ans[i].first << " " << ans[i].second << endl;
    return 0;
}