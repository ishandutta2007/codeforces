#include <bits/stdc++.h>
using namespace std;
const int N=550;
int n;
long long a[N];
int main(){
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            for(int k=j;k<=n;k++){
                ans=max(ans,a[i]|a[j]|a[k]);
            }
        }
    }
    printf("%lld",ans);
    return 0;
}