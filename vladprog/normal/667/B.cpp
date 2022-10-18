#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
    ll m=0,s=0;
    while(n--)
    {
        ll t;
        cin>>t;
        m=max(m,t);
        s+=t;
    }
    cout<<max(2*m-s,0ll)+1;
}