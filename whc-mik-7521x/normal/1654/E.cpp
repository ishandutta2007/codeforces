#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N],mp[50000000];
int solve(){
    int res=0;
    int i;
    for(i=0;i*i<=(int)1e5;i++){
        for(int o=1;o<=n;o++){
            res=max(res,++mp[a[o]+i*(n-o)]);
        }
        for(int o=1;o<=n;o++)mp[a[o]+i*(n-o)]--;
    }
    int len=sqrt(1e5)-1;
    for(int i=1;i<=n;i++){
        for(int o=max(1,i-len);o<i;o++){
            if((a[i]-a[o])%(i-o)==0&&a[i]>=a[o])res=max(res,++mp[(a[i]-a[o])/(i-o)]+1);
        }
        for(int o=max(1,i-len);o<i;o++){
            if((a[i]-a[o])%(i-o)==0&&a[i]>=a[o])--mp[(a[i]-a[o])/(i-o)];
        }
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int ans=solve();
    reverse(a+1,a+n+1);
    ans=max(ans,solve());
    printf("%d",n-ans);
    return  0;
}