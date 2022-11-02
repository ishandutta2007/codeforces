#include<bits/stdc++.h>
using namespace std;
const int N = 200009;
int n,m,k,f[N][1<<9],t[N],c[19];
struct pp{int x,tag,id,len;}p[N];
bool cmp(pp a,pp b){
    return a.x==b.x?(a.tag<b.tag):(a.x<b.x);
}
void Mx(int &a,int b){
    if(b>a) a=b;
    return ;
}
int lowbit(int a){return a&(-a);}
int check(int a){
    int cnt=0;
    while(a){cnt++;a-=lowbit(a);}
    return cnt%2;
}
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;i++){
        int l,r;scanf("%d%d",&l,&r);
        p[i*2-1].tag=1,p[i*2-1].x=l,p[i*2-1].id=i,p[i*2-1].len=r-l+1;
        p[i*2].tag=0,p[i*2].x=r+1,p[i*2].id=i,p[i*2].len=r-l+1;
    }
    sort(p+1,p+2*n+1,cmp);
    for(int i=1;i<=2*n;i++){
        if(p[i].tag){
            for(int j=1;j<=k;j++)
                if(!c[j]){t[p[i].id]=j,c[j]=1;break;}
        }
        else c[t[p[i].id]]=0;
    }
    memset(f,-1,sizeof(f));
    f[0][0]=0,p[0].x=1,p[0].tag=1;int ans=-1;
    for(int i=1;i<=2*n;i++){
        if(p[i].tag){
            for(int j=0;j<(1<<k);j++){
                if(f[i-1][j]!=-1){
                    Mx(f[i][j|(1<<(t[p[i].id]-1))],f[i-1][j]+check(j)*(p[i].x-p[i-1].x));
                    Mx(f[i][j],f[i-1][j]+check(j)*(p[i].x-p[i-1].x));
                }
            }
        }
        else{
            for(int j=0;j<(1<<k);j++){
                if(f[i-1][j]!=-1&&(j&(1<<(t[p[i].id]-1)))) 
                    Mx(f[i][j-(1<<(t[p[i].id]-1))],f[i-1][j]+check(j)*(p[i].x-p[i-1].x));
                if(f[i-1][j]!=-1&&!(j&(1<<(t[p[i].id]-1)))) 
                    Mx(f[i][j],f[i-1][j]+check(j)*(p[i].x-p[i-1].x));
            }       
        }
        for(int j=0;j<(1<<k);j++)
            Mx(ans,f[i][j]);
    }
    printf("%d\n",ans);
    return 0;
}