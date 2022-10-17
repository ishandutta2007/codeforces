#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

ll a[303];
ll cal(ll n)
{
    ll ret = 0, i = 2;
    for(;i*i<n;++i) if(n%i==0) ret+=2;
    if(i*i==n) ret++;
    return ret;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        rep(i,n) cin>>a[i];
        sort(a+1,a+1+n);
        int ok = 1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]*a[n-i+1] != a[1]*a[n])
            {
                ok=0;break;
            }
        }
        if(ok && cal(a[1]*a[n])==n) cout<<a[1]*a[n]<<endl;
        else cout<<-1<<endl;
    }
}