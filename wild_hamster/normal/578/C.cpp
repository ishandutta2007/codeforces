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
double a[200500], pa[200500];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d",&x);
        a[i] = x;
    }
    double l = -10000, r = 10000, ans;
    for (int ii = 0; ii < 200; ii++)
    {
        double m1 = l+(r-l)/3., m2 = r-(r-l)/3.;
        double fm1,fm2;
        
        {
        for (i = 0; i < n; i++)
            pa[i] = a[i] + m1;
        double max1 = -1e+9;
        double tmp = 0;
        for (i = 0; i < n; i++)
        {
            tmp += pa[i];
            if (tmp > max1)
               max1 = tmp;
            if (tmp < 0)
               tmp = 0;
        }
        
        for (i = 0; i < n; i++)
            pa[i] = -pa[i];
        double max2 = -1e+9;
        tmp = 0;
        for (i = 0; i < n; i++)
        {
            tmp += pa[i];
            if (tmp > max2)
               max2 = tmp;
            if (tmp < 0)
               tmp = 0;
        }
        fm1 = max(max1,max2);
        }
        
        {
        for (i = 0; i < n; i++)
            pa[i] = a[i] + m2;
        double max1 = -1e+9;
        double tmp = 0;
        for (i = 0; i < n; i++)
        {
            tmp += pa[i];
            if (tmp > max1)
               max1 = tmp;
            if (tmp < 0)
               tmp = 0;
        }

        for (i = 0; i < n; i++)
            pa[i] = -pa[i];
        double max2 = -1e+9;
        tmp = 0;
        for (i = 0; i < n; i++)
        {
            tmp += pa[i];
            if (tmp > max2)
               max2 = tmp;
            if (tmp < 0)
               tmp = 0;
        }
        fm2 = max(max1,max2);
        }
        if (fm1 > fm2)
            l = m1;
        else
            r = m2;
        ans = fm1;
    }
    printf("%.10f\n",ans);
    return 0;
}