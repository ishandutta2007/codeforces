    #include <bits/stdc++.h>

    using namespace std;
    #define int long long
    int go(int a)
    {
        int u=2;
        while(true)
        {
            if(a%u!=0)
            {
                return (u/2);
            }
            else
            {
                u*=2;
            }
        }
    }
    bool comp(int a1,int a2)
    {
        return go(a1)>go(a2);
    }
    int32_t main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int n;
        cin>>n;
        vector <int> a(n);
        vector <int> b(n);
        int ma=-1e18;
        int k;
        for(int i=0;i<n;++i)
        {
            cin>>k;
            a[i]=k;
        }
        sort(a.begin(),a.end(),comp);
        b=a;
        int s;
        int g;
        while(!a.empty())
        {
            s=0;
            for(int i=0;i<a.size();++i)
            {
                if(a[i]%2!=0)
                {
                    ++s;
                }
            }
            ma=max(ma,s);
            g=a.size()-1;
            while(g>=0)
            {
                if(a[g]%2!=0)
                {
                    a.erase(a.begin()+g);
                }
                else
                {
                    a[g]/=2;
                }
                g--;
            }
        }
        a=b;
        set <int> v;
        int u=1;
        while(!a.empty())
        {
            s=0;
            for(int i=0;i<a.size();++i)
            {
                if(a[i]%2!=0)
                {
                    ++s;
                }
            }
            if(s==ma)
            {
                for(int i=0;i<a.size();++i)
                {
                    if(a[i]%2!=0)
                    {
                        v.insert(u*a[i]);
                    }
                }
                break;
            }
            g=a.size()-1;
            while(g>=0)
            {
                if(a[g]%2!=0)
                {
                    a.erase(a.begin()+g);
                }
                else
                {
                    a[g]/=2;
                }
                g--;
            }
            u*=2;
        }
        a=b;
        cout<<(n-ma)<<endl;
        for(int i=0;i<a.size();++i)
        {
            if(v.count(a[i])==0)
            {
                cout<<a[i]<<" ";
            }
        }
        return 0;
    }