    #include <bits/stdc++.h>

    using namespace std;
    #define int long long
    int32_t main()
    {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int n;
        cin>>n;
        vector <int> a(n);
        vector <int> v;
        map <int,int> o;
        for(int i=0;i<n;++i)
        {
            cin>>a[i];
            if(!o.count(a[i]))
            {
                o[a[i]]=1;
                v.push_back(a[i]);
            }
            else
            {
                o[a[i]]++;
                //cout<<" tgfd "<<endl;
            }
        }
        sort(a.begin(),a.end());
        sort(v.begin(),v.end());
        int mi;
        int ans[v.size()+1];
        ans[v.size()]=0;
        for(int i=(v.size()-1);i>=0;i--)
        {
            if(i<(v.size()-2) && ((v[i+1]-v[i])==1 && (v[i+2]-v[i+1])==1))
            {
                ans[i]=ans[i+3]+1;
            }
            else if((i<v.size()-1) && (v[i+1]-v[i])<=2)
            {
                ans[i]=ans[i+2]+1;
            }
            else
            {
                ans[i]=ans[i+1]+1;
            }
        }
        mi=ans[0];
        int ma;
        bool used[n+5];
        for(int i=0;i<(n+5);++i)
        {
            used[i]=false;
        }
        map <int,int> e;
        int t;
        for(int i=0;i<n;++i)
        {
            if(e.count(a[i])==1)
            {
                continue;
            }
            e[a[i]]=1;
            //cout<<a[i]<<endl;
            t=o[a[i]];
            if(t>=3)
            {
                used[a[i]-1]=true;
                used[a[i]]=true;
                used[a[i]+1]=true;
                continue;
            }
            if(t==2 && !used[a[i]-1])
            {
                //cout<<" tgfd "<<endl;
                used[a[i]-1]=true;
                used[a[i]]=true;
                continue;
            }
            else if(t==2)
            {
                used[a[i]]=true;
                used[a[i]+1]=true;
                continue;
            }
            else if(t==1)
            {
                for(int j=(-1);j<2;++j)
                {
                    if(!used[a[i]+j])
                    {
                        used[a[i]+j]=true;
                        break;
                    }
                }
                continue;
            }
        }
        ma=0;
        for(int i=0;i<(n+5);++i)
        {
            if(used[i])
            {
                //cout<<i<<endl;
                ++ma;
            }
        }
        cout<<mi<<" "<<ma;
        return 0;
    }