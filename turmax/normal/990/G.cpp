#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=2e5+5;
vector <int> a[maxn];
vector <int> h[maxn];
bool use1[maxn];
int b[maxn];
int ans1[maxn];
bool used[maxn];
int sub[maxn];
int corn[maxn];
int z[maxn];
int answ[maxn];
bool used2[maxn];
int mi2[maxn];
vector <int> rasl(int n)
{
    vector <int> v;
    if(n==1) return v;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            v=rasl(n/i);
            v.push_back(i);
            return v;
        }
    }
    v.push_back(n);
    return v;
}
void dfs1(int x)
{
    used[x]=true;
    sub[x]=1;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v] && !use1[h[x][i]])
        {
            dfs1(v);
            sub[x]+=sub[v];
        }
    }
    used[x]=false;
}
vector <int> h1;
void dfs2(int x)
{
    h1.push_back(corn[x]);
    used[x]=true;
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v] && !use1[h[x][i]])
        {
            corn[v]=__gcd(corn[x],b[v]);
            dfs2(v);
        }
    }
    used[x]=false;
}
int fin(int x,int sz)
{
    used[x]=true;
    int ans=(-1);
    bool h2=((2*sub[x])>=sz);
    for(int i=0;i<a[x].size();++i)
    {
        int v=a[x][i];
        if(!used[v] && !use1[h[x][i]])
        {
            ans=max(ans,fin(v,sz));
            h2=(h2 && (2*sub[v]<=sz));
        }
    }
    if(h2)
    {
        ans=x;
    }
    used[x]=false;
    return ans;
}
vector <int> f;
unordered_map <int,int> m1;
void pl(vector <int> d)
{
    m1.clear();
    sort(d.begin(),d.end());
    for(int i=0;i<d.size();++i)
    {
        if(!m1.count(d[i]))
        {
            m1[d[i]]=1;
        }
        else 
        {
            m1[d[i]]++;
        }
    }
    f.clear();
    for(int i=0;i<d.size();++i)
    {
        int o=d[i];
        if(i==0 || o!=d[i-1])
        {
        for(int j=1;j*j<=o;++j)
        {
            if(o%j==0)
            {
            z[j]+=m1[o];
            f.push_back(j);
            if(j*j!=o)
            {
                z[o/j]+=m1[o];
                f.push_back(o/j);
            }
            }
        }
        }
    }
    for(auto i:f)
    {
        ans1[i]+=(z[i]*(z[i]+1))/2;
        z[i]=0;
    }
}
void mi(vector <int> d)
{
    m1.clear();
    sort(d.begin(),d.end());
    for(int i=0;i<d.size();++i)
    {
        if(!m1.count(d[i]))
        {
            m1[d[i]]=1;
        }
        else 
        {
            m1[d[i]]++;
        }
    }
    f.clear();
    for(int i=0;i<d.size();++i)
    {
        int o=d[i];
        if(i==0 || o!=d[i-1])
        {
        for(int j=1;j*j<=o;++j)
        {
            if(o%j==0)
            {
            z[j]+=m1[o];
            f.push_back(j);
            if(j*j!=o)
            {
                z[o/j]+=m1[o];
                f.push_back(o/j);
            }
            }
        }
        }
    }
    for(auto i:f)
    {
        ans1[i]-=(z[i]*(z[i]+1))/2;
        z[i]=0;
    }
}
void go(int x)
{
    //cout<<x<<" x "<<endl;
    dfs1(x);
    if(sub[x]==1)
    {
        int o=b[x];
        for(int j=1;j*j<=o;++j)
        {
            if(o%j==0)
            {
                ans1[j]++;
                if(j*j!=o)
                {
                    ans1[o/j]++;
                }
            }
        }
        return;
    }
    int c=fin(x,sub[x]);
    corn[c]=b[c];
    //cout<<c<<" c "<<endl;
    vector <int> u;
    vector <int> g;
    for(int i=0;i<a[c].size();++i)
    {
        if(!use1[h[c][i]])
        {
            use1[h[c][i]]=true;
            int v=a[c][i];
            corn[v]=__gcd(b[c],b[v]);
            dfs2(v);
            for(int j=0;j<h1.size();++j)
            {
                u.push_back(h1[j]);
            }
            mi(h1);
            h1.clear();
            g.push_back(v);
        }
    }
    u.push_back(b[c]);
    pl(u);
    for(auto v:g)
    {
        go(v);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    used2[0]=true;used2[1]=true;
    for(int i=2;i<maxn;++i)
    {
        if(used2[i]) continue;
        for(int j=i;j<maxn;j+=i)
        {
            if(!used2[j])
            {
                used2[j]=true;
                mi2[j]=i;
            }
        }
    }
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    for(int i=0;i<(n-1);++i)
    {
        int x,y;
        cin>>x>>y;
        x--;y--;
        a[x].push_back(y);a[y].push_back(x);
        h[x].push_back(i);h[y].push_back(i);
    }
    go(0);
    for(int i=1;i<maxn;++i)
    {
        if(ans1[i]!=0)
        {
            //cout<<i<<" "<<ans1[i]<<" ans1[i] "<<endl;
        }
    }
    for(int i=1;i<maxn;++i)
    {
        answ[i]=ans1[i];
        for(int j=2;(i*j)<maxn;++j)
        {
            vector <int> v;
            int x=j;
            while(x!=1)
            {
                v.push_back(mi2[x]);
                x/=mi2[x];
            }
            //if(j==5) cout<<v.size()<<" size "<<endl;
            int sz=v.size();
            sort(v.begin(),v.end());
            v.erase(unique(v.begin(),v.end()),v.end());
            int o=1;
            if(v.size()==sz)
            {
                if(sz%2==1) o=(-1);
                //if(ans1[i*j]!=0) cout<<j<<" j "<<endl;
                answ[i]+=(o*ans1[i*j]);
            }
        }
    }
    for(int i=0;i<maxn;++i)
    {
        if(answ[i]!=0)
        {
            cout<<i<<" "<<answ[i]<<endl;
        }
    }
    return 0;
}