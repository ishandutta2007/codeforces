#include<bits/stdc++.h>
using namespace std;

const int maxn=200007;

int n,q,b;

bool fg[2][maxn];

void update(int u,int v,int w){
    if (fg[1-u][v-1]) b+=w;
    if (fg[1-u][v]) b+=w;
    if (fg[1-u][v+1]) b+=w;
}
int main(){
    scanf("%d%d",&n,&q);
    for (int i=1;i<=q;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        u--;
        if (fg[u][v]){
            fg[u][v]=0;
            update(u,v,-1);
        }
        else{
            fg[u][v]=1;
            update(u,v,1);
        }
        if (b) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}