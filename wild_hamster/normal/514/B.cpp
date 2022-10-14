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
#define mp make_pair
#define pb push_back
#define PI 3.14159265358979323846
#define MOD 1000000007
#define x1 ldfjgldf
#define x2 lfhlgfjhklgh
#define y1 klfjdhgkldfjhkldf
#define y2 ldfjgkldfjgkldfjhl
#define MX 1000000
typedef long long ll;
using namespace std;
ll l,r,i,j,n,k,m,x,y,x1,y1,cons,a[100500];
string s,s1;
map <pair<ll,ll>,ll > f;
ll Abs(ll x)
{
 if (x < 0) return -x;
 return x;
} 
ll gcd(ll a, ll b)
{
 if (a%b == 0)
    return b;
 return gcd(b,a%b);
}
int main()
{
    cin >> n >> x >> y;
    ll rez = 0;
    for (i = 0; i < n; i++)
    {
        cin >> x1 >> y1;
        x1 -= x; y1 -= y;
        if (x1 == 0 && y1 == 0)
           continue;
        if (x1 == 0)
               y1 = 1;
        else
        if (y1 == 0)
           x1 = 1;
        else
        {
        ll tmp = gcd(Abs(x1),Abs(y1));
        x1/=tmp; y1/=tmp;
        }
        if (x1 < 0)
        {
         x1 = -x1;
         y1 = -y1;
        }
        if (f[mp(x1,y1)] == 0)
        {
         rez++;
         f[mp(x1,y1)] = 1;
        }
    }
    cout << rez << endl;
    return 0;
}