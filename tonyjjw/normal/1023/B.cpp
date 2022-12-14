#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
    long long n, k;
    scanf("%lld%lld", &n, &k);
    long long minV;
    if(k&1){
        minV = (k+1)/2;
    }
    else {
        minV = (k+2)/2;
    }
    long long maxV = k-1;
    if(n < minV) {
        puts("0");
        return 0;
    }
    printf("%lld", min(maxV, n) - minV + 1);
    return 0;
}