#include <stdio.h>
#include <vector>
#include <algorithm>
#define pb push_back
#define mp make_pair
#define N 500500
using namespace std;
vector<int>g[N];
int d[N],u[N],n,m,a[7][7],x,y,w[N];
vector<int>r,o;
vector<pair<int,int> >s,e;
void rec(int x,int t){
    if (t==m){
        for (int i=0;i<m;i++)printf("%d %d\n",1+s[i].first,1+s[i].second);
        exit(0);
    }
    if (x==e.size())return;
    rec(x+1,t);
    if ((d[e[x].first]==2)||(d[e[x].second]==2))return;
    ++d[e[x].first];++d[e[x].second];s.pb(e[x]);
    rec(x+1,t+1);
    --d[e[x].first];--d[e[x].second];s.pop_back();
}
void dfs(int x){
    u[x]=1;
    o.pb(x);
    for (int i=0;i<g[x].size();i++)
        if (!u[g[x][i]])dfs(g[x][i]);
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        --x;--y;
        g[x].pb(y);
        g[y].pb(x);
        w[x]++;w[y]++;
        if (n<=6){a[x][y]=1;a[y][x]=1;}
    }
    if (n<=6){
        for (int i=0;i<n;i++)
            for (int j=i+1;j<n;j++)if(!a[i][j])e.pb(mp(i,j));
        rec(0,0);
        puts("-1");
        exit(0);
    }
    for (int i=0;i<n;i++)
        if ((!u[i])&&(w[i]<2)){
            o.clear();
            dfs(i);
            for (int j=0;j<((x=o.size())+1)/2;j++){
                r.pb(o[j]);
                if (x-1-j>j)r.pb(o[x-1-j]);
            }
        }
    for (int i=0;i<n;i++)
        if (!u[i]){
            o.clear();
            dfs(i);
            for (int j=0;j<((x=o.size())+1)/2;j++){
                r.pb(o[j]);
                if (x-1-j>j)r.pb(o[x-1-j]);
            }
        }
    for (int i=0;i<m;i++)printf("%d %d\n",1+r[i],1+r[(i+3)%n]);
}