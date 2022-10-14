#include <bits/stdc++.h>
using namespace std;

int _;
long long u,v;

void solve() {
    scanf("%lld%lld",&u,&v);
    printf("%lld %lld\n",-u*u,v*v);
}

int main() {
    for (scanf("%d",&_);_;_--) {
        solve();
    }
}