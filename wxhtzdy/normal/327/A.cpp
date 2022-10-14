#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int pref[n];
    for(int i=0;i<n;i++)pref[i]=a[i]+(i==0?0:pref[i-1]);
    int ans=pref[n-1];
    if(ans==n){printf("%i",ans-1);return 0;}
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int k=pref[j]-(i==0?0:pref[i-1]),t=j-i+1;
            ans=max(ans,pref[n-1]-k+t-k);
        }
    }
    printf("%i",ans);
    return 0;
}