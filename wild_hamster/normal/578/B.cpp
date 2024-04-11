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
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,l,r,z;
string s1,s2,s3,s,t;
ll a[200500], w[200500], d[80];
int main()
{
    cin >> n >> k >> x;
    for (i = 0; i < n; i++)
        scanf("%I64d",&a[i]);
     {
        for (j = 0; j <= 62; j++)
            d[j] = 0;
        for (l = 0; l < n; l++)
            for (j = 62; j >= 0; j--)
                if ((a[l]&(1LL<<j)) != 0)
                   d[j]++;
         ll sum = 0;
         for (j = 0; j <= 62; j++)
             if (d[j])
                sum |= (1LL<<j);
         ll max1 = sum;
         for (l = 0; l < n; l++)
         {

             ll tmp = a[l];
             for (i = 0; i < k; i++)
                 tmp *= x;
            for (j = 62; j >= 0; j--)
                if ((a[l]&(1LL<<j)) != 0)
                   d[j]--;
             for (j = 62; j >= 0; j--)
                if ((tmp&(1LL<<j)) != 0)
                   d[j]++;
             ll tmp2 = 0;
             for (j = 0; j <= 62; j++)
                 if (d[j])
                    tmp2 |= (1LL<<j);
             if (tmp2 > max1)
             {
                max1 = tmp2;
                y = l;
             }
             for (j = 62; j >= 0; j--)
                if ((a[l]&(1LL<<j)) != 0)
                   d[j]++;
             for (j = 62; j >= 0; j--)
                if ((tmp&(1LL<<j)) != 0)
                   d[j]--;
         }
         for (i = 0; i < k; i++)
         a[y] *= x;
     }
     ll ans = 0;
     for (i = 0; i < n; i++)
         ans |= a[i];
     cout << ans << endl;
    return 0;
}