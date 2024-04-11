#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],t,n,tot;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int tot=0;
        for(int i=1;i<n;i++)if(a[i]==a[i+1])tot++;
        if(tot<=1){printf("0\n");continue;}
        int ans1=0,ans2=1e9;
        for(int i=1;i<=n;i++){
            if(a[i]==a[i+1])ans1=max(ans1,i),ans2=min(ans2,i);
        }
        printf("%d\n",max(ans1-ans2-1,1));
    }
    return  0;
}