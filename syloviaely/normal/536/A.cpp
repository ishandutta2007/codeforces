#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int A,B,n;
int check(int k1,int k2,int k3,int k4){
    long long l=A+1ll*(k1-1)*B,r=A+1ll*(k2-1)*B;
    if (r>k3) return 0;
    if (k2-k1+1<=k4) return 1;
    r-=B;
    long long tot=(l+r)*(k2-k1)/2;
    if (k4==1) return (tot+r+B)<=k3;
    if (tot+r+B>1ll*k3*k4) return 0;
    long long t=(tot/(k4-1))+((tot%(k4-1))!=0);
    r+=B;
    if (t+(r-t)>k3) return 0;
    return 1;
}
int main(){
    scanf("%d%d%d",&A,&B,&n);
    for (;n;n--){
        int k1,t,m; scanf("%d%d%d",&k1,&t,&m);
        if (1ll*B*(k1-1)+A>t){
            printf("-1\n"); continue;
        }
        int l=k1,r=1e6+1,ans=0;
        while (l<r){
            int mid=(l+r)>>1;
            if (check(k1,mid,t,m)){
                ans=mid; l=mid+1;
            } else r=mid;
        }
        printf("%d\n",ans);
    }
    return 0;
}