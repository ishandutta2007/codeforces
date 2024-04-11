#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    scanf("%i",&n);
    char a[n];
    scanf("%s",&a);
    int cnt=0;
    for(auto c:a){
        if(c=='1')cnt++;
        else break;
    }
    if(n!=cnt)cnt++;
    printf("%i",cnt);
    return 0;
}