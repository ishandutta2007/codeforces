#include<bits/stdc++.h>
#define ULL unsigned long long
#define F first
#define S second
#define pb push_back
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define rep1(i,n) for(int i=1;i<=(int)(n);++i)
#define range(a) a.begin(), a.end()
#define PI pair<int,int>
#define VI vector<int,int>

using namespace std;

typedef long long ll;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/* DSU
int p[maxn]; // rep1(i,n) p[i]=i;

int find(int u){
    if (p[u]==u) return u;
    return p[u]=find(p[u]);
}

bool unite(int u,int v){
    int pu=find(u),pv=find(v);
    p[pu]=pv;
    return pu!=pv;
}
*/

const int maxn=1000007;
int n,m;
string s[maxn];
bool vis[maxn<<2];
int d[maxn<<2],td[maxn<<2];

queue<int> init(){
    memset(vis,0,sizeof(vis));
    memset(d,0,sizeof(d));
    queue<int> q;
    while (q.size()) q.pop();
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (s[i][j]=='.'){
                q.push(i*m+j);
                d[i*m+j]=0;
                vis[i*m+j]=1;
            }
        }
    }
    for (int i=0;i<n;++i){
        if (s[i][0]=='X'){
            q.push(i*m);
            d[i*m]=1;
            vis[i*m]=1;
        }
        if (s[i][m-1]=='X'){
            q.push(i*m+m-1);
            d[i*m+m-1]=1;
            vis[i*m+m-1]=1;
        }
    }
    for (int i=0;i<m;++i){
        if (s[0][i]=='X'){
            q.push(i);
            d[i]=vis[i]=1;
        }
        if (s[n-1][i]=='X'){
            q.push((n-1)*m+i);
            d[(n-1)*m+i]=vis[(n-1)*m+i]=1;
        }
    }
    return q;
}

void bfs(queue<int> q){
    while (q.size()){
        int t=q.front(); q.pop();
        int x=t/m,y=t%m;
        for (int i=-1;i<=1;++i){
            for (int j=-1;j<=1;++j){
                if (x+i>=0&&x+i<n&&y+j>=0&&y+j<m&&!vis[(x+i)*m+y+j]){
                    vis[(x+i)*m+y+j]=1;
                    d[(x+i)*m+y+j]=d[t]+1;
                    q.push((x+i)*m+y+j);
                }
            }
        }
    }
}

bool check(int t){
    queue<int> q;
    while (q.size()) q.pop();
    memset(vis,0,sizeof(vis));
    for (int i=0;i<n*m;++i){
        d[i]=1e8;
    }
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (td[i*m+j]>t){
                d[i*m+j]=0;
                vis[i*m+j]=1;
                q.push(i*m+j);
            }
        }
    }
    bfs(q);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (s[i][j]=='X'&&d[i*m+j]>t) return 0;
        }
    }
    return 1;
}

int mid_search(int l,int r){
    if (l==r) return l;
    int md=(l+r)>>1;
    if (check(md+1)) return mid_search(md+1,r);
    else return mid_search(l,md);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for (int i=0;i<n;++i){
        cin>>s[i];
    }
    bfs(init());
    for (int i=0;i<n*m;++i){
        td[i]=d[i];
    }
    int ans=mid_search(0,1e6);
    printf("%d\n",ans);
    for (int i=0;i<n;++i){
        for (int j=0;j<m;++j){
            if (td[i*m+j]>ans) printf("X");
            else printf(".");
        }
        printf("\n");
    }
    return 0;
}