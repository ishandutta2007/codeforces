#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+9;
int n,m,a[N],dp[N];
int s[N],top;
int main(){
    memset(a,0,sizeof(a));scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        int l,r;scanf("%d%d",&l,&r);
        a[l]++,a[r+1]--;
    }
    for(int i=1;i<=m;i++) a[i]+=a[i-1];
    top=0;
    for(int i=1;i<=m;i++){
        if(!top||s[top]<=a[i]){
            s[++top]=a[i];dp[i]=top;
        }
        else{
            int l=1,r=top,mid,ans=top;
            while(l<=r){
                mid=(l+r)>>1;
                if(s[mid]>a[i]) ans=mid,r=mid-1;
                else l=mid+1;
            }
            s[ans]=a[i],dp[i]=top;
        }
    }
    top=0;int Ans=0;
    for(int i=m;i>=1;i--){
        if(!top||s[top]<=a[i]){
            s[++top]=a[i];Ans=max(Ans,dp[i-1]+top);
        }
        else{
            int l=1,r=top,mid,ans=top;
            while(l<=r){
                mid=(l+r)>>1;
                if(s[mid]>a[i]) ans=mid,r=mid-1;
                else l=mid+1;
            }
            s[ans]=a[i],Ans=max(Ans,dp[i-1]+top);
        }
    }
    printf("%d\n",Ans);
    return 0;
}