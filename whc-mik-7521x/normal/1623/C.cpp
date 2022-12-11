#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n;
long long h[N];
bool check(int mid){
    long long add[N];
    for(int i=1;i<=n;i++)add[i]=0;
    for(int i=n;i>=3;i--){
        if(h[i]+add[i]<mid)return 0;
        int now=min((h[i]+add[i]-mid),h[i])/3;
        add[i-1]+=now;
        add[i-2]+=now*2;
    }
    return h[1]+add[1]>=mid&&h[2]+add[2]>=mid;
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&h[i]);
        int l=0,r=1e9+1,mid,ans=0;
        while(l<=r){
            mid=(l+r)>>1;
            if(check(mid))l=mid+1,ans=mid;
            else r=mid-1;
        }
        printf("%d\n",ans);
    }
    return  0;
}