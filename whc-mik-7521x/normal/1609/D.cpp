#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int fa[N],siz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x;siz[x]+=siz[y];}
int n,d;
int main(){
    for(int i=1;i<N;i++)fa[i]=i,siz[i]=1;;
    scanf("%d%d",&n,&d);
    int ans=1;
    for(int i=1;i<=d;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        int xx=find(x),yy=find(y);
        if(xx!=yy)unnion(xx,yy);
        else ans++;
        priority_queue<int>q;
        for(int i=1;i<=n;i++)if(fa[i]==i)q.push(siz[i]);
        int tot=-1;
        for(int i=1;i<=ans;i++)tot+=q.top(),q.pop();
        printf("%d\n",tot);
    }
    return  0;
}