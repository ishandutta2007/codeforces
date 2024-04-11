#include <bits/stdc++.h>

using namespace std;
#define int long long
const int p=(1e9+7);
int po(int a,int b)
{
    if(b==0)
    {
        return 1;
    }
    if(b==1)
    {
        return a;
    }
    if(b%2==0)
    {
        int u=po(a,b/2);
        return (u*u)%p;
    }
    int u=po(a,b-1);
    return (a*u)%p;
}
int ha(vector <int> v)
{
    int sum=0;
    for(int i=0;i<v.size();++i)
    {
        sum+=po(v[i]+100,v[i]+100);
        sum%=p;
    }
    return sum;
}
bool check(vector <vector <int> > a,vector <int> ans)
{
    int n=ans.size();
    int pr[n+1];
    pr[0]=0;
    for(int i=1;i<=n;++i)
    {
        pr[i]=pr[i-1]+po(ans[i-1]+100,ans[i-1]+100);
        pr[i]%=p;
    }
    set <int> ri;
    for(int i=0;i<(n-1);++i)
    {
        vector <int> v=a[i];
        int h=v.size();
        int u=ha(v);
        bool o=false;
        for(int j=0;j<=(n-h);++j)
        {
            if((((pr[j+h]-pr[j])%p+p)%p)==u)
            {
                o=true;
                ri.insert(j+h);
                break;
            }
        }
        if(!o)
        {
            return false;
        }
    }
    return ri.size()==(n-1);
}
pair <bool,vector <int> > go(int l,vector <vector <int> > a,int n)
{
    int deq[n];
    bool used[n];
    bool used1[n-1];
    for(int i=0;i<n;++i)
    {
        deq[i]=0;
        used[i]=false;
        if(i!=n)
        {
            used1[i]=false;
        }
    }
    used[l]=true;
    vector <int> h[n];
    for(int i=0;i<(n-1);++i)
    {
        for(int j=0;j<a[i].size();++j)
        {
            deq[a[i][j]]++;
            h[a[i][j]].push_back(i);
        }
    }
    vector <int> ans;
    while(true)
    {
        int r=(-1);
        for(int i=0;i<n;++i)
        {
            if(!used[i] && deq[i]==1)
            {
                r=i;
                break;
            }
        }
        if(r==(-1))
        {
            break;
        }
        ans.push_back(r);
        used[r]=true;
        for(int i=0;i<h[r].size();++i)
        {
            int v=h[r][i];
            if(!used1[v])
            {
                used1[v]=true;
                for(int i=0;i<a[v].size();++i)
                {
                    deq[a[v][i]]--;
                }
            }
        }
    }
    ans.push_back(l);
    reverse(ans.begin(),ans.end());
    if(ans.size()!=n)
    {
        return {false,ans};
    }
    bool h1=check(a,ans);
    if(h1)
    {
        return {true,ans};
    }
    else
    {
        return {false,ans};
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    vector <vector <int> > a(n-1);
    for(int i=0;i<(n-1);++i)
    {
        int x;
        cin>>x;
        vector <int> v(x);
        for(int j=0;j<x;++j)
        {
            cin>>v[j];
            v[j]--;
        }
        a[i]=v;
    }
    vector <int> res;
    for(int i=0;i<n;++i)
    {
        pair <bool,vector <int> > z=go(i,a,n);
        if(z.first)
        {
            res=z.second;
            break;
        }
    }
    for(int i=0;i<res.size();++i)
    {
        cout<<res[i]+1<<" ";
    }
    cout<<endl;
    }
    return 0;
}