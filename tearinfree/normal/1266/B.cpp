#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        lli n;
        scanf("%lld",&n);
        if(n>=21) {
            n%=14;
            if(n+14<21) n+=14;
        }
        puts(n>=15 ? "YES" : "NO");
    }
    return 0;
}