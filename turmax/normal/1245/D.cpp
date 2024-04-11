#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n][n];
    vector <pair<int,int> > b(n);
    int x,y;
    for(int i=0;i<n;++i)
    {
        cin>>x>>y;
        b[i]={x,y};
    }
    vector <int> c(n);
    for(int i=0;i<n;++i)
    {
        cin>>x;
        c[i]=x;
    }
    vector <int> e(n);
    for(int i=0;i<n;++i)
    {
        cin>>x;
        e[i]=x;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            a[i][j]=(e[i]+e[j])*(abs(b[i].first-b[j].first)+abs(b[i].second-b[j].second));
        }
    }
    bool used[n];
    int h[n];
    int pr[n];
    for(int i=0;i<n;++i)
    {
        used[i]=false;
        h[i]=c[i];
        pr[i]=(-1);
    }
    int sum=0;
    vector <int> v;
    vector <pair<int,int> > u;
    int curr;
    pair <int,int> o;
    int mi,l;
    while(true)
    {
        mi=1e18;
        l=(-1);
        for(int i=0;i<n;++i)
        {
            if(h[i]<mi && !used[i])
            {
                mi=h[i];
                l=i;
            }
        }
        if(mi==1e18)
        {
            break;
        }
        used[l]=true;
        sum+=mi;
        if(pr[l]==(-1))
        {
            v.push_back(l);
        }
        else
        {
            u.push_back({l,pr[l]});
        }
        for(int i=0;i<n;++i)
        {
            if(!used[i] && (a[i][l])<h[i])
            {
                h[i]=a[i][l];
                pr[i]=l;
            }
        }
    }
    cout<<sum<<endl;
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    cout<<endl;
    cout<<u.size()<<endl;
    for(int i=0;i<u.size();++i)
    {
        cout<<u[i].first+1<<" "<<u[i].second+1<<endl;
    }
    return 0;
}