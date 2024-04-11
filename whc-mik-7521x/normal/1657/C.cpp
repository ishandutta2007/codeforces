#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t,n,a[N],op[N<<1],len[N<<1];
bool check(int l,int r){
    for(;l<r;l++,r--){
        if(a[l]!=a[r])return 0;
    }
    return 1;
}
int solve(int now){
    for(int i=now*2+1;i<=2*n;i++){
        if(i-len[i]<=now*2)return (i*2-now*2)/2; 
    }
    return -1;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        for(int i=1;i<=n;i++){
            a[i]=getchar()=='('?1:-1;
        }
        op[0]=3;
        for(int i=1;i<=n;i++){
            op[i*2-1]=2;
            op[i*2]=a[i];
        }
        op[n*2+1]=2;
        op[n*2+2]=4;
        int mi=0,mxr=0;
        for(int i=0;i<2*n+2;i++){
            len[i]=0;
            if(i<=mxr)len[i]=min(mxr-i,len[mi*2-i]);
            while(i-len[i]>0&&op[i+len[i]+1]==op[i-len[i]-1])len[i]++;
            if(mxr<len[i]+i)mi=i,mxr=len[i]+i;
        }
        int now=1,ans=0;
        while(now<=n-1){
            if(a[now]==a[now+1])now+=2,ans++;
            else if(a[now]==1&&a[now+1]==-1)now+=2,ans++;
            else{
                int tt=solve(now);
                if(tt==-1)break;
                else now=tt+1;
                ans++;
            }
        }
        printf("%d %d\n",ans,n-now+1);
    }
    return  0;
}