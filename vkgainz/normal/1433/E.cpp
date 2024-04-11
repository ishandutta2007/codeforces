#include<bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long long
#define f first
#define s second

int main() {
    int n; cin >> n;
    ll f = 1;
    for(int i=1;i<=n-1;i++) {
        f = f*1LL*i;
    }
    f = f*1LL*2/n;
    cout << f << endl;
}