#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N],b[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        long long ans1=1e18,ans3=1e18,ans4=1e18,ans5=1e18,ans6=1e18;
        for(int i=1;i<=n;i++){
            ans3=min(ans3,1ll*labs(a[1]-b[i]));
        }
        for(int i=1;i<=n;i++){
            ans4=min(ans4,1ll*labs(a[n]-b[i]));
        }
        for(int i=1;i<=n;i++){
            ans5=min(ans5,1ll*labs(a[i]-b[1]));
        }
        for(int i=1;i<=n;i++){
            ans6=min(ans6,1ll*labs(a[i]-b[n]));
        }
        ans1=min(ans1,ans3+ans4+ans5+ans6);
        ans1=min(ans1,ans3+ans5+labs(a[n]-b[n]));
        ans1=min(ans1,ans3+ans6+labs(a[n]-b[1]));
        ans1=min(ans1,ans4+ans5+labs(a[1]-b[n]));
        ans1=min(ans1,ans4+ans6+labs(a[1]-b[1]));
        ans1=min(ans1,llabs(a[1]-b[1])+llabs(a[n]-b[n]));
        ans1=min(ans1,llabs(a[1]-b[n])+llabs(a[n]-b[1]));
        printf("%lld\n",ans1);
    }
    return  0;
}