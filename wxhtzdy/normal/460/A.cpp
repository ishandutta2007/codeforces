#include<bits/stdc++.h>
using namespace std;
int n,m,d=1,cnt=0;
int main(){
    scanf("%i%i",&n,&m);
    while(n>0){
        n--,cnt++,d++;
        if(d%m==0&&n>0)n++;
    }
    printf("%i",cnt);
}