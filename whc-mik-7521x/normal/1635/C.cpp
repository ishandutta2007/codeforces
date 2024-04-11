#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int t,n,a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        if(a[n]<0){
            int pd=0;
            for(int i=1;i<n;i++)if(a[i]>a[i+1])pd=1;
            puts(pd?"-1":"0");
        }
        else{
            if(a[n]<a[n-1]){
                puts("-1");
            }
            else{
                printf("%d\n",n-2);
                for(int i=n-2;i>=1;i--){
                    printf("%d %d %d\n",i,i+1,n);
                }
            }
        }
    }
    return  0;
}