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
#include <list>
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
#define ALP 26
typedef int ll;
typedef long double ld;
using namespace std;
ll i,j,n,k,l,m,tot, flag,r,z, K,x1,y1,x2,y2,x3,y3,x,y,h,num,h2,timer,sz,q,nn, hs, ml,cnt;
string s,t,s1;
ll a[300500], used[300500], b[300500];
ll P[505][505][2][62];
bitset<505> rows[2][505], cols[2][505];
bitset<505> tmp;
int main() {
	//freopen("input.txt","r",stdin);
 	//freopen("output.txt","w",stdout);
 	cin >> n >> m;
 	for (i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        P[x][y][z][0] = 1;
    }
    for (i = 0; i < 60; i++)
    {
        //0 = 0*1
        //1 = 1*0
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++)
                for (z = 0; z < 2; z++)
                {
                    rows[z][j][k] = P[j][k][z][i];
                    cols[z][k][j] = P[j][k][z][i];
                }
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++)
            {
                tmp = (rows[0][j] & cols[1][k]);
                if (tmp.any())
                    P[j][k][0][i+1] = 1;
                tmp = (rows[1][j] & cols[0][k]);
                if (tmp.any())
                    P[j][k][1][i+1] = 1;
            }
    }
    /*for (i = 0; i < 2; i++)
    {
        for (j = 1; j <= n; j++)
        {
            for (k = 1; k <= n; k++)
                cout << P[j][k][0][i];
            cout << " ";
            for (k = 1; k <= n; k++)
                cout << P[j][k][1][i];
            cout << endl;
        }
        cout << endl;
    }*/
    ll cur = 0;
    long long ans = 0;
    a[1] = 1;
    for (i = 60; i >= 0; i--)
    {
        for (j = 1; j <= n; j++)
            b[j] = 0;
        for (j = 1; j <= n; j++)
            for (k = 1; k <= n; k++)
                b[k] |= (a[j]&P[j][k][cur][i]);
        ll sum = 0;
        for (j = 1; j <= n; j++)
            sum += b[j];
        if (sum > 0)
        {
            for (j = 1; j <= n; j++)
                a[j] = b[j];
            ans += (1LL << i);
            cur = 1-cur;
        }
        /*cout << i << endl;
        for (j = 1; j <= n; j++)
            cout << a[j] << " ";
        cout << endl;*/
    }
    long long tmp = 1;
    for (i = 1; i <= 18; i++)
        tmp *= 10;
    if (ans > tmp)
        cout << -1 << endl;
    else
        cout << ans << endl;
    return 0;
}