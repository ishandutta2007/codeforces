#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;

ll fib[maxn];

int main()
{
    fib[0]=fib[1]=1;
    for(int i=2;i<maxn;i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%mod;
    }
    string s;
    cin>>s;
    vector<ll>w;
    int u=0,n=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0;
            return 0;
        }
        if(s[i]=='u')u++;
        else
        {
            if(u>1)w.push_back(u);
            u=0;
        }
    }
    if(u>1)w.push_back(u);
    u=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='m'||s[i]=='w')
        {
            cout<<0;
            return 0;
        }
        if(s[i]=='n')u++;
        else
        {
            if(u>1)w.push_back(u);
            u=0;
        }
    }
    if(u>1)w.push_back(u);


    ll ans=1;
    for(int i=0;i<w.size();i++)
    {
        ans*=fib[w[i]];
        ans%=mod;
    }
    cout<<ans;

    return 0;
}