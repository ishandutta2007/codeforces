#include <bits/stdc++.h>

using namespace std;


const int N=2e2+10,M=N*N;

int n,m;
int v[M][2];

int ma[N][N];
vector <int> e[N];
int m1;
void add_edge(int x,int y){
    ++m1;
    v[m1][0]=x;v[m1][1]=y;
    e[x].push_back(m1);
    e[y].push_back(m1);
    ma[x][y]=ma[y][x]=m1;
}
int s[M],he[M],h[N];
void DFS(int x){
    s[1]=x;
    int top=1;
    while (top){
        int x=s[top];
        if (h[x]==e[x].size()){
            if (top){
                int idx=ma[x][s[top-1]];
                he[idx]=(x==v[idx][1])+1;
            }
            top--;
            continue;
        }
        int idx=e[x][h[x]++];
        if (he[idx]) continue;
        he[idx]=-1;
        s[++top]=v[idx][0]+v[idx][1]-x;
    }
}

int imp[N];
void prepare(){
    scanf("%d%d",&n,&m);
    ///
    m1=0;
    for(int i=1;i<=n;i++) e[i].clear();
    for(int i=1;i<=m;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
    }
    int n1=0;
    for(int i=1;i<=n;i++) if (e[i].size()&1) imp[++n1]=i;
    for(int i=1;i<n1;i+=2) add_edge(imp[i],imp[i+1]);

    memset(h,0,sizeof(h));
    memset(he,0,sizeof(he));
    for(int i=1;i<=n;i++) if (!h[i]) DFS(i);
    printf("%d\n",n-n1);
}
void solve(){
    for(int i=1;i<=m;i++) {
        if (he[i]==2) swap(v[i][0],v[i][1]);
        printf("%d %d\n",v[i][0],v[i][1]);
    }
}
int main(){
    int test;
    scanf("%d",&test);
    while (test--){
        prepare();
        solve();
    }
}