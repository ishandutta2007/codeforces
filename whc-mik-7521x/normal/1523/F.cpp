#include<bits/stdc++.h>
using namespace std;
const int N=1e2+5;
int lg[1<<14],dp1[N][1<<14],dp2[N][1<<14],n,m,fx[N],fy[N],dis[N][1<<14],dt[N][1<<14];
struct tsk{
    int x,y,t;
    bool operator<(const tsk b)const{
        return t<b.t;
    }
}a[N];
int calc1(int x,int y){
    return abs(fx[x]-fx[y])+abs(fy[x]-fy[y]);
}
int calc2(int x,int y){
    return abs(fx[x]-a[y].x)+abs(fy[x]-a[y].y);
}
int calc3(int x,int y){
    return abs(a[x].x-a[y].x)+abs(a[x].y-a[y].y);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d%d",&fx[i-1],&fy[i-1]);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].t);
    }
    for(int i=2;i<1<<n;i<<=1)lg[i]=lg[i>>1]+1;
    stable_sort(a+1,a+m+1);
    memset(dp1,63,sizeof dp1);
    memset(dis,63,sizeof dis);
    memset(dt,63,sizeof dt);
    memset(dp2,-63,sizeof dp2);
    for(int i=0;i<1<<n;i++){
        for(int o=0;o<n;o++){
            for(int k=0;k<n;k++){
                if(i&(1<<k))dis[o][i]=min(dis[o][i],calc1(o,k));
            }
        }
    }
    for(int o=0;o<1<<n;o++){
        for(int i=1;i<=m;i++){
            for(int k=0;k<n;k++){
                if(o&(1<<k))dt[i][o]=min(dt[i][o],calc2(k,i));
            }
        }
    }
    for(int i=0;i<n;i++)dp1[0][1<<i]=0;
    for(int i=1;i<=m;i++)dp2[i][0]=1;
    a[0].t=0;
    int ans=0;
    for(int o=0;o<1<<n;o++){
        for(int i=0;i<=m;i++){
            if(dp1[i][o]>1e9)continue;
            for(int p=0;p<n;p++){
                if(!(o&(1<<p)))dp1[i][o|(1<<p)]=min(dp1[i][o|(1<<p)],dp1[i][o]+dis[p][o]);
            }
            for(int p=1;p<=m;p++){
                if(dt[p][o]+dp1[i][o]<=a[p].t)dp2[p][o]=max(dp2[p][o],i+1);
            }
        }
        for(int i=1;i<=m;i++){
            if(dp2[i][o]<0)continue;
            ans=max(ans,dp2[i][o]);
            for(int k=0;k<n;k++){
                dp1[dp2[i][o]][o|(1<<k)]=min(dp1[dp2[i][o]][o|(1<<k)],a[i].t+min(calc2(k,i),dis[k][o]));
            }
            for(int k=i+1;k<=m;k++){
                if(a[k].t-a[i].t>=min(calc3(i,k),dt[k][o]))dp2[k][o]=max(dp2[k][o],dp2[i][o]+1);
            }
        }
    }
    printf("%d",ans);
    return 0;
}