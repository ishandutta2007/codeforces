#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=1e9+7;
int fa[N],pd[N],siz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){int xx=find(x),yy=find(y);if(xx==yy)return;fa[xx]=yy;siz[yy]+=siz[xx];}
void init(int x){for(int i=0;i<=x;i++)fa[i]=i,pd[i]=0,siz[i]=1;}
int t,n,a[N],b[N],c[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        init(n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            unnion(x,a[i]);
        }
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            if(!x)continue;
            pd[find(x)]=1;
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            if(find(i)==i)ans*=pd[i]?1:siz[i]!=1?2:1;
            ans%=mod;
        }
        printf("%d\n",ans);
    }
    return  0;
}