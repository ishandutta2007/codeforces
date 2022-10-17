#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int a[100005],ans[100005];
int main()
{
    int n,m;
    cin>>n>>m;
    ll sum=0;
    for(int i=1;i<=m;++i) cin>>a[i],sum+=a[i];
    if(sum<n) return cout<<-1<<endl,0;
    for(int i=1;i<=m;++i)
    {
        ans[i]=i;
        if(i>n-a[i]+1) return cout<<-1<<endl,0;
    }
    for(int i=m;i>=1;--i)
    {
        if(ans[i]+a[i]-1 < n) ans[i]=n-a[i]+1,n=ans[i]-1;
        else break;
    }
    for(int i=1;i<=m;++i) cout<<ans[i]<<" ";cout<<endl;
}