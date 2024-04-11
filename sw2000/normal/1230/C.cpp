#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=2e5+10;

int main()
{
    int n,m;
    cin>>n>>m;
    if(n<7)
    {
        cout<<m;
        return 0;
    }
    int vis[7][7]={0};
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        vis[a-1][b-1]=vis[b-1][a-1]=1;
    }
    int mi=inf;
    for(int i=0;i<7;i++)
    {
        for(int j=i+1;j<7;j++)
        {
            int cnt=0;
            for(int k=0;k<7;k++)
            {
                if(k!=i&&k!=j)
                {
                    if(vis[k][i]&&vis[k][j])cnt++;
                }
            }
            mi=min(mi,cnt);
        }
    }
    cout<<m-mi;
    return 0;
}