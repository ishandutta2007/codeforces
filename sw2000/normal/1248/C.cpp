#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
const int mod=1e9+7;
int fib[maxn];

int main()
{
    int n,m;
    cin>>n>>m;
    fib[0]=fib[1]=1;
    for(int i=2;i<maxn;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
        fib[i]%=mod;
    }
    int ans=fib[n]+fib[m]-1;
    ans%=mod;
    ans=ans*2%mod;
    cout<<ans;
}