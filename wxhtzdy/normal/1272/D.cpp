#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int a[N],s[N][2];
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    int ans=1,cnt=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1])cnt++;
        else cnt=1;
        ans=max(ans,cnt);
    }
    s[1][0]=s[n][1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]>a[i-1])s[i][0]=s[i-1][0]+1;
        else s[i][0]=1;
    }
    for(int i=n-1;i>=1;i--){
        if(a[i]<a[i+1])s[i][1]=s[i+1][1]+1;
        else s[i][1]=1;
    }
    for(int i=2;i<n;i++)if(a[i-1]<a[i+1])ans=max(ans,s[i-1][0]+s[i+1][1]);
    printf("%i",ans);
    return 0;
}