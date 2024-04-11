#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int n,x;
        scanf("%i %i",&n,&x);
        int a[n],b[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        for(int i=0;i<n;i++)scanf("%i",&b[i]);
        sort(a,a+n);sort(b,b+n);
        bool ok=true;
        for(int i=0;i<n;i++)ok&=(a[i]+b[n-i-1])<=x;
        if(ok)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}