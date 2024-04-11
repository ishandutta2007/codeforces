#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    for(int i=1;i<n-1;i++){
        if((a[i]^a[i+1])<a[i-1]){
            printf("1");
            return 0;
        }
    }
    int ans=1e9;
    for(int i=0;i<n-1;i++){
        int xr=a[i];
        int tmp=a[i+1];
        for(int j=i+2;j<n;j++){
            tmp^=a[j];
            if(tmp<a[i])ans=min(ans,j-i-1);
        }
        for(int j=i-1;j>=0;j--){
            xr^=a[j];
            int xt=a[i+1];
            if(xt<xr)ans=min(ans,i-j);
            for(int l=i+2;l<n;l++){
                xt^=a[l];
                if(xt<xr)ans=min(ans,i-j+l-i-1);
            }
        }
    }
    if(ans==1e9)printf("-1");
    else printf("%i",ans);
    return 0;
}