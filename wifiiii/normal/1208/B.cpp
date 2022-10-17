#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[2005];
unordered_map<int,int> vis;
int main()
{
    int n;
    cin>>n;
    ii cin>>a[i];
    int ok=1;
    for(int i=1;i<=n;++i)
    {
        if(vis[a[i]]) {ok=0;break;}
        vis[a[i]]=1;
    }
    if(ok) return cout<<0<<endl,0;
    int ans=1e9;
    for(int i=1;i<=n;++i)
    {
        vis.clear();
        int ok=1;
        for(int j=1;j<i;++j)
        {
            if(vis[a[j]]) {ok=0;break;}
            vis[a[j]]=1;
        }
        if(!ok) break;
        for(int j=n;j>=i;--j)
        {
            if(vis[a[j]])
            {
                ans=min(ans,j-i+1);
                break;
            }
            vis[a[j]]=1;
        }
    }
    cout<<ans<<endl;
}