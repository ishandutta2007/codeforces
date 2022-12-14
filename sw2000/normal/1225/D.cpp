#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int inf=0x3f3f3f3f;
const ll mod=1e9+7;

int vis[maxn],n,k;
ll ans=0;

void f(int a)
{
    int x=a;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            int cnt=0;
            while(a%i==0)
            {
                a/=i;
                cnt++;
            }
            while(cnt>=k)
            {
                for(int j=k;j;j--)
                {
                    x/=i;
                }
                cnt-=k;
            }
        }
    }
    ans+=vis[x];
}

void add(int a)
{
    int y=1;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
        {
            int cnt=0;
            while(a%i==0)
            {
                a/=i;
                cnt++;
            }
            cnt%=k;
            if(cnt)
            {
                for(;cnt<k;cnt++)
                {
                    if(maxn/i>=y)y*=i;
                    else return;
                }
            }
        }
    }
    if(a!=1)
    {
        for(int i=1;i<k;i++)
        {
            if(maxn/a>=y)y*=a;
            else return;
        }
    }
    vis[y]++;
}

int main()
{
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        f(a);
        add(a);
    }
    cout<<ans;
    return 0;
}