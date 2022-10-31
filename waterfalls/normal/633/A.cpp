#include <bits/stdc++.h>
using namespace std;

int a,b,c;

int main() {
    scanf("%d%d%d",&a,&b,&c);
    for (int i=0;i<=10000;i++) for (int j=0;j<=10000;j++) {
        if (i*a+j*b==c) return printf("Yes\n"), 0;
    }
    printf("No\n");

	return 0;
}