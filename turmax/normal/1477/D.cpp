#include <bits/stdc++.h>

using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector <int> a[n];
        int deq[n];
        for(int i=0;i<n;++i) deq[i]=0;
        set <pair<int,int> > ed;
        for(int i=0;i<m;++i)
        {
            int x,y;
            cin>>x>>y;
            x--;y--;
            a[x].push_back(y);a[y].push_back(x);
            deq[x]++;deq[y]++;
            ed.insert({x,y});ed.insert({y,x});
        }
        int p[n],q[n];
        set <pair<int,int> > o;
        for(int i=0;i<n;++i) o.insert({-deq[i],i});
        int sz=n;
        int curr=1;
        set <int> ok;
        for(int i=0;i<n;++i) ok.insert(i);
        while(sz!=0)
        {
            pair <int,int> h=(*o.begin());
            if((-h.first)==(sz-1))
            {
                p[h.second]=curr;q[h.second]=curr;
                ++curr;
                sz--;
                o.erase(o.begin());
                ok.erase(h.second);
                for(auto h:ok)
                {
                    o.erase({-deq[h],h});
                    deq[h]--;
                    o.insert({-deq[h],h});
                }
            }
            else
            {
                int v=h.second;
                //cout<<v<<" v "<<endl;
                int v2=(-1);
                for(auto h:ok)
                {
                    if(h!=v && !ed.count({v,h}))
                    {
                        v2=h;
                        break;
                    }
                }
                //cout<<v2<<" v2 "<<endl;
                vector <int> z;
                z.push_back(v);
                if(deq[v]==(sz-2))
                {
                for(auto h:ok)
                {
                    if(h!=v && h!=v2 && !ed.count({v2,h}) && deq[h]==(sz-2))
                    {
                        z.push_back(h);
                    }
                }
                }
                else if(deq[v]==(sz-3))
                {
                for(auto h:ok)
                {
                    if(h!=v && h!=v2 && !ed.count({v2,h}) && !ed.count({v,h}) && deq[h]==(sz-3))
                    {
                        z.push_back(h);
                    }
                }
                }
                for(int i=0;i<z.size();++i)
                {
                    p[z[i]]=(curr+i);q[z[i]]=(curr+i+1);
                }
                p[v2]=(curr+z.size());q[v2]=curr;
                z.push_back(v2);
                //cout<<" z "<<endl;
                //for(auto h:z) cout<<h<<' ';
                //cout<<endl;
                curr+=z.size();
                for(auto h:z) {o.erase({-deq[h],h});ok.erase(h);}
                sz=ok.size();
                for(auto h:z)
                {
                    for(auto i:a[h])
                    {
                        if(ok.count(i))
                        {
                            o.erase({-deq[i],i});
                            deq[i]--;
                            o.insert({-deq[i],i});
                        }
                    }
                }
            }
        }
        for(int i=0;i<n;++i) cout<<p[i]<<' ';
        cout<<endl;
        for(int i=0;i<n;++i) cout<<q[i]<<' ';
        cout<<endl;
    }
    return 0;
}