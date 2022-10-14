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
ll x,y,l,i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,r,z,max1,tx,flag;
vector <ll> divisors,ans;
ll min_path[5][5];
string s,s1;
pii a[100015];
int main()
{
    //freopen("input.txt","r",stdin);
    ll a,b,m,vx,vy,vz;
    cin >> a >> b >> m >> vx >> vy >> vz;
    double v = -m/vy;
    ll x = ((int)(2*m*vx-a*vy)%(int)(-4*a*vy));
    //cout << 2*m*vx-a << " " << -2*a*vy << endl;
    if (x < 0)
       x += -4*a*vy;
    ll y = ((int)(m*vz)%(int)(-2*b*vy));
    //cout << xx << " " << yy << endl;
    if (y < 0)
       y += -2*b*vy;
    //cout << xx << " " << yy << endl;
       x = min(x,-4*vy*a-x);
       y = min(y,-2*vy*b-y);
    printf("%.10f %.10f\n",(double)x/(-2.*vy),-(double)y/vy);
    return 0;
}