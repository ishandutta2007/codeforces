
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

const int maxn = 200005;
int prime[maxn],np[maxn],ans[maxn],tot=0,cnt=0;
void init()
{
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) prime[++tot] = i, ans[i]=++cnt;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>=maxn) break;
            np[i*prime[j]] = 1;
            ans[i*prime[j]] = ans[prime[j]];
            if(i%prime[j]==0) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;cin>>n;
    init();
    for(int i=2;i<=n;++i) cout<<ans[i]<<" ";
    cout<<endl;
}