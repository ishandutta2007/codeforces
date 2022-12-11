#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int t,n;
int fa[N],siz[N];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){int xx=find(x),yy=find(y);if(xx==yy)return;fa[xx]=yy;siz[yy]+=siz[xx];}
void init(int x){for(int i=0;i<=x;i++)fa[i]=i,siz[i]=1;}
int a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        init(n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)unnion(a[i],b[i]);
        int tot=0;
        for(int i=1;i<=n;i++){
            if(find(i)==i)tot+=(siz[i]>>1);
        }
        printf("%lld\n",2ll*(n-tot)*tot);
    }
    return  0;
}