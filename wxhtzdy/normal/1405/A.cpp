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
        for(int i=n-1;i>=0;i--)printf("%i ",a[i]);
        printf("\n");
    }
    return 0;
}