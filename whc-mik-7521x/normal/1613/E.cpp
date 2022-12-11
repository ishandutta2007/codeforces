#include<bits/stdc++.h>
using namespace std;
#define ak(x,y) ((x-1)*m+y)
const int N=1e6+10;
struct edge{
    int to,nex;
};
edge ed[N<<2];
int cnt,h[N],rd[N],s,n,m,a[N],vis[N];
char an[]={'.','#','L','+'};
void add(int st,int et){
    cnt++;
    ed[cnt].to=et;
    ed[cnt].nex=h[st];
    h[st]=cnt;
    rd[et]++;
}
void dfs(int u){
    if(vis[u])return;
    if(rd[u]<=1||u==s)a[u]=3;
    else return;
    vis[u]=1;
    for(int i=h[u];i;i=ed[i].nex){
        int v=ed[i].to;
        rd[v]--;
        dfs(v);
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        cnt=0;
        scanf("%d%d\n",&n,&m);
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                vis[ak(i,o)]=h[ak(i,o)]=a[ak(i,o)]=rd[ak(i,o)]=0;
                char c;
                if((c=getchar())=='#')a[ak(i,o)]=1;
                if(c=='L')s=ak(i,o);
            }
            getchar();
        }
        for(int i=1;i<n;i++){
            for(int o=1;o<=m;o++){
                if(!a[ak(i,o)]&&!a[ak(i+1,o)])add(ak(i,o),ak(i+1,o)),add(ak(i+1,o),ak(i,o));
            }
        }
        for(int i=1;i<=n;i++){
            for(int o=1;o<m;o++){
                if(!a[ak(i,o)]&&!a[ak(i,o+1)])add(ak(i,o),ak(i,o+1)),add(ak(i,o+1),ak(i,o));
            }
        }
        dfs(s);
        a[s]=2;
        for(int i=1;i<=n;i++){
            for(int o=1;o<=m;o++){
                putchar(an[a[ak(i,o)]]);
            }
            putchar('\n');
        }
    }
    return  0;
}