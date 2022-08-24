#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdio>
using namespace std;
struct point{
    int x,y,a,b;
    void scan(){
        scanf("%d%d%d%d",&x,&y,&a,&b);
    }   
    void rev(){
        int k1=x-a,k2=y-b;
        x=a-k2; y=b+k1;
    }
}x[4];
int pd[4],ans,y[4],d[4];
int pdd(point k1,point k2,point k3,point k4){
    return (k2.x-k1.x)*(k4.x-k3.x)+(k2.y-k1.y)*(k4.y-k3.y);
}
#define sqr(x) ((x)*(x))
int dis(point k1,point k2){
    return sqr(k1.x-k2.x)+sqr(k1.y-k2.y);
}
int dfs2(int k,int kk){
    if (k==4){
        for (int i=0;i<4;i++){
            int k1=((i+1)%4); d[y[i]]=dis(x[y[k1]],x[y[i]]);
        }
        if (d[0]==0) return 0;
        for (int i=0;i<4;i++){
            int k1=((i+1)%4); if (d[y[i]]!=d[y[k1]]) return 0;
        }
        for (int i=0;i<=3;i++){
            int pre=(i+3)%4,next=(i+1)%4;
            if (pdd(x[y[i]],x[y[pre]],x[y[i]],x[y[next]])) return 0;
        }
        return 1;
    }
    for (int i=0;i<=3;i++)
        if (pd[i]==0){
            y[k]=i; pd[i]=1; int k1=dfs2(k+1,kk); if (k1) return 1; pd[i]=0;
        }
    return 0;
}
int check(int k){
    memset(pd,0x00,sizeof pd);
    return dfs2(0,k);
}
void dfs(int k1,int k2){
    if (k1==4){
        if (check(k2)){
            ans=min(ans,k2); 
        }
        return;
    }
    for (int i=0;i<=3;i++){
        dfs(k1+1,k2+i); x[k1].rev();
    }
}
int main(){
    int n; scanf("%d",&n);
    for (;n;n--){
        for (int i=0;i<4;i++) x[i].scan();
        ans=20; dfs(0,0);
        if (ans==20)printf("-1\n"); else printf("%d\n",ans);
    }
    return 0;
}