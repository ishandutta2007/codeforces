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

const long long mod=1000000007;
const int maxn=2015;
long long ck[maxn], v[maxn], ans[maxn];

long long pow_mod(long long v, long long st)
{
    long long a=v, ans=1;
    for(; st; st/=2)
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
    long long i, j, k, n, tmp;
    cin >> n >> k;
    for(i=1; i<=n; i++)
        cin >> v[i];
    ck[0]=1;
    for(i=1; i<n; i++)
    {
        ck[i]=(ck[i-1]*(k-1+i))%mod;
        tmp=get_obr(i);
        ck[i]=(ck[i]*tmp)%mod;
    }
    for(i=1; i<=n; i++)
    {
        for(j=0; j<=i; j++)
            ans[i]=(ans[i]+v[j+1]*ck[i-1-j])%mod;
    }
    for(i=1; i<=n; i++)
        cout << ans[i] << " ";
    return 0;
}