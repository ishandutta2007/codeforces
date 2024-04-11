#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e3+5;
vector <int> a[maxn];
bool used[maxn];
int corn[maxn];
int pr[maxn];
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
    for(int i=0;i<maxn;++i) {pr[i]=(-1);corn[i]=0;}
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
    corn[c]=0;
    pr[c]=(-1);
    dfs(c);
    int low=0;
    int up=maxn;
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