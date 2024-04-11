#include <cstdio>
#include <algorithm>

using namespace std;

int n;
long long k;
long long fib[100];

int main() {
    scanf("%d%I64d",&n,&k);
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2;i<=84;i++) fib[i] = fib[i-1]+fib[i-2];
    for (int i=1;i<=n;i++) {
        if (k<=fib[n-i]) printf("%d ",i);
        else {
            printf("%d %d ",i+1,i);
            k-=fib[n-i];
            i+=1;
        }
    }
    printf("\n");

    return 0;
}