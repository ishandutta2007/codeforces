#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937 mrand(random_device());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

int deg[1005];
vector<int> g[1005];
int a[1005],tp=0;
int main()
{
    int n;
    cin >> n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ii if(deg[i]==1) a[++tp]=i;
    for(int i=1;i<=n/2;++i)
    {
        if(tp==1) return cout<<"! "<<a[1]<<endl,0;
        int u=a[tp],v=a[tp-1];
        tp-=2;
        cout<<"? "<<u<<" "<<v<<endl;
        cout.flush();
        int tmp;
        cin>>tmp;
        if(tmp == u) return cout<<"! "<<u<<endl,0;
        if(tmp == v) return cout<<"! "<<v<<endl,0;
        for(int p:g[u]) if(--deg[p] == 1) a[++tp] = p;
        for(int p:g[v]) if(--deg[p] == 1) a[++tp] = p;
    }
    cout<<"! "<<a[1]<<endl,0;
}