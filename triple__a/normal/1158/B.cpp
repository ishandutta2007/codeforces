#include<bits/stdc++.h>
using namespace std;

int n,k,w;
int main(){
    scanf("%d%d",&n,&k);
    w=1+(n-k)/2;
    for (int i=1;i<=n;++i){
        if (i%w==0) putchar('1');
        else putchar('0');
    }
    return 0;
}