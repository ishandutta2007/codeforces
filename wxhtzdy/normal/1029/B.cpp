#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    int j=0,ans=1,cnt=0;
    for(int i=0;i<n;i++){
        if(i==0||a[i]>a[i-1]*2)cnt=1;
        else cnt++;
        ans=max(ans,cnt);
    }
    printf("%i",ans);
}