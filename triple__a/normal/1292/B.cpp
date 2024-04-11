#include<bits/stdc++.h>
using namespace std;

const long long INF=1e16;
long long xr,yr,ax,ay,bx,by,xs,ys,t;
long long x[107],y[107];
int cnt=0;

long long dis(long long u0,long long v0,long long u1,long long v1){
    if (u0<u1) swap(u0,u1);
    if (v0<v1) swap(v0,v1);
    return min(u0-u1,2*INF)+min(v0-v1,2*INF);
}

bool ck(int i,int j){
    if (dis(xs,ys,x[i],y[i])+dis(x[i],y[i],x[j],y[j])<=t) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin>>xr>>yr>>ax>>ay>>bx>>by;
    cin>>xs>>ys>>t;
    x[0]=xr, y[0]=yr;
    while (x[cnt]<=INF&&y[cnt]<=INF){
        ++cnt;
        x[cnt]=x[cnt-1]*ax+bx;
        y[cnt]=y[cnt-1]*ay+by;
    }
    int ans=0;
    for (int i=0;i<=cnt;++i){
        for (int j=0;j<=cnt;++j){
            if (ck(i,j)) ans=max(ans,abs(i-j)+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}