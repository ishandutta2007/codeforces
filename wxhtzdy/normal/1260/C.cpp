#include <bits/stdc++.h>

using namespace std;
long long int typedef li;

int main()
{
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int t; cin>>t;
    while(t--)
    {
        li r,b,k; cin>>r>>b>>k;
        li g=__gcd(r,b);r/=g,b/=g;
        if(max(r,b)-1>(k-1)*min(r,b)) cout<<"REBEL\n";
        else cout<<"OBEY\n";
    }
}