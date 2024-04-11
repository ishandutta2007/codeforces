#include<bits/stdc++.h>
using namespace std;
int t,n,a,b,c;
 
int main(){
    scanf("%d",&t);
    a=6,b=10,c=14;
    while(t--){
        scanf("%d",&n);
        if(n<=a+b+c){
            printf("NO\n");
            continue;
        }
        int p=n-a-b-c;
        if(p!=a&&p!=b&&p!=c){
            printf("YES\n");
            printf("%d %d %d %d\n",a,b,c,p);
            continue;
        }
        if(n==40){
            printf("YES\n");
            printf("6 14 15 5\n");
            continue;
        }
        if(n==44){
            printf("YES\n");
            printf("6 7 10 21\n");
            continue;
        }
        if(n==36){
            printf("YES\n");
            printf("5 6 10 15\n");
            continue;
        }
    }
    return 0;
}