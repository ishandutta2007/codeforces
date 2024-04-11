#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,cnt=0;
    scanf("%i%i",&a,&b);
    while((a>1||b>1)&&(a>0&&b>0)){
        if(a<b)a++,b-=2;
        else a-=2,b++;
        cnt++;
    }
    printf("%i",cnt);
}