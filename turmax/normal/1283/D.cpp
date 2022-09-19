    #include <bits/stdc++.h>

    using namespace std;
    #define int long long
    int32_t main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n,m;
        cin>>n>>m;
        vector <int> a(n);
        set <int> r;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            r.insert(a[i]);
        }
        bool used[n][2];
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<2;++j)
            {
                used[i][j]=false;
            }
        }
        set <int> use;
        set <pair<int,int> > o;
        set <pair<int,int> > o1;
        for(int i=0;i<n;++i)
        {
            o.insert({i,-1});
            o.insert({i,1});
        }
        //o.insert({1e9,1e9});
        int curr=0;
        pair <int,int> d;
        int sum=0;
        while(use.size()<m)
        {
            o1.clear();
            ++curr;
            while(!o.empty())
            {
                d=(*o.begin());
                o.erase(o.begin());
                if(use.count(a[d.first]+d.second*curr) || use.size()>=m || r.count(a[d.first]+d.second*curr))
                {
                }
                else if(!r.count(a[d.first]+d.second*curr))
                {
                    //cout<<" tgfrd "<<endl;
                    use.insert(a[d.first]+d.second*curr);
                    sum+=curr;
                    o1.insert(d);
                }
                else
                {
                    o1.insert(d);
                }
            }
            o=o1;
        }
        cout<<sum<<endl;
        //use.insert(1e18);
        while(!use.empty())
        {
            cout<<(*use.begin())<<" ";
            use.erase(use.begin());
        }
        return 0;
    }