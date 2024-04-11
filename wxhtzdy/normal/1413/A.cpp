#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        int ans[n];
        for(int i=0;i<n/2;i++)ans[i]=a[n-i-1],ans[n-i-1]=-a[i];
        for(int i=0;i<n;i++)printf("%i ",ans[i]);
        printf("\n");
    }
    return 0;
}