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
#define x1 flkdgl
#define x2 fdgdfgh
#define y1 lfdkgl
#define y2 lhkgflhkf
typedef long long ll;
using namespace std;
ll hr,hb,wr,wb,x1,x2,y1,y2,x,y,z,w,l,r,i,j,n,a[100500],b[100500],k,k1,k2,d,m,q;
string s;
ll Abs(ll x)
{
 if (x < 0)
    return -x;
 return x;
}


ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
int main()
{
    cin >> n >> hr >> hb >> wr >> wb;
    ll rez = 0;
    for (i = 0; i < 100000; i++)
        if (wr*i <= n)
           rez = max(rez, hr*i + ((n-wr*i)/wb)*hb);
           
    for (i = 0; i < 100000; i++)
        if (wb*i <= n)
           rez = max(rez, hb*i + ((n-wb*i)/wr)*hr);
    cout << rez << endl;
    return 0;
}