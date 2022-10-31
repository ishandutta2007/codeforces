#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int n;
        scanf("%d",&n);
        if(n==1) puts("0");
        else {
            if(n%2) printf("7"),n-=3;
            while(n) printf("1"),n-=2;
            puts("");
        }
    }
    return 0;
}