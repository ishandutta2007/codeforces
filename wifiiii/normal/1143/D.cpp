#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
int main()
{
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    ll tot = n * k;
    ll m = 1e18, M = 0;
    ll c[4] = {a-b,k-a-b,b-a,a+b-k};
    for(int i=0;i<4;++i)
    {
        while(c[i]<0) c[i]+=k;
        while(c[i]<n*k)
        {
            ll tmp = n*k/gcd(n*k,c[i]);
            m = min(m,tmp);
            M = max(M,tmp);
            c[i] += k;
        }
    }
    cout << m << " " << M << endl;
}