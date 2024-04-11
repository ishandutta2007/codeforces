#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N = 1e6+9;
int n,m,q,f[N];
int find(int x){return x==f[x]?x:(f[x]=find(f[x]));}

int main(){
    scanf("%d%d",&n,&m);
    scanf("%d",&q);
    for(int i=1;i<=n+m;i++) f[i]=i;
    for(int i=1;i<=q;i++){
        int u,v;scanf("%d%d",&u,&v);
        u=find(u),v=find(n+v);
        if(u!=v) f[u]=v;
    }
    int ans=-1;
    for(int i=1;i<=n+m;i++) if(find(i)==i) ans++;
    printf("%d\n",ans);
    return 0;
}