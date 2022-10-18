#pragma GCC optimize("O3")
#include <bits/stdc++.h>

typedef long long ll;
#define int ll
typedef long double ld;

using namespace std;

const int MOD=1e9+7;

int sum1(int k)
{
    k%=MOD;
    return k*k%MOD;
}

int sum2(int k)
{
    k%=MOD;
    return k*(k+1)%MOD;
}

int solve(int n)
{
//    cout<<n<<" -> ";
    int k[3]={};
    int pw=1,par=1;
    while(n)
    {
        k[par]+=min(n,pw);
        n-=min(n,pw);
        pw*=2;
        par=3-par;
    }
//    cout<<k[1]<<" "<<k[2]<<" -> "<<sum1(k[1])<<" "<<sum2(k[2])<<" -> "<<sum1(k[1])+sum2(k[2])<<"\n";
    return (sum1(k[1])+sum2(k[2]))%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int l,r;
    cin>>l>>r;
    cout<<(solve(r)-solve(l-1)+MOD)%MOD;
}