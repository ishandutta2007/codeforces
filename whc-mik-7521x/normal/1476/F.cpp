#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int t,n,p[N],q[N],dp[N],fr[N],kk[N];
struct RMQ{
    int st[N][21];
    RMQ(int a[],int len){
        for(int i=1;i<=len;i++)st[i][0]=a[i];
        for(int o=1;o<=20;o++){
            for(int i=1;i+(1<<o)-1<=len;i++){
                st[i][o]=max(st[i][o-1],st[i+(1<<(o-1))][o-1]);
            }
        }
    }
    int query(int l,int r){
        if(l>r)return 0;
        int len=r-l+1,k=30;
        while((1<<k)>len)k--;
        return max(st[l][k],st[r-(1<<k)+1][k]);
    }
};
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&p[i]);
            q[i]=p[i]+i;
            dp[i]=0;
        }
        RMQ ty(q,n);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            if(dp[i-1]>=i)dp[i]=max(dp[i-1],q[i]),fr[i]=i-1,kk[i]=1;
            else dp[i]=dp[i-1],fr[i]=i-1,kk[i]=1;
            int l=0,r=i-1,mid,ans=-1;
            while(l<=r){
                mid=(l+r)>>1;
                if(dp[mid]>=i-p[i]-1)ans=mid,r=mid-1;
                else l=mid+1;
            }
            if(ans!=-1){
                int now=max(ty.query(ans+1,i-1),i-1);
                if(now>dp[i])dp[i]=now,fr[i]=ans,kk[i]=2;
            }
        }
        stack<char>ans;
        if(dp[n]>=n){
            int now=n;
            while(now){
                ans.push(kk[now]==2?'L':'R');
                for(int i=now-1;i>fr[now];i--)ans.push('R');
                now=fr[now];
            }
            puts("YES");
            while(ans.size())putchar(ans.top()),ans.pop();
            puts("");
        }
        else{
            puts("NO");
        }
    }
    return  0;
}