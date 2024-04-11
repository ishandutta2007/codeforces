#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int main(){
    int n;scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    long long ans=0;
    for(int mx=0;mx<=30;mx++){
        long long sum=0,best=0;
        for(int i=0;i<n;i++){
            int val=a[i]>mx?-inf:a[i];
            sum+=val;best=min(best,sum);
            ans=max(ans,sum-best-mx);
        }
    }
    printf("%lld",ans);
    return 0;
}