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
#define INF ((ll)1e+18)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define MAXN 100100
typedef int ll;
using namespace std;
ll x,y,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,z,max1,tx,pnt,flag;
vector <ll> divisors;
ll a[500500];
int main()
{
    //freopen("input.txt","r",stdin);
    double x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    double vx = x2-x1, vy = y2-y1;
    double v,t,tx,ty,wx,wy;
    cin >> v >> t;
    cin >> tx >> ty;
    cin >> wx >> wy;
    {
     double x = x1-x2;
    double y = y1-y2;
    double a = tx*tx + ty*ty - v*v;
    double b = 2*x*tx + 2*y*ty;
    double c = x*x+y*y;
    double d = b*b - 4*a*c;
    double ans1 = (-b - sqrt(d))/(2.*a);
    double ans2 = (-b + sqrt(d))/(2.*a);
    if (ans2 < 0)
    {
     if (ans1 >= 0 && ans1 <= t)
     {
        printf("%.12f\n",ans1);
        return 0;
     }
    }
    if (ans1 < 0)
    {
     if (ans2 >= 0 && ans2 <= t)
     {
        printf("%.12f\n",ans2);
        return 0;
     }
    }
    if (ans1 >= 0 && ans1 <= t && ans2 >= 0 && ans2 <= t)
    {
       printf("%.12f\n",min(ans2,ans1));
        return 0;
    }
    }
    x1 += tx*t;
    y1 += ty*t;
    double x = x1-x2;
    double y = y1-y2;
    double a = wx*wx + wy*wy - v*v;
    double b = 2*x*wx + 2*y*wy - 2*t*v*v;
    double c = x*x+y*y - t*t*v*v;
    double d = b*b - 4*a*c;
    double ans1 = (-b - sqrt(d))/(2.*a);
    double ans2 = (-b + sqrt(d))/(2.*a);
    if (ans1 < 0)
       printf("%.12f\n",t+ans2);
    else
    if (ans2 < 0)
       printf("%.12f\n",t+ans1);
    else
        printf("%.12f\n",t+min(ans1,ans2));
    return 0;
}