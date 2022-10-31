#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d",&n);
    if (n%2==1) printf("%d\n",0);
    else printf("%d\n",(n-1)/4);

    return 0;
}