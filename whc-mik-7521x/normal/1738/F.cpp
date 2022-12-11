#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int deg[N],vis[N],a[N],col[N],t,n,ct;
int main(){
    scanf("%d",&t);
    while(t--){
        ct=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&deg[i]),a[i]=i,vis[i]=0,col[i]=0;
        stable_sort(a+1,a+n+1,[&](int k1,int k2){return deg[k1]>deg[k2];});
        for(int i=1;i<=n;i++){
            int x=a[i];
            if(vis[x])continue;
            vis[x]=1;
            vector<int>vec(1,x);
            for(int o=0;o<deg[x];o++){
                printf("? %d\n",x);
                fflush(stdout);
                int v;
                scanf("%d",&v);
                vis[v]=1;
                if(col[v]){
                    for(int k:vec)col[k]=col[v];
                    break;
                }
                vec.push_back(v);
            }
            if(!col[x]){
                ct++;
                for(int k:vec)col[k]=ct;
            }
        }
        printf("! ");
        for(int i=1;i<=n;i++)assert(vis[i]),printf("%d ",col[i]);
        puts("");
        fflush(stdout);
    }
    return 0;
}