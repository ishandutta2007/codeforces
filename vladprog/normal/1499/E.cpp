#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1010,MOD=998244353;

vector<int> g[2*N*N];
int dp[2*N*N];

int xy(int i,int j)
{
    return i*N+j;
}
int yx(int j,int i)
{
    return i*N+j+N*N;
}
string decode(int v)
{
    stringstream ss;
    if(v<N*N)
        ss<<"x"<<v/N<<"y"<<v%N;
    else
    {
        v%=N*N;
        ss<<"y"<<v%N<<"x"<<v/N;
    }
    string s;
    ss>>s;
    return s;
}
void add(int u,int v)
{
//    cout<<decode(u)<<" -> "<<decode(v)<<"\n";
    g[u].push_back(v);
}
void add(int u,int v,char a,char b)
{
//    cout<<a<<" "<<b<<"\n";
    if(b!='_'&&a!=b)
        add(u,v);
}

int dfs(int v)
{
    int&ans=dp[v];
    if(ans)
        return ans;
    ans=1;
    for(int to:g[v])
        ans=(ans+dfs(to))%MOD;
    return ans;
}

int lenx[N],leny[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string x,y;
    cin>>x>>y;
    int n=x.size(),m=y.size();
    lenx[0]=1;
    for(int i=1;i<n;i++)
        lenx[i]=(x[i]==x[i-1]?1:lenx[i-1]+1);
    leny[0]=1;
    for(int j=1;j<m;j++)
        leny[j]=(y[j]==y[j-1]?1:leny[j-1]+1);
    x+="_";
    y+="_";
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            add(xy(i,j),yx(j,i+1),y[j],x[i+1]);
            add(xy(i,j),xy(i,j+1),y[j],y[j+1]);
            add(yx(j,i),yx(j,i+1),x[i],x[i+1]);
            add(yx(j,i),xy(i,j+1),x[i],y[j+1]);
        }
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(x[i]!=y[j])
                ans=(ans+
                     dfs(xy(i,j))*lenx[i]+
                     dfs(yx(j,i))*leny[j])%MOD;
    cout<<ans;
}