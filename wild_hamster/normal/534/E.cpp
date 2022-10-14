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
#define INF ((ll)1e+18)
typedef long long ll;
using namespace std;
ll v1,v2,x1,x2,x3,y1,t,y2,z,w,l,r,i,j,n,x,y,d,m,q;
ll a[400500],b[400500];
string s;
int main()
{
    cin >> n;
    for (i = 1; i <= n; i++)
        scanf("%d",&a[i]);
    l = a[n] - a[1];
    cin >> m;
    for (i = 0; i < m; i++)
    {
        scanf("%d",&x);
        b[x]++;
    }
    ll rez = 0;
    rez = (b[n]+b[1]-1)*l;
    for (i = 2; i < n; i++)
        b[i] -= b[n]+b[1]-1;
    ll flag = 1;
    for (i = 2; i < n; i++)
        if (b[i] != 1)
           flag = 0;
    if (b[1] != b[n])
       flag = 0;
    if (flag)
    {
     l = a[n-1] - a[1];
     for (i = 1; i < n; i++)
     if (a[i] - a[1] + a[n] - a[i+1] != l)
     {
        cout << -1 << endl;
        return 0;
     }
     cout << rez + l << endl;
     return 0;
    }
    if (b[1] == b[n])
    {
    l = 1; r = n;
    for (i = 2; i < n; i++)
        if (b[i] == 0)
           break;
        else 
        if (b[i] - b[i+1] == 1||i == n-1)
        {
           l = i;
           break;
        } 
           
    for (i = n-1; i >= 2; i--)
        if (b[i] == 0)
           break;
        else
        if (b[i] - b[i-1] == 1||i == 2)
        {
           r = i;
           break;
        } 
    rez += a[n] - a[r] + a[l] - a[1];
    } else
    if (b[1] > b[n])
    {
     for (i = 2; i < n; i++)
         rez += b[i]*(a[i]-a[i-1]);
    } else
    for (i = 2; i < n; i++)
         rez += b[i]*(a[i+1]-a[i]);
    cout << rez << endl;
    return 0;
}