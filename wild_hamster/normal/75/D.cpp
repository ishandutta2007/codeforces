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
ll a[100500],b[55],c[55][10],d[55],tot[1755555];
vector <ll> f;
int main()
{
    //freopen("input.txt","r",stdin);
   cin >> n >> m;
   for (j = 1; j <= n; j++)
   {

    ll max1 = -100500;
    cin >> k;
    for (i = 0; i < k; i++)
    {
        scanf("%I64d",&a[i]);
        max1 = max(max1,a[i]);
    }
    d[j] = max1;
    ll sum = 0;
    ll ans = 0;
    ll l = 0, r = 0;
    k1 = 0; k2 = -1;
    for (i = 0; i < k; i++)
    {
        if (sum + a[i] < 0)
        {
            sum = 0;
            l = i+1;
        } else
        {
            sum += a[i];
            if (sum >= ans)
            {
                k1 = l;
                k2 = i;
                ans = sum;
            }
        }
    }
    k2++;
    ll k3 = 0,k4 = 0;
    sum = 0, ans = 0;
    for (i = 0; i < k; i++)
    {
        sum += a[i];
        if (sum >= ans)
        {
            ans = sum;
            k3 = i+1;
        }
    }
    sum = 0, ans = 0;
    for (i = k-1; i >= 0; i--)
    {
        sum += a[i];
        if (sum >= ans)
        {
            ans = sum;
            k4 = i;
        }
    }
    ll b[5];
    b[0] = k1, b[1] = k2, b[2] = k3, b[3] = k4;
    sort(b,b+4);
    k1 = b[0], k2 = b[1], k3 = b[2], k4 = b[3];
    ll sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (i = 0; i < k1; i++)
        sum1 += a[i];
    for (i = k1; i < k2; i++)
        sum2 += a[i];
    for (i = k2; i < k3; i++)
        sum3 += a[i];
    for (i = k3; i < k4; i++)
        sum4 += a[i];
    for (i = k4; i < k; i++)
        sum5 += a[i];
    c[j][0] = sum1, c[j][1] = sum2, c[j][2] = sum3, c[j][3] = sum4, c[j][4] = sum5;
    
   }

   ll tmp = -100500;
   for (i = 0; i < m; i++)
   {
    scanf("%I64d",&x);
    tmp = max(tmp,d[x]);
    for (j = 0; j < 5; j++)
        tot[i*5+j] = c[x][j];
   }
   m *= 5;
   ll ans = 0, sum = 0;
   for (i = 0; i < m; i++)
   {
    if (sum + tot[i] < 0)
    {
        sum = 0;
    } else
    {
        sum += tot[i];
        ans = max(ans,sum);
    }
   }
   if (tmp < 0   )
   {
      cout << tmp << endl;
      return 0;
   }
   /*for (i = 0; i < m; i++)
       cout << tot[i] << " ";
   cout << endl;*/
   cout << ans << endl;
    return 0;
}