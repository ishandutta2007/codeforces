#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i %i",&n,&m);
    int cnt=n/2+n%2;
    while(cnt%m!=0)cnt++;
    if(cnt>n){
        printf("-1");
        return 0;
    }
    printf("%i",cnt);
    return 0;
}