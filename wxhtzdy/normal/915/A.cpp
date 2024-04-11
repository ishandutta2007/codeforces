#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
    int n,k;scanf("%i %i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    int ans=1e9;
    for(int i=1;i<=n;i++)if(k%a[i]==0)ans=min(ans,k/a[i]);
    printf("%i",ans);
    return 0;
}