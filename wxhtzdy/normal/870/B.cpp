#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i %i",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    if(k==1){
        sort(a,a+n);
        printf("%i",a[0]);
    }else{
        if(k==2){
            printf("%i",max(a[0],a[n-1]));
        }else{
            sort(a,a+n);
            printf("%i",a[n-1]);
        }
    }
    return 0;
}