#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int n;scanf("%i",&n);
        int a[n];
        long long sum=0;
        for(int i=0;i<n;i++)scanf("%i",&a[i]),sum+=a[i];
        long long tmp=0;
        for(int i=0;i<n;i++)if(i%2==0)tmp+=a[i]-1;
        if(2*tmp<=sum){
            for(int i=0;i<n;i++){
                if(i%2==0)printf("1 ");
                else printf("%i ",a[i]);
            }
        }else{
            for(int i=0;i<n;i++){
                if(i%2==1)printf("1 ");
                else printf("%i ",a[i]);
            }
        }
        printf("\n");
    }
    return 0;
}