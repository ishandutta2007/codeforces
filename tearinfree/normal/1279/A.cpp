#include <bits/stdc++.h>
using namespace std;

bool can(int a,int b,int c) {
    return a <= b+c+1;
}

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int r,g,b;
        scanf("%d%d%d",&r,&g,&b);
        if(can(r,g,b) && can(g,r,b) && can(b,r,g)) puts("YES");
        else puts("NO");
    }
    return 0;
}