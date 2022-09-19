#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+5;
vector <int> a[maxn];
bool used[maxn];
int corn[maxn];
int pr[maxn];
int sub[maxn];
pair <int,int> query(vector <int> v)
{
    if(v.size()==0)
    {
        return {0,5*maxn};
    }
    cout<<"? "<<v.size()<<" ";
    for(int i=0;i<v.size();++i) cout<<v[i]+1<<" ";
    cout<<endl;
    pair <int,int> ans;
    cin>>ans.first>>ans.second;
    ans.first--;
    return ans;
}
void dfs(int x)
{
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            pr[v]=x;
            corn[v]=corn[x]+1;
            dfs(v);
        }
    }
    used[x]=false;
}
void dfs1(int x)
{
    used[x]=true;
    sub[x]=1;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            dfs1(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
}
int fin(int x,int sz)
{
    used[x]=true;
    int ans=(-1);
    bool h=(sub[x]>=(sz/2));
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v])
        {
            ans=max(ans,fin(v,sz));
            h=(h && sub[v]<=(sz/2));
        }
    }
    if(h)
    {
        ans=max(ans,x);
    }
    used[x]=false;
    return ans;
}
vector <int> go(int x)
{
    vector <int> v;
    for(int i=0;i<maxn;++i)
    {
        if(corn[i]>=x)
        {
            v.push_back(i);
        }
    }
    return v;
}
int32_t main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    for(int i=0;i<n;++i) a[i].clear();
    for(int i=0;i<maxn;++i) {pr[i]=(-1);corn[i]=0;used[i]=false;}
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
    }
    vector <int> v;
    for(int i=0;i<n;++i) v.push_back(i);
    pair <int,int> h=query(v);
    int o=h.second;
    int c=h.first;
    dfs1(0);
    int x=fin(0,sub[0]);
    corn[x]=0;
    pr[x]=(-1);
    dfs(x);
    int low=0;
    int up=maxn/2;
    int z=c;
    while(true)
    {
        if((up-low)==1)
        {
            corn[z]=0;
            dfs(z);
            vector <int> v=go(o);
            int r=query(v).first;
            cout<<"! "<<z+1<<" "<<r+1<<endl;
            string s;
            cin>>s;
            if(s=="Correct")
            {
                break;
            }
            else
            {
                exit(0);
            }
        }
        int k=(low+up)/2;
        vector <int> v=go(k);
        pair <int,int> ans=query(v);
        if(ans.second==o)
        {
            z=ans.first;
            low=k;
        }
        else
        {
            up=k;
        }
    }
    }
    return 0;
}