#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
string x,y;

bool f()
{
    int tx[30]={0},ty[30]={0};
    for(int i=0;i<n;i++)
    {
        tx[x[i]-'a']++;
        ty[y[i]-'a']++;
    }
    for(int i=0;i<26;i++)
        if(tx[i]!=ty[i])return 0;

    for(int i=0;i<26;i++)
        if(tx[i]>1)return 1;

    int ans=n;
    bool vis[30]={0};
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            ans--;
            char a;
            int b=i;
            while(vis[b]==0)
            {
                a=x[b];
                vis[b]=1;
                for(int j=i;j<n;j++)
                {
                    if(a==y[j])
                    {
                        a=x[j];
                        b=j;
                        break;
                    }
                }
            }
        }
    }
    if(ans&1)return 0;
    else return 1;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>x>>y;
        if(f())puts("yes");
        else puts("no");
    }
    return 0;
}