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
ll a[1005],b[1005],dp[1005];
vector <ll> f;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    if (n > m)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (i = 0; i < n; i++)
    {
        scanf("%I64d",&x);
        y = x;
        y %= m;
        a[y]++;
    }
    for (i = 0; i < m; i++)
        while (a[i]--)
           f.push_back(i);
    ll sz = f.size();
    for (i = 0; i < sz; i++)
    {
        //cout << f[i] << endl;
        for (j = 0; j < m; j++)
            b[j] = 0;

        b[f[i]] = 1;
        for (j = 0; j < m; j++)
            if (dp[j])
               b[(j+f[i])%m] = 1;
        for (j = 0; j < m; j++)
            dp[j] |= b[j];
    }
    if (dp[0])
       cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}