#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        long long ans=0;
        for(int i=0;i<n-1;i++){
            if(a[i]>a[i+1])ans+=a[i]-a[i+1];
        }
        printf("%lld\n",ans);
    }
    return 0;
}