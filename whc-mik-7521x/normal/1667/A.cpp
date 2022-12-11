#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N],n;
long long solve(int x){
    long long last=0,res=0;
    for(int i=x-1;i>=1;i--){
        res+=(last+a[i])/a[i];
        last=(last+a[i])/a[i]*a[i];
    }
    last=0;
    for(int i=x+1;i<=n;i++){
        res+=(last+a[i])/a[i];
        last=(last+a[i])/a[i]*a[i];
    }
    return res;
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    long long ans=1e18;
    for(int i=1;i<=n;i++)ans=min(ans,solve(i));
    printf("%lld",ans);
    return  0;
}