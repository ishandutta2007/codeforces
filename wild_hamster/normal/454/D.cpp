 #include <iostream>
//#include <cmath>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <cstring>
#define tr 1000000007
#define mp make_pair
#define tA 555
#define tB 666
#define AorB 777
typedef long long ll;
using namespace std;
ll rez,l,r,n,m,k,j,p,pN,pM,k1,k2,i,fact[120],x,a[100500],prime[1005],isprime[100],dp[102][150000];
ll invfact[140000];
vector <ll> primes, total;
ll Abs(ll x)
{
 if (x < 0) return -x;
    return x;
}
int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 2; i < 100; i++)
        isprime[i] = 1;    
    for (i = 2; i < 60; i++)
    if (isprime[i])
        for (j = i*i; j < 60; j+=i)
            isprime[j] = 0;
    for (i = 0; i < 60; i++)
        if (isprime[i]) primes.push_back(i);
     ll kokoko = ((1<<17) - 1);
    for (i = 2; i < 60; i++)
    {
        for (j = 0; j < primes.size(); j++)
            if (i%primes[j] != 0)
               fact[i] = (fact[i]|(1<<j));
        invfact[kokoko-fact[i]] = i;
    }
    invfact[0] = 1;
    //cout << kokoko << endl;
    fact[1] = kokoko;
    for (i = 1; i <= n; i++)
        for (j = 0; j <= kokoko; j++)
            dp[i][j] = 100500;
    for (i = 0; i < n; i++)
    for (j = 1; j < 60; j++)
    {
        ll tmp = fact[j]&kokoko;
        //cout << tmp << endl;
        while (1)
        {
              if (dp[i+1][tmp|(kokoko-fact[j])] > dp[i][tmp] + Abs(a[i] - j))
                 dp[i+1][tmp|(kokoko-fact[j])] = dp[i][tmp] + Abs(a[i] - j);
              if (tmp == 0) break;
              tmp = (tmp-1)&fact[j];
              
        }
    }
    rez = (ll)1e+9;

    ll tmp = 0;
    for (i = 0; i <= kokoko; i++)
        if (rez > dp[n][i])
        {
                rez = dp[n][i];
                tmp = i;
        }
    //cout << tmp << endl;
    for (i = n; i >= 1; i--)
    {
        ll byk = tmp;
        for (j = 0; j <= byk; j++)
        {
        ll z = 1;
            for (k = 1; k < 60; k++)
            if (dp[i][tmp] - dp[i-1][j] == Abs(k-a[i-1]) && kokoko-fact[k] == tmp - j&&
            ((kokoko-fact[k])|j) == tmp )
            {
             total.push_back(k);
             tmp = j;
             //cout << tmp << endl;
             z = 0;
             break;
            }
        if (!z) break;
        }
    }
    ll size = total.size();
    for (i = size - 1; i >= 0; i--)
        cout << total[i] << " ";
    return 0;
}