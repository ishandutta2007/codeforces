#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100;
#define no(x) (N+(x))

int l[N];
vector<int> s[N];
vector<int> g[2*N];
vector<int> r[2*N];
vector<int> ord;
bool used[2*N];
int comp[2*N];

void dfs1(int v)
{
    if(used[v])
        return;
    used[v]=true;
    for(int to:g[v])
        dfs1(to);
    ord.push_back(v);
//    cout<<"ord: "<<v<<"\n";
}

void dfs2(int v,int c)
{
    if(comp[v])
        return;
    comp[v]=c;
    for(int from:r[v])
        dfs2(from,c);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>l[i];
        s[i].resize(l[i]+1);
        for(int j=0;j<l[i];j++)
            cin>>s[i][j];
    }
    for(int i=1;i<=n-1;i++)
        for(int j=0;j<min(l[i],l[i+1])+1;j++)
        {
            int x=s[i][j],y=s[i+1][j];
            if(x==0)
                break;
            if(y==0)
                cout<<"No",exit(0);
            if(x<y)
//                cout<<x<<" -> "<<y<<"\n",
//                cout<<y<<"' -> "<<x<<"'\n",
                g[x].push_back(y),
                g[no(y)].push_back(no(x)),
                r[y].push_back(x),
                r[no(x)].push_back(no(y));
            else if(x>y)
//                cout<<x<<" -> "<<x<<"'\n",
//                cout<<y<<"' -> "<<y<<"\n",
                g[x].push_back(no(x)),
                g[no(y)].push_back(y),
                r[no(x)].push_back(x),
                r[y].push_back(no(y));
            else
                continue;
            break;
        }
    for(int i=1;i<=m;i++)
        dfs1(i),
        dfs1(no(i));
    reverse(ord.begin(),ord.end());
    int cnt=0;
    for(int v:ord)
        if(!comp[v])
            dfs2(v,++cnt);
//    for(int i=1;i<=m;i++)
//        cout<<comp[i]<<" ";
//    cout<<"\n";
//    for(int i=1;i<=m;i++)
//        cout<<comp[no(i)]<<" ";
//    cout<<"\n";
    for(int i=1;i<=m;i++)
        if(comp[i]==comp[no(i)])
            cout<<"No",exit(0);
    vector<int> ans;
    for(int i=1;i<=m;i++)
        if(comp[i]<comp[no(i)])
            ans.push_back(i);
    cout<<"Yes\n"<<ans.size()<<"\n";
    for(int x:ans)
        cout<<x<<" ";
}