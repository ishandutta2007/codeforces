
#include <bits/stdc++.h>
typedef long long ll;
//typedef unsigned long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forij for(int i=1;i<=m;++i)
#define forjj for(int j=1;j<=m;++j)

int a[1005][1005],sum[1005][1005];
int n,m;
ll vala,valb;
ll solve(ll x,ll y)
{
    ll ans = 0;
    ll resy = y % m, resx = x % n;
    y /= m, x /= n;
    ll cnta=0,cntb=0;
    if(y&1)
    {
        if(__builtin_popcountll(y)%2) cnta++;
        else cntb++;
    }
    for(int i=1;i<31;++i) if(y&(1<<i)) cnta+=1<<(i-1),cntb+=1<<(i-1);
    if(__builtin_popcountll(x)%2==0) ans += cnta*sum[resx][m] + cntb*(resx*m-sum[resx][m]);
    else ans += cntb*sum[resx][m] + cnta*(resx*m-sum[resx][m]);
    
    ll tmpa=cnta*vala+cntb*valb,tmpb=cnta*valb+cntb*vala;
    ll cnta2=0,cntb2=0;
    if(x&1)
    {
        if(__builtin_popcountll(x)%2) cnta2++;
        else cntb2++;
    }
    for(int i=1;i<31;++i) if(x&(1<<i)) cnta2+=1<<(i-1),cntb2+=1<<(i-1);
    if(__builtin_popcountll(y)%2==0) ans += cnta2*sum[n][resy]+cntb2*(n*resy-sum[n][resy]);
    else ans += cntb2*sum[n][resy]+cnta2*(n*resy-sum[n][resy]);
    ans += tmpa*cnta2+tmpb*cntb2;
    if(__builtin_popcount(x)%2 ^ __builtin_popcount(y)%2) ans += resx*resy-sum[resx][resy];
    else ans += sum[resx][resy];
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int q;
    cin>>n>>m>>q;
    forii
    {
        string s;
        cin>>s;
        forjj
        {
            if(s[j-1]=='1') a[i][j]=1,vala++;
            else if(s[j-1]=='0') a[i][j]=0;
        }
    }
    valb = n*m-vala;
    forii
    forjj
    sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
    while(q--)
    {
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<solve(x2,y2)+solve(x1-1,y1-1)-solve(x1-1,y2)-solve(x2,y1-1)<<endl;
    }
}