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
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,h,x,y;
string s1,s2,s3,s;
ll a[105][105],b[105];
vector<pair<ll,ll> > f;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //printf("%.3f\n",15.5554);
    cin >> n >> m;
    cin >> s;
    ll ans = 0;
    for (i = 0; i < n-1; i++)
        if (s[i] == '.' && s[i+1] == '.')
           ans++;
    for (int i = 0; i < m; i++)
    {
        char c;
        scanf("%d %c",&x,&c);
        x--;
        if (c == '.' && s[x] != '.')
        {
            if (x > 0 && s[x-1] == '.')
               ans++;
            if (x < n-1 && s[x+1] == '.')
               ans++;
        } else
        if (c != '.' && s[x] == '.')
        {
            if (x > 0 && s[x-1] == '.')
               ans--;
            if (x < n-1 && s[x+1] == '.')
               ans--;
        }
        s[x] = c;
        printf("%d\n",ans);
    }
    return 0;
}