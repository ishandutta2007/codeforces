//template start//
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
template<typename T>
void printvector(vector<T>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<"\n";
}
void solve()
{
    int n,x,y;
    cin>>n>>x>>y;
    int extra;
    vi cnt(n+2,0),v(n),ans(n);
    vvi temp(n+2);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
        cnt[v[i]]++;
    }
    if(n==1)
    {
        if(x==0&&y==1)
            cout<<"NO"<<'\n';
        else if(x==0&&y==0)
        {
            cout<<"YES"<<'\n';
            cout<<(v[0]==1?2:1)<<'\n';
        }
        else if(x==1&&y==1)
        {
            cout<<"YES"<<'\n';
            cout<<v[0]<<'\n';
        }
        return; 
    }
    if(x==n&&y==n)
    {
        cout<<"YES"<<'\n';
        printvector(v);
        return;
    }
    y-=x;
    priority_queue<pair<int,int>> q;
    for(int i=1;i<=n+1;i++)
    {
        if(cnt[i]==0) extra=i;
        else
        {
            q.push({cnt[i],i});
        }
    }
    for(int i=0;i<=n+1;i++) cnt[i]=0;
        int X=x;
    while(x)
    {
        auto [a,b]=q.top();
        q.pop();
        cnt[b]++;
        a--;
        if(a) q.push({a,b});
        x--;
    }
    auto [temp1,temp2]=q.top();
    int least_matches=max(2*temp1-(n-X),0);
    int max_Y=n-least_matches;
    if(max_Y<y+X)
    {
        cout<<"NO"<<'\n';
        return;
    }
    int garbage=0;
    int Y=n-X-least_matches;
    for(int i=least_matches;i>0;i--)
    {
        auto [a,b]=q.top();
        q.pop();
        temp[b].pb(extra);
        a--;
        if(a) q.push({a,b});
    }
    while(Y&&q.size())
    {
        if(Y&1)
        {
            if(q.size()>=3)
            {
                auto [a,b]=q.top();
                q.pop();
                auto [c,d]=q.top();
                q.pop();
                auto [e,f]=q.top();
                q.pop();
                temp[b].pb(d);
                temp[d].pb(f);
                temp[f].pb(b);
                a--;c--;e--;
                if(a) q.push({a,b});
                if(c) q.push({c,d});
                if(e) q.push({e,f});
                Y-=3;
                continue;
            }
            /*
            else
            {
                auto [a,b]=q.top();
                q.pop();
                temp[b].pb(extra);
                a--;
                if(a) q.push({a,b});
                Y--;
                garbage++;
                continue;
            }
            */
        }
        if(q.size()>1)
        {
            auto [a,b]=q.top();
            q.pop();
            auto [c,d]=q.top();
            q.pop();
            temp[b].pb(d);
            temp[d].pb(b);
            a--;
            c--;
            if(a) q.push({a,b});
            if(c) q.push({c,d});
            Y-=2;
        }
        /*
        else
        {
            auto [a,b]=q.top();
            q.pop();
            temp[b].pb(extra);
            a--;
            if(a) q.push({a,b});
            Y-=1;
            garbage++;
        }
        */
    } 
    for(int i=0;i<n;i++)
    {
        if(cnt[v[i]])
        {
            ans[i]=v[i];
            cnt[v[i]]--;
        }
        else
        {
            if((int)temp[v[i]].size())
            {
                ans[i]=temp[v[i]].back();
                temp[v[i]].pop_back();
            }
        }
    }   
    int i=0;
    int cc=n-X-y-garbage-least_matches;
    while(cc>0)
    {
        if(v[i]!=ans[i]&&ans[i]!=extra) {ans[i]=extra;cc--;}
        i++;
    }
    cout<<"YES"<<'\n';
    printvector(ans);
        return;
}
int main()
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }   
    return 0;
}