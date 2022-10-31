#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b) swap(a,b);

        int ans = 0;
        while(a < b) {
            a += ++ans;
        }
        while((a+b)%2!=0) {
            a += ++ans;
        }
        printf("%d\n",ans);
    }
    
    return 0;
}