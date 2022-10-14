#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        int a[n];
        for(int i=0;i<n;i++)scanf("%i",&a[i]);
        if(n==1&&a[0]%2==1){printf("-1\n");continue;}
        bool ok=0;
        for(int i=0;i<n;i++)if(a[i]%2==0){printf("1\n%i\n",i+1);ok=1;break;}
        if(ok)continue;
        printf("2\n%i %i\n",1,2);
    }
    return 0;
}