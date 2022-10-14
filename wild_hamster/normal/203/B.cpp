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
#define MOD 1000000007
#define MOD2 (33LL+(ll)1e+17)
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef int ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,flag;
vector <ll> divisors,ans;
ll min_path[5][5];
string s,s1;
ll a[1015][1015];
int main()
{
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    for (i = 0; i < m; i++)
    {
        cin >> x >> y;
        x += 2; y += 2;
        a[x][y] = 1;
        for (j = x-2; j <= x; j++)
            for (k = y-2; k <= y; k++)
            {
                ll tmp = 0;
                for (k1 = j; k1 <= j+2; k1++)
                    for (k2 = k; k2 <= k+2; k2++)
                        tmp += a[k1][k2];
                if (tmp == 9)
                {
                    cout << i+1 << endl;
                    return 0;
                }
            }
    }
    cout << -1 << endl;
    return 0;
}