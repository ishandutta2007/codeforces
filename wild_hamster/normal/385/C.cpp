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
typedef long long ll;
using namespace std;
ll n,i,j,d,m,x,r,y,p,k,max1,e,l,a[10050500],primes[10055500],rez[10005500];
string s1,s2,s;
ll b[10005005];
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%I64d",&x);
        a[x]++;
    }
    for (i = 2; i < 10000005; i++)
        primes[i] = 1;
    for (i = 2; i < 10000005; i++)
    if (primes[i])
    {
     if (a[i] > 0)
       rez[i] += a[i];
     for (j = i*2; j < 10000005; j+=i)
     {
         primes[j] = 0;
         if (a[j] > 0)
         {
          rez[i] += a[j];
         } 
     } 
    }
    b[0] = 0;
    for (i = 0; i < 10000005; i++)
        b[i+1] = b[i]+rez[i];
    cin >> m;
    for (i = 0; i < m; i++)
    {
        cin >> l >> r;
        if (l > (ll)1e+7)
           cout << 0 << endl;
        else
        {
        if (r > (ll)1e+7)
           r = (ll)1e+7;
        cout << b[r+1] - b[l] << endl;
        }
    }
    return 0;
}