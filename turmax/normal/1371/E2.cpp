#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,p;
    cin>>n>>p;
    int a[n];
    for(int i=0;i<n;++i) cin>>a[i];
    sort(a,a+n);
    int x=1;
    for(int i=0;i<n;++i) x=max(x,a[i]-i);
    //cout<<x<<" x "<<endl;
    int b[n];
    for(int i=0;i<n;++i) {b[i]=min(max(0LL,n-a[i]+x),n);}
    sort(b,b+n);
    //cout<<x<<" x "<<endl;
    int c[n];
    for(int i=0;i<n;++i) c[i]=b[i];
    for(int i=0;i<n;++i) {b[i]-=i;}
    int maans=1e18;
    for(int i=0;i<n;++i)
    {
        if((n-i)%p==0)
        {
            maans=min(maans,n-c[i]-1);
        }
    }
    if(maans==(-1)) {cout<<0<<endl;return 0;}
    //cout<<maans<<" maans "<<endl;
    bool used[maans+1];
    for(int i=0;i<=maans;++i) used[i]=false;
    vector <int> v[p];
    for(int i=0;i<p;++i)
    {
        for(int j=0;j<=maans;j+=p)
        {
            v[i].push_back(0);
        }
        v[i].push_back(0);
        v[i].push_back(0);
        v[i].push_back(0);
    }
    for(int i=0;i<n;++i)
    {
        //cout<<i<<" i "<<endl;
        //cout<<b[i]<<"  b[i] "<<endl;
        int u=(p-b[i]%p)%p;
        //cout<<u<<" u "<<endl;
        if((c[i]+u)>=n) continue;
        v[u][0]--;
        v[u][min(((n-1-c[i]-u)/p)+1,((int) v[u].size())-1)]++;
    }
    for(int i=0;i<p;++i)
    {
        int sum=0;
        for(int j=0;j<v[i].size();++j)
        {
            sum+=v[i][j];
            if(sum!=0)
            {
                if((j*p+i)<=maans)
                used[j*p+i]=true;
            }
        }
    }
    vector <int> res;
    for(int i=0;i<=maans;++i)
    {
        if(!used[i])
        {
            res.push_back(i+x);
        }
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]<<' ';
    }
    return 0;
}