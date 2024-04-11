#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
void exgcd(int a,int b,int &d,int &x,int &y)
{
    if(!b) {d=a;x=1;y=0;}
    else {exgcd(b,a%b,d,y,x);y-=x*(a/b);}
}
int ans[1000005];
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n,a,b;
    cin>>n>>a>>b;
    if(n%__gcd(a,b)) return cout<<-1<<endl,0;
    int d,x,y;
    exgcd(a,b,d,x,y);
    x*=n/d,y*=n/d;
    x=(x%(b/d)+(b/d))%(b/d);
    y=(n-a*x)/b;
    if(x<0 || y<0) return cout<<-1<<endl,0;
    int l=1,r;
    for(int i=1;i<=x;++i)
    {
        r=l+a-1;
        ans[l]=r;
        for(int j=l+1;j<=r;++j) ans[j]=j-1;
        l+=a;
    }
    for(int i=1;i<=y;++i)
    {
        r=l+b-1;
        ans[l]=r;
        for(int j=l+1;j<=r;++j) ans[j]=j-1;
        l+=b;
    }
    for(int i=1;i<=n;++i) cout<<ans[i]<<" ";cout<<endl;
}