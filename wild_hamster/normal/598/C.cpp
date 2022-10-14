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
#define MOD 100003
#define MOD2 (33LL+(ll)1e+17)
#define INF (1+(ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
#define SQ 500400
#define CI 43534
#define N 118228
typedef int ll;
using namespace std;
ll l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,x,y,r,z,max1,tx,flag,timer,start,finita,ans;
vector <pair<long double,ll> > angles;
string s;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        long double x,y;
        cin >> x >> y;
        if (asin(y/sqrt(x*x+y*y)) > 0)
        angles.push_back(mp(acos(x/sqrt(x*x+y*y)),i+1));
        else
        angles.push_back(mp(2.*PI-acos(x/sqrt(x*x+y*y)),i+1));
    }
    sort(angles.begin(),angles.end());
    long double ans = 2.*PI;
    //for (i = 0; i < n; i++)
     // cout << angles[i].X << " " << angles[i].Y << endl;
    for (i = 0; i < n-1; i++)
    {
        long double fs = angles[i].X;
        long double sc = angles[i+1].X;
        if (sc-fs <= ans)
        {
            ans = sc-fs;
            k1 = angles[i].Y;
            k2 = angles[i+1].Y;
        }
    }
    long double fs = angles[n-1].X;
    long double sc = 2.*PI + angles[0].X;
    if (sc-fs <= ans)
        {
            ans = sc-fs;
            k1 = angles[n-1].Y;
            k2 = angles[0].Y;
        }
    cout << k1 << " " << k2 << endl;
    return 0;
}