#include<bits/stdc++.h>
using namespace std;
int n,m;


int main(){
    scanf("%d",&n);
    m=(n+2)/2;printf("%d\n",m);
    int x=1,y=0,op=0;
    for(int i=1;i<=n;i++){
        if(op==0) y+=1;else x+=1;
        printf("%d %d\n",x,y);
        if(y==m) op=1;
    }
    return 0;
}