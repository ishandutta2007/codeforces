#include <bits/stdc++.h>
using namespace std;

bool isprime(int n) {
    for (int i=2;i*i<=n;i++) {
        if (n%i==0) return false;
    }
    return true;
}

int n,k;

int main() {
    scanf("%d",&n);
    int x = n;
    while (!isprime(x)) x-=1;
    n-=x;
    if (n==0) return printf("1\n%d\n",x), 0;
    if (isprime(n)) return printf("2\n%d %d\n",x,n), 0;
    for (int i=2;i<=n;i++) if (isprime(i) && isprime(n-i)) return printf("3\n%d %d %d\n",x,i,n-i), 0;

    return 0;
}