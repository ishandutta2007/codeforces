#include<bits/stdc++.h>
using namespace std;
int T,a,b,c,d;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d%d",&a,&b,&c,&d);
        printf("%d\n",max(a+b,c+d));
    }
    return 0;
}