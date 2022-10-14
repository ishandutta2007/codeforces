#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    scanf("%i",&t);
    while(t--){
        int a,b,n,s;
        scanf("%i %i %i %i",&a,&b,&n,&s);
        int x=min(a,s/n);
        if(s-b<=x*n)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}