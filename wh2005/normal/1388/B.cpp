#include<bits/stdc++.h>
using namespace std;
int t,n;
 
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);int p=0;
        if(n%4==0) p=n/4;
        else p=n/4+1;
        for(int i=n;i>p;i--) printf("9");
        for(int i=p;i>=1;i--) printf("8");
        puts("");
    }
    return 0;
}