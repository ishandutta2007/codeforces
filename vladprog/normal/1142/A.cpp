#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

int n,k;

int calc(int s)
{
    s%=n*k;
    s+=n*k;
    s%=n*k;
    return n*k/__gcd(n*k,s);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b;
    cin>>n>>k>>a>>b;
    int x=n*k,y=1;
    for(int p=0;p<n;p++)
    {
        int u=calc(p*k-a-b),
            v=calc(p*k-a+b);
        x=min({x,u,v});
        y=max({y,u,v});
    }
    cout<<x<<" "<<y;
}