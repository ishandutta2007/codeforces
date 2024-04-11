#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    int ans=1;
    for(int i=1;i<=20;i++){
        int x=(pow(2,i)-1)*pow(2,i-1);
        if(n%x==0)ans=x;
    }
    printf("%i",ans);
    return 0;
}