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
#define SQ 500400
#define CI 43534
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x,y,l,r,z;
string s1,s2,s3,s,t;
pair<pair<ll,ll>,ll> a[1000500];
vector<pair<pair<ll,ll>,ll> > f[1000500];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d%I64d",&x,&y);
        ll x1 = ((max(x-1,0LL))/1000);
        ll y1 = ((max(y-1,0LL))/1000);
        ll num;
        if (x1%2 == 0)
           num = x1*1000 + y1;
        else
            num = x1*1000 + 999 - y1;
        f[num].push_back(mp(mp(x,y),i+1));
    }
    for (i = 0; i <= 1000000; i++)
        sort(f[i].begin(),f[i].end());
    for (i = 0; i <= 1000000; i++)
    {
        for (j = 0; j < f[i].size(); j++)
            printf("%I64d ",f[i][j].second);
    }
    return 0;
}