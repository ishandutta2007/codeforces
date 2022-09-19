        #include <bits/stdc++.h>
     
        using namespace std;
        #define int long long
        struct clas
        {
            vector <int> a;
            vector <pair<int,int> > b;
            void insert(pair<int,int> x)
            {
                a[lower_bound(b.begin(),b.end(),x)-b.begin()]=1;
            }
            int count(pair<int,int> x)
            {
                return a[lower_bound(b.begin(),b.end(),x)-b.begin()];
            }
        };
        int32_t main()
        {
            ios_base::sync_with_stdio(false);
            cin.tie(0);
            cout.tie(0);
            int n,m;
            cin>>n>>m;
            vector <int> a[n];
            int deq[n];
            vector <pair<int,int> > b;
            for(int i=0;i<n;++i)
            {
                deq[i]=0;
                a[i].clear();
            }
            int x,y;
            for(int i=0;i<m;++i)
            {
                cin>>x>>y;
                x--;
                y--;
                a[x].push_back(y);
                a[y].push_back(x);
                b.push_back({x,y});
                b.push_back({y,x});
                deq[x]++;
                deq[y]++;
            }
            clas ban;
            sort(b.begin(),b.end());
            ban.b=b;
            vector <int> u2;
            u2.resize(b.size());
            for(int i=0;i<u2.size();++i)
            {
                u2[i]=0;
            }
            ban.a=u2;
            int i=0;
            vector <int> v;
            vector <pair<int,int> > res;
            while(true)
            {
                v.clear();
                if(i==n)
                {
                    break;
                }
                if((deq[i]%2)==1)
                {
                    x=i;
                    while(true)
                    {
                        v.push_back(x);
                        if((deq[x]%2)==1 && v.size()!=1 && (x!=i))
                        {
                            for(int j=0;j<v.size()-2;++j)
                            {
                                deq[v[j]]--;
                                deq[v[j+1]]--;
                                if(j%2==0)
                                {
                                    res.push_back({v[j],v[j+1]});
                                }
                            }
                            deq[v[v.size()-1]]--;
                            deq[v[v.size()-2]]--;
                            res.push_back({v[v.size()-2],v[v.size()-1]});
                            break;
                        }
                        else
                        {
                            while(true)
                            {
                            if(ban.count({x,a[x][a[x].size()-1]})==1)
                            {
                                a[x].erase(a[x].begin()+a[x].size()-1);
                            }
                            else
                            {
                                y=a[x][a[x].size()-1];
                                a[x].erase(a[x].begin()+a[x].size()-1);
                                x=y;
                                break;
                            }
                            }
                        }
                        ban.insert({v[v.size()-1],x});
                        ban.insert({x,v[v.size()-1]});
                    }
                }
                else
                {
                    ++i;
                }
            }
            int o=0;
            x=0;
            i=0;
            while(true)
            {
                v.clear();
                if(i==n)
                {
                    break;
                }
                x=i;
                while(true)
                {
                    v.push_back(x);
                    if(!(a[x]).empty())
                    {
                        while(true)
                            {
                            if(a[x].empty())
                                {
                                    break;
                                }
                            if(ban.count({x,a[x][a[x].size()-1]})==1)
                            {
                                a[x].erase(a[x].begin()+a[x].size()-1);
                            }
                            else
                            {
                                y=a[x][a[x].size()-1];
                                a[x].erase(a[x].begin()+a[x].size()-1);
                                x=y;
                                ban.insert({v[v.size()-1],x});
                                ban.insert({x,v[v.size()-1]});
                                break;
                            }
                            }
                    }
                    if(!a[x].empty())
                    {
     
                    }
                    else
                    {
                        for(int j=0;j<v.size()-1;++j)
                        {
                            if(j%2==0)
                            {
                                res.push_back({v[j],v[j+1]});
                            }
                        }
                        break;
                    }
                }
                ++i;
            }
            cout<<res.size()<<"\n";
            for(int j=0;j<res.size();++j)
            {
                cout<<res[j].first+1<<" "<<res[j].second+1<<"\n";
            }
            return 0;
        }