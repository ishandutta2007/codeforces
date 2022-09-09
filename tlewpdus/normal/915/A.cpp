#include <bits/stdc++.h>

using namespace std;

int n, k;

int main() {
    scanf("%d%d",&n,&k);
    int i, t = 123;
    for (i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        if (k%a==0) t = min(t,k/a);
    }
    printf("%d\n",t);

    return 0;
}