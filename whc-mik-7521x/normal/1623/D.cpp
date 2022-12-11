#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long fp(long long x,long long y){
    long long res=1;
    while(y)res=(y&1)?res*x%mod:res,x=x*x%mod,y>>=1;
    return res;
}
int t;
int n,m,rb,cb,rd,cd,lx=1,ly=1;
long long p;
void dfs(int x,int y,int dx,int dy,vector<long long>&v){
    int nx=x+dx,ny=y+dy;
    if(nx>n||nx<1)dx=-dx;
    if(ny>m||ny<1)dy=-dy;
    if((x==rb&&y==cb&&v.size()!=0&&dx==lx&&dy==ly))return;
    if(x==rd||y==cd)v.push_back(p);
    else v.push_back(1);
    nx=x+dx,ny=y+dy;
    dfs(nx,ny,dx,dy,v);
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d%d%d%d%lld",&n,&m,&rb,&cb,&rd,&cd,&p);
        vector<long long>v;
        long long fz=1;
        long long ny=fp(100,mod-2),xx=1;
        p=(100ll-p)*ny%mod;
        lx=1,ly=1;
        int nx=rb+lx,nn=cb+ly;
        if(nx>n||nx<1)lx=-lx;
        if(nn>m||nn<1)ly=-ly;
        dfs(rb,cb,lx,ly,v);
        for(int i=0;i<(int)v.size();i++){fz=(fz*v[i])%mod;}
        long long val=0;
        for(int i=0;i<(int)v.size();i++){
            xx=(v[i]*xx)%mod;
            val+=xx;
            val%=mod;
        }
        fz=(1-fz+mod)%mod;
        val=(val*fp(fz,mod-2))%mod;
        printf("%lld\n",val);
    }
    return  0;
}