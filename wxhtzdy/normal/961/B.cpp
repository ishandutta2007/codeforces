#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i %i",&n,&k);
    int a[n],t[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=0;i<n;i++)scanf("%i",&t[i]);
    long long pref[n],pref1[n];
    for(int i=0;i<n;i++){
        if(i==0)pref[i]=(t[i]==0?0:a[i]),pref1[i]=a[i];
        else pref[i]=pref[i-1]+(t[i]==0?0:a[i]),pref1[i]=pref1[i-1]+a[i];
    }
    long long ans=0;
    for(int i=k-1;i<n;i++){
        long long sum=pref1[i]-(i==k-1?0:pref1[i-k])+pref[n-1]-pref[min(n-1,i)];
        if(i>=k)sum+=pref[i-k];
        ans=max(ans,sum);
    }
    printf("%lld",ans);
    return 0;
}