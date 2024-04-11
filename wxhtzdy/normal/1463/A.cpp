#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;scanf("%i",&t);
    while(t--){
        int a,b,c;scanf("%i %i %i",&a,&b,&c);
        int sum=a+b+c;
        if(sum%9==0&&min({a,b,c})>=sum/9)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}