#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <deque>
#define tr 1000000007
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,a[50][5],k,used[1228228];
double bits[21][1228228];
vector <ll> f[2];
double dist(double x1, double y1, double x2, double y2)
{
       return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
double find_some_shit(double l, double alpha, double x, double y)
{
    double dx = l-x, dy = -y;
    double ddx = dx*cos(alpha)-dy*sin(alpha), ddy = dx*sin(alpha)+dy*cos(alpha);
    double c = r-l;
    double a = dist(x,y,l,0);
    double b = dist(x,y,r,0);
    double alph = acos((a*a+b*b-c*c)/(2.*a*b));
    
    dx = ddx*(-y)/ddy;
    if (x+dx < l) 
    {     
     //cout << alph << " " << alpha << endl;
     return r-l;     
    }
    return x + dx - l;
}
int main()
{
    //cout.precision(15);
    cin >> n >> l >> r;
    for (i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    for (i = 0; i <= n; i++)
        for (j = 0; j < (1<<n); j++)
    bits[i][j] = l;
    f[0].push_back(0);
    ll cnt = 0;
    for (i = 0; i < (1<<n); i++)
        used[i] = -1;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < f[i%2].size(); j++)
        {
            cnt++;
            for (k = 0; k < n; k++)
                if ((f[i%2][j]&(1<<k)) == 0)
            {
                ll x = f[i%2][j];
                if (used[f[i%2][j]|(1<<k)]!=i) f[(i+1)%2].push_back(f[i%2][j]|(1<<k));
                used[f[i%2][j]|(1<<k)]=i;
                bits[i+1][f[i%2][j]|(1<<k)] = max(bits[i+1][f[i%2][j]|(1<<k)],bits[i][f[i%2][j]]+
                find_some_shit(bits[i][f[i%2][j]],a[k][2]*PI/180.,a[k][0],a[k][1]));
            }
        }
        f[i%2].clear();
    }
    //cout << f[n%2].size() << endl;
    cout.precision(15);
    //cout << bits[n][(1<<n)-1] << endl;
    cout << min(bits[n][(1<<n)-1],(double)r)-(double)l << endl;
    return 0;
}