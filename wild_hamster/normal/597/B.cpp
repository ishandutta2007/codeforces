#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <deque>
#include <stack>
#include <stdio.h>
#include <map>
#include <set>
#include <time.h>
#include <string>
#include <fstream>
#include <queue>
#include <bitset>
#include <cstdlib>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000033
#define MOD2 (33LL+(ll)1e+17)
#define INF (1LL+2LL*(ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 1488228
typedef int ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
ll c[N],a[N],b[N],dp[N];
set<ll> f;
map<ll,ll> sr;
set<ll>::iterator itr;
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n;
    for (i = 0; i <= 1000000; i++)
        a[i] = N;
    for (i = 0; i < n; i++)
    {
        scanf("%d %d",&b[i],&c[i]);
        f.insert(b[i]);
        f.insert(c[i]);
    }
    k = 0;
    for (itr = f.begin(); itr != f.end(); itr++)
    {
        sr[*itr] = k++;
    }
    for (i = 0; i < n; i++)
    {
        x = sr[b[i]];
        y = sr[c[i]];
        a[x] = min(a[x],y);
    }
    for (i = 0; i <= 1000000; i++)
    {
        dp[i+1] = max(dp[i+1],dp[i]);
        if (a[i] != N)
        {
            //cout << a[i] << " " << i << endl;
           dp[a[i]+1] = max(dp[a[i]+1],dp[i]+1);
        }
    }
    ll ans = 0;
    for (i = 0; i <= 1000001; i++)
        ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}