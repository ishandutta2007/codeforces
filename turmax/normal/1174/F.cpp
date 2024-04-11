    #include <bits/stdc++.h>

    using namespace std;
    #define int long long
    const int maxn=200000;
    bool used[maxn];
    vector <int> a[maxn];
    vector <int> b[maxn];
    int sub[maxn];
    int corn[maxn];
    bool use[maxn];
    int pr[maxn];
    void dfs(int x)
    {
        used[x]=true;
        int v;
        int sz=1;
        for(int i=0;i<a[x].size();++i)
        {
            v=a[x][i];
            pr[v]=x;
            if(!used[v] && !use[b[x][i]])
            {
                corn[v]=corn[x]+1;
                dfs(v);
                sz+=sub[v];
            }
        }
        sub[x]=sz;
        used[x]=false;
    }
    int go(int x,int sz)
    {
        used[x]=true;
        int v;
        bool h=true;
        vector <int> z;
        h=(sub[x]>=(sz/2));
        int ans=(-1);
        for(int i=0;i<a[x].size();++i)
        {
            v=a[x][i];
            if(!used[v] && !use[b[x][i]])
            {
                ans=max(ans,go(v,sz));
                h=(h && sub[v]<(sz/2));
            }
        }
        used[x]=false;
        if(h)
        {
            return x;
        }
        else
        {
            return ans;
        }
    }
    int centroid(int x)
    {
        dfs(x);
        return go(x,sub[x]);
    }
    void getans(int x)
    {
        cout<<"! "<<(x+1)<<endl;
        exit(0);
    }
    int dquery(int x)
    {
        cout<<"d "<<(x+1)<<endl;
        int ans;
        cin>>ans;
        if(ans==0)
        {
            getans(x);
        }
        return ans;
    }
    int squery(int x)
    {
        cout<<"s "<<(x+1)<<endl;
        int ans;
        cin>>ans;
        if(ans==(-1))
        {
            exit(0);
        }
        else
        {
            return (ans-1);
        }
    }
    int sl(int x,int l)
    {
        corn[x]=0;
        dfs(x);
        if(sub[x]==1)
        {
            getans(x);
        }
        int t=centroid(x);
        int l2=dquery(t);
        int f=corn[t];
        if((f+l2)==l)
        {
            int o=squery(t);
            for(int i=0;i<a[t].size();++i)
            {
                use[b[t][i]]=true;
            }
            sl(o,l2-1);
        }
        else
        {
            int o=pr[t];
            for(int i=0;i<a[t].size();++i)
            {
                use[b[t][i]]=true;
            }
            sl(x,l);
        }
    }
    int32_t main()
    {
        //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n;
        cin>>n;
        for(int i=0;i<(n-1);++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);a[y].push_back(x);
            b[x].push_back(i);b[y].push_back(i);
        }
        sl(0,dquery(0));
        return 0;
    }