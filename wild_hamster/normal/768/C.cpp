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
#include <assert.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define pdd pair<double,double>
#define pii pair<ll,ll>
#define PI 3.14159265358979323846
#define MOD 1000000007
#define MOD2 1000000009
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define N 131072
#define SUM 377
#define MAG 33554431
#define RED 0
#define BLUE 1
typedef long long ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,c,ans, curL, curR, SQ;
string s,t;
ll dp[2][1045];
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> k >> x;
 	for (i = 0; i < n; i++)
    {
        cin >> y;
        dp[0][y]++;
    }
    for (i = 0; i < k; i++)
    {
        ll cur = i%2;
        ll nxt = (i+1)%2;
        for (j = 0; j <= 1023; j++)
            dp[nxt][j] = 0;
        ll curT = 0;
        for (j = 0; j <= 1023; j++)
        {
            if (curT == 0)
            {
                dp[nxt][j^x] += ((dp[cur][j]+1)>>1);
                dp[nxt][j] += dp[cur][j] - ((dp[cur][j]+1)>>1);
            }
            else
            {
                dp[nxt][j^x] += (dp[cur][j]>>1);
                dp[nxt][j] += dp[cur][j] - (dp[cur][j]>>1);
            }
            curT ^= (dp[cur][j]&1);
        }
    }
    ll min1 = 1050, max1 = -1050;
    for (i = 0; i < 1024; i++)
        if (dp[k%2][i] > 0)
    {
        min1 = min(min1, i);
        max1 = max(max1, i);
    }
    cout << max1 << " " << min1 << endl;
    return 0;
}