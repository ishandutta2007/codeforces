#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=510;

int p[N],ans[N][N];
int cnt[N];
set<pii> adj[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    #define add(c,x,y) if(1<=(y)&&(y)<=(x)&&(x)<=n&&!ans[x][y]) adj[c].insert({(x),(y)})
    #define del(c,x,y) adj[c].erase({(x),(y)})
    #define ok(c) (cnt[c]<c&&adj[c].size()==1)
    #define check(c) if(ok(c)) q.push(c)
    queue<int> q;
    for(int i=1;i<=n;i++)
        cin>>p[i];
    for(int i=1;i<=n;i++)
    {
        cnt[p[i]]=1;
        ans[i][i]=p[i];
        add(p[i],i-1,i);
        add(p[i],i+1,i);
        add(p[i],i,i-1);
        add(p[i],i,i+1);
        check(p[i]);
    }
    while(!q.empty())
    {
        int c=q.front();
        q.pop();
//        cout<<c<<"\n";
        if(!ok(c))
            continue;
        auto[x,y]=*adj[c].begin();
//        cout<<x<<" "<<y<<"\n";
        if(ans[x][y])
            continue;
//        cout<<"add\n";
        ans[x][y]=c;
        cnt[c]++;
        add(c,x-1,y);
        add(c,x+1,y);
        add(c,x,y-1);
        add(c,x,y+1);
        del(ans[x-1][y],x,y);
        del(ans[x+1][y],x,y);
        del(ans[x][y-1],x,y);
        del(ans[x][y+1],x,y);
        check(ans[x-1][y]);
        check(ans[x+1][y]);
        check(ans[x][y-1]);
        check(ans[x][y+1]);
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<i<<"("<<cnt[i]<<"): ";
//        for(auto[x,y]:adj[i])
//            cout<<"("<<x<<","<<y<<") ";
//        cout<<"\n";
//    }
    for(int i=1;i<=n;i++,cout<<"\n")
        for(int j=1;j<=i;j++)
            cout<<ans[i][j]<<" ";
}