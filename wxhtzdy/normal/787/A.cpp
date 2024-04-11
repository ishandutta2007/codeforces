#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d;
    scanf("%i%i%i%i",&a,&b,&c,&d);
    for(int i=max(b,d);i<=10000;i++){
        if((i-b)%a==0&&(i-d)%c==0){printf("%i",i);return 0;}
    }
    printf("-1");
}