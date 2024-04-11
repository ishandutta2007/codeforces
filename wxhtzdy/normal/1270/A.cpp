#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n,k1,k2;
        scanf("%i %i %i",&n,&k1,&k2);
        int a[k1],b[k2];
        for(int i=0;i<k1;i++)scanf("%i",&a[i]);
        for(int i=0;i<k2;i++)scanf("%i",&b[i]);
        sort(a,a+k1);
        sort(b,b+k2);
        if(a[k1-1]>b[k2-1])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}