#include<stdio.h>
int min (int a, int b){
    if(a<b) return a;
    else return b;
}
int main (){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int x = min(c,d);
    int y = min(x,a);
    int z = a-y;
    int ans = (min(z,b)*32) + y*256 ;
    printf("%d",ans);
    return 0;
    
}