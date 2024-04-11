#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    if(n%2==0){
        printf("NO");
        return 0;
    }
    int ans[2*n];
    for(int i=0;i<n;i++){
        if(i%2==0)ans[i]=2*i+1,ans[i+n]=2*i+2;
        else ans[i+n]=2*i+1,ans[i]=2*i+2;
    }
    printf("YES\n");
    for(int i=0;i<2*n;i++)printf("%i ",ans[i]);
    return 0;
}