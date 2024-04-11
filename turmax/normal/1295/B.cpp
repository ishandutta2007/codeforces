#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
    int n,x;
    cin>>n>>x;
    string s;
    cin>>s;
    vector <int> pr(n+1);
    map <int,int> u;
    u[0]=1;
    for(int i=0;i<n;++i)
    {
    pr[i+1]=pr[i]-(2*s[i]-'1'-'0');
    if(i==(n-1))
    {
        break;
    }
    if(!u.count(pr[i+1]))
    {
        u[pr[i+1]]=1;
    }
    else
    {
        u[pr[i+1]]++;
    }
    }
    if(pr[n]==0)
    {
    if(u.count(x))
    {
        cout<<(-1)<<endl;
        continue;
    }
    else
    {
        cout<<0<<endl;
        continue;
    }
    }
    //cout<<pr[n]<<" gfds "<<endl;
    int t1=(x-s.size())/pr[n];
    int t2=(x+s.size())/pr[n];
    if(t1>=t2)
    {
        swap(t1,t2);
    }
    int ans=0;
    //cout<<t1<<" "<<t2<<endl;
    for(int i=max(0LL,t1);i<=t2;++i)
    {
    int t=(x-pr[n]*i);
    if(u.count(t))
    {
        ans+=u[t];
    }
    }
    cout<<ans<<endl;
    }
    return 0;
}