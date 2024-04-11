#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        ll a,b,n,s;
        cin>>a>>b>>n>>s;
        if(a*n+b<s||s%n>b)puts("nO");
        else puts("yEs");
    }
    return 0;
}