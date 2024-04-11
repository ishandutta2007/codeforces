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

long long pow_mod(long long v, long long st, long long mod)
{
    long long ans=1, a=v;
    while(st)
    {
        if (st&1)
            ans=(ans*a)%mod;
        a=(a*a)%mod;
        st/=2;
    }
    return ans;
}

int main()
{   
    
    long long n, m, ans;
    cin >> n >> m;
    ans=pow_mod(3, n, m);
    ans=(ans+m-1)%m;
    cout << ans;
}