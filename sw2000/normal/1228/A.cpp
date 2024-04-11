#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+10;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

bool can(int a)
{
    bool vis[10]={0};
    while(a)
    {
        int x=a%10;
        if(vis[x])return 0;
        vis[x]=1;
        a/=10;
    }
    return 1;
}

int main()
{
    int l,r;
    cin>>l>>r;
    for(int i=l;i<=r;i++)
    {
        if(can(i))
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}