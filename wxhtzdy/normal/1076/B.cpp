#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    scanf("%lld",&n);
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0){
            printf("%lld",1+(n-i)/2);
            return 0;
        }
    }
    printf("%i",1);
    return 0;
}