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
typedef long long ll;
using namespace std;
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,pnt,flag;
ll a[155][155],b[155][155];
ll na,ma,nb,mb;
string s;
set<ll> f;
int main()
{
    cin >> na >> ma;
    for (i = 0; i < na ; i++)
        for (j = 0; j < ma; j++)
        {
            char c;
            cin >> c;
            a[i][j] = c - '0';
        }
    cin >> nb >> mb;
    for (i = 0; i < nb; i++)
        for (j = 0; j < mb; j++)
        {
            char c;
            cin >> c;
            b[i][j] = c - '0';
        }
    ll max1 = -1;
    for (x = -50; x <= 50; x++)
        for (y = -50; y <= 50; y++)
        {
            ll tmp = 0;
            for (i = 0; i < na; i++)
                for (j = 0; j < ma; j++)
                {
                    ll l = i+x;
                    if (l < 0)
                       l = 100;
                    ll r = j+y;
                    if (r < 0)
                       r = 100;
                    tmp += a[i][j] * b[l][r];
                }
            if (tmp > max1)
            {
                max1 = tmp;
                k1 = x;
                k2 = y;
            }
        }
    cout << k1 << " " << k2 << endl;
    return 0;
}