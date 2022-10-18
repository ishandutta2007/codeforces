#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;

vector<pii> g[N];
bool used[N];
int k[N],b[N];
int val[N];
bool found_x;
int need_x;
vector<int> comp;

void dfs(int v,int my_k,int my_b)
{
    if(used[v])
    {
        if(my_k!=k[v])
        {
            int my_need_x=(b[v]-my_b)/(my_k-k[v]);
            if(found_x&&need_x!=my_need_x)
                cout<<"NO",exit(0);
            found_x=true;
            need_x=(b[v]-my_b)/(my_k-k[v]);
        }
        else if(my_b!=b[v])
            cout<<"NO",exit(0);
        return;
    }
    comp.push_back(v);
    used[v]=true;
    k[v]=my_k,b[v]=my_b;
    for(pii to:g[v])
        dfs(to.x,-my_k,to.y-my_b);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout<<fixed<<setprecision(1);

    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,2*c});
        g[b].push_back({a,2*c});
    }
    for(int i=1;i<=n;i++)
        if(!used[i])
        {
            found_x=false;
            comp.clear();
            dfs(i,1,0);
            if(!found_x)
            {
                vector<int> coords;
                for(int v:comp)
                    coords.push_back(-b[v]/k[v]);
                sort(coords.begin(),coords.end());
                need_x=coords[coords.size()/2];
            }
            for(int v:comp)
                val[v]=k[v]*need_x+b[v];
            for(int v:comp)
                for(pii to:g[v])
                    if(val[v]+val[to.x]!=to.y)
                        cout<<0/0,exit(0);
        }
    cout<<"YES\n";
    for(int i=1;i<=n;i++)
        cout<<val[i]/2.<<" ";
}