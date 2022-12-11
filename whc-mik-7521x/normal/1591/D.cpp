#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,t,fa[N],siz[N],pd[N],cnt[5];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void unnion(int x,int y){fa[y]=x,siz[x]+=siz[y];}
struct node{
    int num,val;
    bool operator<(const node b)const{
        return val==b.val?num<b.num:val<b.val;
    }
}a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)pd[i]=0;
        memset(cnt,0,sizeof cnt);
        int ans=0;
        for(int i=1;i<=n;i++){
            fa[i]=i,siz[i]=1;
            scanf("%d",&a[i].val);
            a[i].num=i;
            if(!pd[a[i].val])pd[a[i].val]=1;
            else ans=1;
        }
        if(ans){puts("YES");continue;}
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            int xx=find(i),yy=find(a[i].num);
            if(xx!=yy){
                unnion(xx,yy);
            }
        }
        for(int i=1;i<=n;i++){
            if(fa[i]==i&&siz[i]!=1)(cnt[(siz[i]-2)%2+2]++);
        }
        puts(cnt[2]%2!=0?"NO":"YES");
    }
    return  0;
}