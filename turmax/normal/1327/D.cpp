    #include <bits/stdc++.h>
     
    using namespace std;
    #define int long long
    vector <int> h;
    vector <int> del(int n)
    {
        vector <int> res;
        for(int i=1;i*i<=n;++i)
        {
            if(n%i==0)
            {
                res.push_back(i);
                res.push_back(n/i);
            }
        }
        return res;
    }
    const int maxn=200000;
    int l[maxn+1];
    int go(vector <int> v,int n)
    {
        int x,ma;
        vector <int> keys;
        for(auto y:h)
        {
            keys.clear();
            ma=1;
            for(auto u:v)
            {
                x=(u%y);
                l[x]++;
                ma=max(ma,l[x]);
                keys.push_back(x);
            }
            for(auto u:keys)
            {
                l[u]=0;
            }
            if(ma==(n/y))
            {
                return y;
            }
        }
    }
    int slv(vector <int> v)
    {
        vector <int> keys;
        map <int,vector <int> > u;
        int n=v.size();
        int ans=v.size();
        h=del(n);
        sort(h.begin(),h.end());
        for(int i=0;i<v.size();++i)
        {
            if(!u.count(v[i]))
            {
                keys.push_back(v[i]);
                vector <int> z;
                z.push_back(i);
                u[v[i]]=z;
            }
            else
            {
                u[v[i]].push_back(i);
            }
        }
        for(int i=0;i<keys.size();++i)
        {
            ans=min(ans,go(u[keys[i]],n));
        }
        h.clear();
        return ans;
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
        int a[n];
        int b[n];
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            a[i]--;
        }
        for(int i=0;i<n;++i)
        {
            cin>>b[i];
        }
        bool used[n];
        for(int i=0;i<n;++i)
        {
            used[i]=false;
        }
        int ans=1e18;
        for(int i=0;i<n;++i)
        {
            vector <int> v;
            if(!used[i])
            {
                int curr=i;
                v.push_back(b[curr]);
                while(true)
                {
                    used[curr]=true;
                    curr=a[curr];
                    if(used[curr])
                    {
                        break;
                    }
                    v.push_back(b[curr]);
                }
                ans=min(ans,slv(v));
            }
        }
        cout<<ans<<endl;
        }
        return 0;
    }