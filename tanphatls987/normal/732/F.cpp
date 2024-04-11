#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> ii;
typedef long long ll;

#define X first
#define Y second

const int N=4e5+10;
const ll inf=4e18;

int n,n1,m;

int gr[N];
int v[N][2];
vector <int> e[N],imp[N];

int mark[N];
void DFSor(int x){
    for(auto i:e[x]) if (!mark[i]){
        mark[i]=1;
        int y=v[i][0]+v[i][1]-x;
        if (x!=v[i][0]) swap(v[i][0],v[i][1]);
        DFSor(y);
    }
}
stack <int> s;
int low[N],num[N];
void DFS(int x){
    static int n2=0;
    s.push(x);
    low[x]=num[x]=++n2;
    for(auto i:e[x]){
        int y=v[i][1];
        if (!num[y]) DFS(y);
        low[x]=min(low[x],low[y]);
    }
    if (low[x]>=num[x]){
        imp[++n1].push_back(x);
        while (s.top()!=x){
            imp[n1].push_back(s.top());
            s.pop();
        }
        s.pop();
    }
}
void prepare(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        v[i][0]=x;v[i][1]=y;
        e[x].push_back(i);
        e[y].push_back(i);
    }
    DFSor(1);
    for(int i=1;i<=m;i++) e[i].clear();
    for(int i=1;i<=m;i++)
        e[v[i][0]].push_back(i);
    DFS(1);
    for(int i=1;i<=n1;i++)
        for(auto j:imp[i]) gr[j]=i;
}

vector <int> cd[N];
int cpa[N],cq[N];
void BFS(int st){
    int top=1,bot=1;
    cq[1]=st;
    while (top<=bot){
        int x=cq[top++];
        for(auto y:cd[x]) if (y!=cpa[x]){
            cpa[y]=x;
            cq[++bot]=y;
        }
    }
}
void solve(){
    int ans=1;
    for(int i=1;i<=n1;i++) if (imp[i].size()>imp[ans].size())
        ans=i;
    for(int i=1;i<=m;i++)
        if (gr[v[i][0]]!=gr[v[i][1]]){
            int x=gr[v[i][0]],y=gr[v[i][1]];
            cd[x].push_back(y);
            cd[y].push_back(x);
        }
    BFS(ans);
    for(int i=1;i<=m;i++)
        if (gr[v[i][0]]!=gr[v[i][1]]){
            int x=gr[v[i][0]],y=gr[v[i][1]];
            if (cpa[y]==x) swap(v[i][0],v[i][1]);
        }
//    for(int i=1;i<=n1;i++){
//        cout<<"? ";
//        for(auto j:imp[i]) cout<<j<<" ";
//        cout<<'\n';
//    }
    printf("%d\n",imp[ans].size());
    for(int i=1;i<=m;i++) printf("%d %d\n",v[i][0],v[i][1]);
}
int main(){
    prepare();
    solve();
}