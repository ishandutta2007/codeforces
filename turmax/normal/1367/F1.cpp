#include <bits/stdc++.h>

using namespace std;
#define int long long
map <int,int> u;
map <int,int> z;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    u.clear();
    z.clear();
    int n;
    cin>>n;
    int a[n];
    int b[n];
    int pr[n];
    int answ[n];
    for(int i=0;i<n;++i) answ[i]=0;
    for(int i=0;i<n;++i) cin>>a[i];
    for(int i=0;i<n;++i) b[i]=a[i];
    for(int i=0;i<n;++i) u[a[i]]=i;
    sort(b,b+n);
    for(int i=0;i<n;++i) z[b[i]]=i;
    int ans=1;
    for(int i=0;i<n;++i)
    {
        int x=z[a[i]];
        if(x==0)
        {
            pr[i]=(-1);
            answ[i]=1;
            continue;
        }
        int y=u[b[x-1]];
        if(y>=i)
        {
            pr[i]=(-1);
            answ[i]=1;
            continue;
        }
        pr[i]=y;
        answ[i]=answ[y]+1;
        ans=max(ans,answ[i]);
    }
    cout<<(n-ans)<<endl;
    }
    return 0;
}