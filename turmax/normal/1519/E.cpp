#include <bits/stdc++.h>

using namespace std;
#define int long long
typedef pair <int,int> rat;
const int maxn=4e5+5;
vector <pair<int,int> > g[maxn];
bool used[maxn];
vector <int> z[maxn];
set <int> use;
void dfs(int x,int pr1=(-1))
{
    //cout<<x<<" x "<<pr1<<" pr1 "<<endl;
    used[x]=true;
    for(auto l:g[x])
    {
        int v=l.first;
        if(!used[v])
        {
            dfs(v,x);
            //cout<<l.second<<" l.second "<<endl;
            if(use.count(l.second)) continue;
            use.insert(l.second);
            if(z[v].size()%2==1)
            {
                z[v].push_back(l.second);
            }
            else
            {
                //cout<<x<<" tyhrge "<<endl;
                z[x].push_back(l.second);
            }
        }
        else if(v!=pr1)
        {
            //cout<<l.second<<" l.second "<<endl;
            if(use.count(l.second)) continue;
            use.insert(l.second);
            z[x].push_back(l.second);
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    pair <pair<int,int>,pair<int,int> > a[n];
    vector <pair<int,int> > mom;
    for(int i=0;i<n;++i)
    {
    int a1,b,c,d;
    cin>>a1>>b>>c>>d;
    int x=(a1+b)*d;int y=(b*c);
    int h=__gcd(x,y);
    x/=h;y/=h;
    a[i].first={x,y};
    mom.push_back({x,y});
    x=(a1*d);y=b*(c+d);
    h=__gcd(x,y);
    x/=h;y/=h;
    a[i].second={x,y};
    mom.push_back({x,y});
    }
    sort(mom.begin(),mom.end());
    pair <int,int> b[n];
    for(int i=0;i<n;++i)
    {
        b[i].first=lower_bound(mom.begin(),mom.end(),a[i].first)-mom.begin();
        b[i].second=lower_bound(mom.begin(),mom.end(),a[i].second)-mom.begin();
        //cout<<b[i].first<<' '<<b[i].second<<endl;
        g[b[i].first].push_back({b[i].second,i});
        g[b[i].second].push_back({b[i].first,i});
    }
    for(int i=0;i<mom.size();++i)
    {
        if(!used[i]) dfs(i);
    }
    vector <pair<int,int> > v;
    for(int i=0;i<mom.size();++i)
    {
        vector <int> h=z[i];
        /*for(auto r:h)
        {
            cout<<r<<' ';
        }
        cout<<endl;*/
        for(int i=0;i<h.size();i+=2)
        {
            if((i+2)>h.size()) break;
            v.push_back({h[i],h[i+1]});
        }
    }
    cout<<v.size()<<endl;
    for(auto h:v) cout<<h.first+1<<' '<<h.second+1<<endl;
    return 0;
}