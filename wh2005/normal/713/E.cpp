#include<bits/stdc++.h>
using namespace std;
const int N = 200009;
int n,m,a[N],p[N],r,f[N];
void init(){
    r=0;
    for(int i=1;i<=n;i++) r=max(a[i+1]-a[i]-1,r);
    for(int i=1;i<=n;i++)
        if(a[i+1]-a[i]-1==r){
            for(int j=1;j<=n;j++) p[j]=a[i+j];
            for(int j=n;j>=1;--j) p[j]-=p[1];
            break;
        }
}
bool check(int x){
    f[1]=0;
    for(int i=2;i<=n;i++){
        f[i]=f[i-1];
        if(f[i-1]>=p[i]-1) f[i]=p[i]+x;
        if(f[i-1]>=p[i]-x-1) f[i]=max(f[i],p[i]);
        if(i!=2&&f[i-2]>=p[i]-x-1) f[i]=max(f[i],p[i-1]+x);
    }
    if(f[n]>=min(m-1,m+p[1]-x-1)) return 1;
    f[2]=max(x,p[2]);
    for(int i=3;i<=n;i++){
        f[i]=f[i-1];
        if(f[i-1]>=p[i]-1) f[i]=p[i]+x;
        if(f[i-1]>=p[i]-x-1) f[i]=max(f[i],p[i]);
        if(i!=3&&f[i-2]>=p[i]-x-1) f[i]=max(f[i],p[i-1]+x);
    }
    if(f[n]>=min(m-1,m+p[2]-x-1)) return 1;
    return 0;
}
int main(){
    scanf("%d%d",&m,&n);
    if(n==1){printf("%d\n",m-1);return 0;}
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[n+i]=a[i]+m;
    sort(a+1,a+2*n+1);init();
    int l=0,ans;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid)) ans=mid,r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}