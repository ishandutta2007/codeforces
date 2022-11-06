#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex<double>

const long long mod=1000000007;

long long pow_mod(long long v, long long st)
{
    long long a=v, ans=1;
    for(;st; st/=2)
    {
        if (st&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
    }
    return ans;
}

long long get_obr(long long v)
{
    return pow_mod(v, mod-2);
}

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long c, v, i, n;
    cin >> n;
    c=1; v=1;
    for(i=2; i<=n; i++)
    {
        v=(4*v-c+mod)%mod;
        c=(c*2)%mod;
        c=(c*(2*i-1))%mod;
        c=(c*get_obr(i+1))%mod;
    }
    cout << (2*v-n+mod)%mod;
}