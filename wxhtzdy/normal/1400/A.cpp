#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        int n;
        scanf("%i",&n);
        char a[2*n];
        scanf("%s",&a);
        for(int i=0;i<2*n-1;i+=2)printf("%c",a[i]);
        printf("\n");
    }
}