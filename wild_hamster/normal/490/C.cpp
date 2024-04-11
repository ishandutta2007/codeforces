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
#define mp make_pair
#define pb push_back
#define tA 555
#define tB 666
#define AorB 777
#define N 100499
#define PI 3.14159265358979323846
typedef long long ll;
using namespace std;
ll n,l,r,i,j,k,x,m,y,v,mod10a[1000500],mod10b[1000500],a10[1000500],b10[1000500],a[1000500];
vector <ll> f[5];
string s;
int main()
{
    cin >> s;
    cin >> x >> y;
    n = s.size();
    for (i = 0; i < n; i++)
        a[i] = s[i] -'0';
        
    a10[0] = 1%x; b10[0] = 1%y;
    for (i = 1; i < n; i++)
    {
        a10[i] = (a10[i-1]*10)%x;
        b10[i] = (b10[i-1]*10)%y;
    }
    
    k = 0; m = 0;
    for (i = n-1; i >= 0; i--)
    {
        //k = (k+a[i]*a10[n-i-1])%x;
        m = (m+a[i]*b10[n-i-1])%y;
        //mod10a[i] = k;
        mod10b[i] = m;
    }
    for (i = 0; i < n; i++)
    {
        mod10a[i] = (k*10+a[i])%x;        
        k = (k*10+a[i])%x;
    }
    l = n;
   
    for (i = 1; i <= n-1; i++)
    {
        //cout << mod10b[i] << " " << mod10a[i-1] << endl;
        if (a[i]!=0 && mod10b[i] == 0 && mod10a[i-1] == 0)
        {
         l = i;
         break;
        }
    }
    if (l == n)
       cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
        for (i = 0; i < l; i++)
            cout << a[i];
        cout << endl;
        for (i = l; i < n; i++)
            cout << a[i];
        cout << endl;
    }
    return 0;
}