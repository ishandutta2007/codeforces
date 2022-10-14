#include <omp.h>
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
#define MOD 1000000007
#define INF ((ll)1e+15)
typedef int ll;
using namespace std;
ll globalflag,oz,l,i,j,k1,k2,dr,n,k,w,m, qt, qh, primes[5000050], a[5000050], b[5000050], md;
ll x,y;
int main()
{
    //freopen("kokoko.in","r",stdin);
    //freopen("kokoko.out","w",stdout);
    ll p = 5000000;
    for (i = 2; i <= p; i++)
        primes[i] = 1;
    for (i = 2; i <= p; i++)
    {
        if (primes[i])
        {
         a[i] = 1;
         for (j = i*2; j <= p; j += i)
         {
            primes[j] = 0;
            ll tmp = j;
            while (tmp % i == 0)
            {
                a[j]++;
                tmp/=i;
            }
         }
        }
    }
    b[0] = 0;
    for (i = 0; i <= p; i++)
        b[i+1] = b[i] + a[i];
    cin >> n;
    for (i = 0; i < n; i++)
    {
        scanf("%d%d",&y,&x);
        printf("%d\n",b[y+1]-b[x+1]);
    }
    return 0;
}