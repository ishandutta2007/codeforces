#include <bits/stdc++.h>

using namespace std;
#define int long long
int n;
int d[14][14];
int u[(1<<14)];
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    char t;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>t;
            if(t=='0')
            d[i][j]=0;
            else
            d[i][j]=1;
        }
    }
    const int sz=(1<<n);
    vector <pair<int,int> > a[sz][n];
    for(int mask=0;mask<(sz-1);++mask)
    {
        for(int beg=0;beg<n;++beg)
        {
            if((1<<beg) & mask)
            {
                continue;
            }
            vector <pair<int,int> > ans;
            vector <pair<int,int> > v;
            vector <int> keys;
            bool h=false;
            for(int i=0;i<n;++i)
            {
                if(mask & (1<<i))
                {
                    //cout<<" i am going to "<<i<<endl;
                    h=true;
                    v=a[mask-(1<<i)][i];
                    //cout<<v.size()<<" v.size() "<<endl;
                    for(int j=0;j<v.size();++j)
                    {
                        //cout<<v[j].first<<" was "<<endl;
                        v[j].first*=2;
                        v[j].first+=(d[beg][i]);
                        if(u[v[j].first]!=0)
                        {
                            u[v[j].first]+=v[j].second;
                        }
                        else
                        {
                            //cout<<v[j].first<<" we insert "<<endl;
                            keys.push_back(v[j].first);
                            u[v[j].first]=v[j].second;
                        }
                    }
                }
            }
            for(int i=0;i<keys.size();++i)
            {
                //cout<<keys[i]<<" keys[i] "<<endl;
                ans.push_back({keys[i],u[keys[i]]});
                u[keys[i]]=0;
            }
            if(!h)
            {
                ans.push_back({0,1});
            }
            a[mask][beg]=ans;
            //cout<<mask<<" "<<beg<<" "<<ans.size()<<endl;
        }
    }
    int msk=(1<<n)-1;
    //cout<<msk<<" msk "<<endl;
    map <int,int> u1;
    vector <int> keys;
    for(int i=0;i<(1<<(n-1));++i)
    {
        int s=0;
        for(int j=0;j<(n-1);++j)
        {
            if(i & (1<<j))
            {
                s+=(1<<j);
            }
            else
            {
                s+=0;
            }
        }
        //cout<<s<<" s "<<endl;
        u1[s]=0;
        keys.push_back(s);
    }
    for(int beg=0;beg<n;++beg)
    {
        int msk1=msk-(1<<beg);
        //cout<<msk1<<" msk1 "<<beg<<" beg "<<endl;
        vector <pair<int,int> > v=a[msk1][beg];
        for(int i=0;i<v.size();++i)
        {
            //cout<<v[i].first<<" "<<v[i].second<<" banned "<<endl;
            u1[v[i].first]+=v[i].second;
        }
    }
    for(int i=0;i<keys.size();++i)
    {
        //cout<<keys[i]<<" keys[i] "<<endl;
        cout<<u1[keys[i]]<<" ";
    }
    return 0;
}