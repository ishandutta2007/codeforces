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
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 228228
typedef long long ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag;
string s,t;
ll a[100500];
vector <ll> f;
int main()
{
   cin >> n >> m;
   for (i = 1; i*i <= n; i++)
   if (n%i == 0)
   {
    if (i != n/i)
    {
        if (m%(n/i) == 0)
           f.push_back(n/i);
    }
    if (m%i == 0)
       f.push_back(i);
   }
   sort(f.begin(),f.end());
   reverse(f.begin(),f.end());
   cin >> k;
   for (i = 0; i < k; i++)
   {
    cin >> x >> y;
    for (j = 0; j < f.size(); j++)
        if (f[j] >= x && f[j] <= y)
        {
            cout << f[j] << endl;
            break;
        }
    if (j == f.size())
       cout << -1 << endl;
   }
    return 0;
}