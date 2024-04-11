#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n],cnt[2]={0,0};
        for(int i=0;i<n;i++)scanf("%i",&a[i]),cnt[a[i]%2]++;
        long long ans=0;
        int m;scanf("%i",&m);
        int b[m];
        for(int i=0;i<m;i++)scanf("%i",&b[i]),ans+=cnt[b[i]%2];
        printf("%lld\n",ans);
    }
    return 0;
}