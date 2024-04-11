#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
    int x,y,num;
    bool operator<(const node b)const{
        return x>b.x;
    }
}a[N];
int t,n,mar[N],ans[N],mi[N],dp[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        mar[n+1]=0;
        for(int i=1;i<=n;i++)scanf("%d",&a[i].x),a[i].num=i;
        for(int i=1;i<=n;i++)scanf("%d",&a[i].y);
        stable_sort(a+1,a+n+1);
        mi[0]=1e9;
        for(int i=n;i>=1;i--)mar[i]=max(a[i].y,mar[i+1]);
        for(int i=1;i<=n;i++)mi[i]=min(mi[i-1],a[i].y);
        ans[a[1].num]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            int now=mar[i];
            int l=1,r=i-1,mid,an=-1;
            while(l<=r){
                mid=(l+r)>>1;
                if(mi[mid]<now)an=mid,r=mid-1;
                else l=mid+1;
            }
            if(an!=-1&&dp[i-1]-dp[an-1]>0){
                ans[a[i].num]=1;
                dp[i]=1;
            }
            else dp[i]=0,ans[a[i].num]=0;
            dp[i]+=dp[i-1];
        }
        for(int i=1;i<=n;i++)printf("%d",ans[i]);
        puts("");
    }
    return  0;
}