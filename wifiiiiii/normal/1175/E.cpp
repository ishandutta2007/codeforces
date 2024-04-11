
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

const int maxn = 500005;
int r[maxn][20];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    rep(i,n)
    {
        int a,b;
        cin>>a>>b;
        r[a][0] = max(r[a][0], b);
    }
    for(int i=1;i<maxn;++i) r[i][0]=max(r[i][0],i),r[i][0]=max(r[i][0],r[i-1][0]);
    for(int j=1;j<20;++j)
        for(int i=0;i<maxn;++i)
            r[i][j] = r[r[i][j-1]][j-1];
    rep(i,m)
    {
        int a,b;
        cin>>a>>b;
        int tmp = 0, ans = 2e9;
        for(int i=19;i>=0;--i)
        {
            if(r[a][i] < b) a=r[a][i],tmp+=1<<i;
            else if(r[a][i] >= b) ans = min(ans, tmp+(1<<i));
        }
        if(ans!=2e9) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}