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
#define MOD 21092013
#define INF ((ll)1e+9)
#define x1 fldgjdflgjhrthrl
#define x2 fldgjdflgrtyrtyjl
#define y1 fldggfhfghjdflgjl
#define y2 ffgfldgjdflgjl
typedef long long ll;
using namespace std;
ll i,j,n,k,k1,k2,k3,m,x1,y1,x2,y2,h,x,y;
string s1,s2,s3;
ll Abs(ll x)
{
    return (x>0?x:-x);
}
ll gcd(ll a, ll b)
{
    if (b == 0)
       return a;
    return gcd(b,a%b);
}
double dist(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
bool pal(ll x)
{
    vector<ll> f;
    while (x)
    {
        f.push_back(x%10);
        x /= 10;
    }
    ll i, sz = f.size();
    for (i = 0; i < sz; i++)
        if (f[i] != f[sz-i-1])
           return false;
    return true;
}
ll b[10005000],primes[10005000],parpri[10005000];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //printf("%.3f\n",15.5554);
    ll p,q;
    cin >> p >> q;
    for (i = 2; i <= 2000000; i++)
        primes[i] = 1;
    for (i = 2; i <= 2000000; i++)
    if (primes[i])
        for (j = i*i; j <= 2000000; j+=i)
            primes[j] = 0;
    b[0] = 0;
    for (i = 1; i <= 2000000; i++)
    if (pal(i))
       b[i] = b[i-1]+1;
    else
        b[i] = b[i-1];
    parpri[0] = 0;
    for (i = 1; i <= 2000000; i++)
        parpri[i] = parpri[i-1] + primes[i];

    //for (i = 1; i <= 172; i++)
    //  cout << parpri[i] << " " << b[i] << " " << primes[i] << " " << pal(i) << " " << i << endl;
    for (i = 2000000; i >= 1; i--)
        if (parpri[i]*q <= b[i]*p)
        {
            cout << i << endl;
            return 0;
        }
    return 0;
}