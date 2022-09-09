#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m, ans;
vector<int> lis[300100];

vector<int> com;
int vis[300100];
int tra[300100];
void dfs(int here, int tt) {
    int i;
    vis[here] = tt;
    com.push_back(here);
    for (int &there : lis[here]) {
        if (vis[there]==tt)continue;
        dfs(there,tt);
    }
}

int par[300100];
int dis[300100];
void bfs(int st=0) {
    int i;
    for (i=0;i<n;i++) dis[i] = par[i] = -1;
    queue<int> q;
    q.push(st);
    dis[st] = 0;
    par[st] = -2;
    if (st) {
        par[0] = -2;
    }
    while(!q.empty()) {
        int here = q.front(); q.pop();
        for (int &there : lis[here]) {
            if (~par[there]) continue;
            par[there] = here;
            dis[there] = dis[here]+1;
            q.push(there);
        }
    }
    if (st) return;
    if (~par[n-1]) {
        int cur = n-1;
        while(cur>=0) {
            tra[ans++] = cur;
            cur = par[cur];
        }
        reverse(tra,tra+ans);
        ans--;
    }
    else ans = 987654321;
}

int unf[300100];
int sz[300100];
int getp(int a) {
    return (unf[a]==a)?a:(unf[a]=getp(unf[a]));
}
void uni(int a, int b) {
    a = getp(a); b = getp(b);
    if (a==b) return;
    sz[a] += sz[b];
    unf[b] = a;
}

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    bfs();
    dfs(0,1);
    if (com.size()!=lis[0].size()+1) {
        if (ans>4) {
            ans = 4;
            int go = -1;
            for (int &t:com) {
                if (dis[t]==2) {
                    go = t;
                    break;
                }
            }
            printf("4\n1 %d %d 1 %d\n",par[go]+1,go+1,n);
            return 0;
        }
        printf("%d\n",ans);
        for (int j=0;j<=ans;j++) printf("%d ",tra[j]+1);
        printf("\n");
        return 0;
    }
    if (ans<=5) {
        printf("%d\n",ans);
        for (int j=0;j<=ans;j++) printf("%d ",tra[j]+1);
        printf("\n");
        return 0;
    }
    for (i=0;i<n;i++) unf[i] = i;
    for (i=0;i<n;i++) sz[i] = 1;
    for (i=1;i<n;i++) {
        for (int &t :lis[i]) {
            if (!t) continue;
            uni(t,i);
        }
    }
    for (i=0;i<n;i++){
        //printf("%d : %d, %d\n",i+1,getp(i)+1,sz[getp(i)]);
    }
    for (i=1;i<n;i++) {
        if (!vis[i]) continue;
        if (lis[i].size()==sz[getp(i)]) continue;
        vis[0] = 2;
        com.clear();
        bfs(i);
        int go = -1;
        for (int j=0;j<n;j++) {
            if (dis[j]==2) {
                go=j;
                break;
            }
        }
        printf("5\n1 %d %d %d %d %d\n",i+1,par[go]+1,go+1,i+1,n);
        return 0;
    }

    if (ans>n+1000) {
        printf("-1\n");
        return 0;
    }
        printf("%d\n",ans);
        for (int j=0;j<=ans;j++) printf("%d ",tra[j]+1);
        printf("\n");

    return 0;
}