#include <bits/stdc++.h>

using namespace std;
#define int long long
pair<string,vector <pair<int,int> > > go(string s)
{
    int n=s.size();
    vector <pair<int,int> > v;
    for(int i=0;i<(n-1);++i)
    {
        if(s[i]=='R' && s[i+1]=='L')
        {
            v.push_back({i,i+1});
        }
    }
    for(auto h:v)
    {
        swap(s[h.first],s[h.second]);
    }
    //cout<<v.size()<<" size "<<endl;
    return {s,v};
}
vector <vector <pair<int,int> > > f(string s)
{
    vector <vector<pair<int,int> > > l;
    while(true)
    {
        pair<string,vector <pair<int,int> > > u=go(s);
        if(u.first==s)
        {
            return l;
        }
        else
        {
            //cout<<u.second.size()<<" push back "<<endl;
            l.push_back(u.second);
            s=u.first;
        }
    }
    return l;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector <vector <pair<int,int> > > h=f(s);
    /*cout<<h.size()<<endl;
    for(int i=0;i<h.size();++i)
    {
        cout<<h[i].size()<<endl;
        for(auto o:h[i])
        {
            cout<<o.first<<' '<<o.second<<endl;
        }
    }*/
    int sum=0;
    for(auto v:h)
    {
        sum+=v.size();
    }
    if(h.size()>k || sum<k)
    {
        cout<<(-1);
        return 0;
    }
    int l=h.size()-1;
    vector <pair<int,int> > res;
    while((res.size()+h.size())<k)
    {
        if(h[l].size()==1)
        {
            res.push_back(h[l][0]);
            l--;
            h.pop_back();
            continue;
        }
        pair <int,int> o=h[l].back();
        res.push_back(o);
        h[l].pop_back();
    }
    reverse(res.begin(),res.end());
    //cout<<" gfbdnj "<<endl;
    for(int i=0;i<h.size();++i)
    {
        cout<<h[i].size()<<' ';
        for(int j=0;j<h[i].size();++j)
        {
            cout<<min(h[i][j].first,h[i][j].second)+1<<' ';
        }
        cout<<'\n';
    }
    for(auto h1:res)
    {
        cout<<1<<' ';
        cout<<min(h1.first,h1.second)+1<<'\n';
    }
    return 0;
}