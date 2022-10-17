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

const int maxn = 1000005;
int prime[maxn],np[maxn],mp[maxn],tot=0;
int main()
{
    np[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) prime[++tot]=i,mp[i]=i;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>=maxn) break;
            np[i*prime[j]] = 1, mp[i*prime[j]]=max(mp[i], prime[j]);
            if(i%prime[j]==0) break;
        }
    }
    int n;
    cin>>n;
    int ans = 1e9;
    for(int i=n-mp[n]+1;i<=n;++i)
    {
        if(!np[i]) ans=min(ans,i);
        else ans=min(ans,i-mp[i]+1);
    }
    cout << ans << endl;
}