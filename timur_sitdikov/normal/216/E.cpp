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

map<long long, long long> mp;
long long m[100055];

int main()
{   
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    long long ans=0, ans1=0;
    long long k, b, n, a, mod, i, j, s, tmp;
    scanf("%I64d %I64d %I64d", &k, &b, &n);
    mod=k-1;
    m[0]=m[n+1]=1;
    for(i=1; i<=n; i++)
        scanf("%I64d", &m[i]);
    if (b==0 || b==mod)
    {
        for(i=1, j=0; i<=n+1; i++)
        {
            if (!m[i] && m[i-1])
            {
                j=i;
            }
            else if (m[i] && !m[i-1])
                ans1+=(i-j)*(i-j+1)/2;
        }
    }
    if (b==0)
    {
        cout << ans1;
        return 0;
    }
    s=0;
    mp[0]=1;
    if (b==mod)
        b=0;
    for(i=1; i<=n; i++)
    {
        s=s+m[i];
        if (s>=mod)
            s-=mod;
        tmp=s-b;
        if (tmp<0)
            tmp+=mod;
        if (mp.find(tmp)!=mp.end())
            ans+=mp[tmp];
        mp[s]++;        
    }
    if (!b)
        ans-=ans1;
    cout << ans;
}