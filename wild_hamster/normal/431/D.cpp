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
typedef long long ll;
using namespace std;
ll i,j,n,k,d,m,rez;
ll C(ll n, ll k)
{
    ll a[70];
    if (k < 0|| n < k) return 0;
    ll i,j;
    for (i = 0; i < 65; i++)
        a[i] = 0;
    for (i = n-k+1; i <= n; i++)
    {
        ll tmp = i;
        for (j = 2; j <= 64; j++)
            while (tmp %j == 0)
            {
                tmp /= j;
                a[j]++;
            }
    }

    for (i = 1; i <= k; i++)
    {
        ll tmp = i;
        for (j = 2; j <= 64; j++)
            while (tmp %j == 0)
            {
                tmp /= j;
                a[j]--;
            }
    }

    ll rez = 1;
    for (i = 2; i <= 64; i++)
        while (a[i]--)
            rez *= i;
    return rez;
        
}
ll F(ll n)
{
    ll i,j;
    for (i = 62; i >= 0; i--)
        if (n&(1LL<<i))
        {
            j = i;
            break;  
        }
    ll bits = 0;
    ll rez = 0;
    for (i = j; i >= 0; i--)
        if (n&(1LL<<i))
    {
        rez += C(i,k-bits);
        bits++;
    }
    if (bits == k) rez++;
    return rez;
}
int main()
{
    cin >> n >> k;
    //cout << F(10) << " " << F(20) << endl;
    ll l = 1, r = (ll)1e+18;
    while (l < r)
    {
        ll mid = (l+r-1)/2;
        ll rez = F(2LL*mid) - F(mid);
        //cout << rez << endl;
        if (rez >= n)
            r = mid;
        else
            l = mid+1;
    }
    cout << l << endl;
    return 0;
}