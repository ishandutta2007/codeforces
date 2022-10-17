#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

int a[200005];
int main()
{
    int n;cin>>n;
    int Mx = -1;
    rep(i,n)
    {
        int t;cin>>t;a[t]++,Mx=max(Mx,t);
    }
    int ans=n,now=0;
    rep(i,n)
    {
        now = max(now, i);
        while(now<=Mx && !a[now]) now++;
        if(now>Mx) {ans=i-1;break;}
        a[now]--;
    }
    cout<<ans<<endl;
}