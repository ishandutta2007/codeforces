#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
int a1[maxn];int a[maxn];bool used[maxn];
vector <vector<int> > cyc;
vector <pair<vector <int>,vector <int> > > res;
void go2(vector <vector <int> > v)
{
    vector <int> v1,v2;
    for(auto h:v)
    {
        for(auto h1:h)
        {
            if(h.size()!=2){
            v1.push_back(h1);v2.push_back(a[h1]);
            }
            else
            {
                v1.push_back(h1);v2.push_back(h[0]+h[1]-h1);
            }
        }
    }
    vector <int> v3=v1;vector <int> v4=v2;
    sort(v3.begin(),v3.end());sort(v4.begin(),v4.end());
    assert(v3==v4);
    for(int i=0;i<v1.size();++i) a1[v1[i]]=a[v1[i]];
    for(int i=0;i<v1.size();++i) a[v2[i]]=a1[v1[i]];
    res.push_back({v1,v2});
}
void go(vector <vector <int> > v)
{
    vector <int> v1,v2;
    for(auto h:v)
    {
        for(auto h1:h)
        {
            v1.push_back(h1);v2.push_back(a[h1]);
        }
    }
    vector <int> v3=v1;vector <int> v4=v2;
    sort(v3.begin(),v3.end());sort(v4.begin(),v4.end());
    assert(v3==v4);
    for(int i=0;i<v1.size();++i) a1[v1[i]]=a[v1[i]];
    for(int i=0;i<v1.size();++i) a[v2[i]]=a1[v1[i]];
    res.push_back({v1,v2});
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;++i) {cin>>a[i];--a[i];}
    for(int i=0;i<n;++i)
    {
        if(!used[i])
        {
            int cur=i;
            vector <int> v={cur};
            while(a[cur]!=i)
            {
                cur=a[cur];
                v.push_back(cur);
            }
            for(auto h:v) used[h]=true;
            cyc.push_back(v);
        }
    }
    int pos=cyc.size()-1;
    /*vector <int> u;
    for(int i=0;i<cyc.size();++i) if(cyc[i].size()>=2) u.push_back(cyc[i].size());
    int res1=0;
    int l[5]={0};
    for(auto h:u)
    {
        if(h%4==1 || h%4==0)
        {
            res1+=(h/4);continue;
        }
        else
        {
            res1+=(h/4);l[h%4]++;
        }
    }
    int o=min(l[2],l[3]);
    res1+=o;
    l[2]-=o;l[3]-=o;
    3 po 3
    res1+=l[3];res1+=(l[2]+1)/2;
    //for(auto h:cyc) cout<<h.size()<<' ';
    //cout<<endl;*/
    while(pos>=0)
    {
        vector <int> &h=cyc[pos];
        if(h.size()<5) {--pos;continue;}
        while(h.size()>=5)
        {
            int u=h.size()-5;
            res.push_back({{h[u],h[u+1],h[u+2],h[u+3],h[u+4]},{h[u+1],h[u+2],h[u+3],h[u+4],h[u]}});
            a1[h[u]]=a[h[u]];a1[h[u+1]]=a[h[u+1]];a1[h[u+2]]=a[h[u+2]];a1[h[u+3]]=a[h[u+3]];a1[h[u+4]]=a[h[u+4]];
            a[h[u+1]]=a1[h[u]];a[h[u+2]]=a1[h[u+1]];a[h[u+3]]=a1[h[u+2]];a[h[u+4]]=a1[h[u+3]];a[h[u]]=a1[h[u+4]];
            h.pop_back();h.pop_back();h.pop_back();h.pop_back();if(h.size()==1) h.clear();
        }
    }
    vector <vector <int> > z[5];
    for(auto h:cyc)
    {
        if(h.size()>=2)
        {
            z[h.size()].push_back(h);
        }
    }
    while(z[2].size()+z[3].size()+z[4].size()>=1)
    {
        if(z[2].size()>=1 && z[3].size()>=1)
        {
            go({z[2].back(),z[3].back()});
            z[2].pop_back();z[3].pop_back();
            continue;
        }
        if(z[3].size() && z[4].size())
        {
            go2({z[3].back(),{z[4].back()[0],z[4].back()[1]}});
            z[3].pop_back();z[4][z[4].size()-1].erase(z[4][z[4].size()-1].begin()+1);
            z[3].push_back(z[4].back());z[4].pop_back();
            continue;
        }
        if(z[3].size()>=2)
        {
            go2({z[3][z[3].size()-2],{z[3].back()[0],z[3].back()[1]}});
            z[3].erase(z[3].begin()+z[3].size()-2);z[3][z[3].size()-1].erase(z[3][z[3].size()-1].begin()+1);
            z[2].push_back(z[3].back());z[3].pop_back();
            continue;
        }
        if(z[4].size())
        {
            go({z[4].back()});z[4].pop_back();
            continue;
        }
        if(z[2].size()>=2)
        {
            go({z[2][z[2].size()-2],z[2][z[2].size()-1]});
            z[2].pop_back();z[2].pop_back();
            continue;
        }
        if(z[3].size())
        {
            go({z[3].back()});z[3].pop_back();
            continue;
        }
        if(z[2].size())
        {
            go({z[2].back()});z[2].pop_back();
            continue;
        }
        assert(false);
    }
    for(int i=0;i<n;++i) assert(a[i]==i);
    //assert(res.size()==res1);
    cout<<res.size()<<'\n';
    for(auto h:res)
    {
        cout<<h.first.size()<<'\n';
        for(auto h1:h.first) cout<<h1+1<<' ';
        cout<<'\n';
        for(auto h2:h.second) cout<<h2+1<<' ';
        cout<<'\n';
    }
    return 0;
}
/*
9
2 3 1 5 6 4 8 9 7
*/