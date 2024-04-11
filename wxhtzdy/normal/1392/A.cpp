#include <bits/stdc++.h>
using namespace std;
const int N=200050;
int n,a[N];
int main(){
    int t;scanf("%i",&t);
    while(t--){
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%i",&a[i]);
        bool ok=0;
        for(int i=2;i<=n;i++)if(a[i]!=a[i-1])ok=1;
        if(ok)printf("1\n");
        else printf("%i\n",n);
    }
    return 0;
}