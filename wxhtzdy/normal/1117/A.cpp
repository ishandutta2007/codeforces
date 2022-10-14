#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    int mx=0;
    for(int i=0;i<n;i++)mx=max(mx,a[i]);
    int cnt=0,ans=0;
    for(int i=0;i<n;i++){
        if(a[i]==mx)cnt++,ans=max(ans,cnt);
        else cnt=0;
    }
    printf("%i",ans);
    return 0;
}