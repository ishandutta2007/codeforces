#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

ll fpow(ll a,ll b,ll mod)
{
    ll ret = 1;
    while(b){if(b&1) ret=ret*a%mod;a=a*a%mod;b>>=1;}
    return ret;
}

unordered_map<int,int> vis,lst;
unordered_map<int, int> vis2, lst2;

int main()
{
    int u,v,p;
    cin>>u>>v>>p;
    queue<int> q;
    q.push(u);
    vis[u]=1;
    queue<int> q2;
    q2.push(v);
    vis2[v] = 1;
    while(1)
    {
        int x=q.front();q.pop();
        if(vis2[x])
        {
            vector<int> ans2;
            int x2 = x;
            while(x2 != v)
            {
                int last = lst2[x2];
                if((last+1)%p == x2) ans2.push_back(2);
                else if((last+p-1)%p == x2) ans2.push_back(1);
                else ans2.push_back(3);
                x2 = lst2[x2];
            }
            vector<int> ans;
            while(x != u)
            {
                int last = lst[x];
                if((last+1)%p == x) ans.push_back(1);
                else if((last+p-1)%p==x) ans.push_back(2);
                else ans.push_back(3);
                x = lst[x];
            }
            reverse(all(ans));
            cout << ans.size() + ans2.size() << endl;
            for(int i : ans) cout << i << " ";
            for(int i : ans2) cout << i << " ";
            return 0;
        }
        if(x == v)
        {
            vector<int> ans;
            while(v != u)
            {
                int last = lst[v];
                if((last+1)%p == v) ans.push_back(1);
                else if((last+p-1)%p==v) ans.push_back(2);
                else ans.push_back(3);
                v = lst[v];
            }
            cout << ans.size() << endl;
            reverse(all(ans));
            for(int i : ans) cout << i << " ";cout << endl;
            return 0;
        }
        int nxt;
        nxt = (x+1)%p;
        if(!vis[nxt])
        {
            vis[nxt] = 1;
            lst[nxt] = x;
            q.push(nxt);
        }
        nxt = (x+p-1)%p;
        if(!vis[nxt])
        {
            vis[nxt] = 1;
            lst[nxt] = x;
            q.push(nxt);
        }
        nxt = fpow(x,p-2,p);
        if(!vis[nxt])
        {
            vis[nxt] = 1;
            lst[nxt] = x;
            q.push(nxt);
        }
        
        x = q2.front(); q2.pop();
        if(vis[x])
        {
            vector<int> ans2;
            int x2 = x;
            while(x2 != v)
            {
                int last = lst2[x2];
                if((last+1)%p == x2) ans2.push_back(2);
                else if((last+p-1)%p == x2) ans2.push_back(1);
                else ans2.push_back(3);
                x2 = lst2[x2];
            }
            vector<int> ans;
            while(x != u)
            {
                int last = lst[x];
                if((last+1)%p == x) ans.push_back(1);
                else if((last+p-1)%p==x) ans.push_back(2);
                else ans.push_back(3);
                x = lst[x];
            }
            reverse(all(ans));
            cout << ans.size() + ans2.size() << endl;
            for(int i : ans) cout << i << " ";
            for(int i : ans2) cout << i << " ";
            return 0;
        }
        nxt = (x+1)%p;
        if(!vis2[nxt])
        {
            vis2[nxt] = 1;
            lst2[nxt] = x;
            q2.push(nxt);
        }
        nxt = (x+p-1)%p;
        if(!vis2[nxt])
        {
            vis2[nxt] = 1;
            lst2[nxt] = x;
            q2.push(nxt);
        }
        nxt = fpow(x,p-2,p);
        if(!vis2[nxt])
        {
            vis2[nxt] = 1;
            lst2[nxt] = x;
            q2.push(nxt);
        }
    }
}