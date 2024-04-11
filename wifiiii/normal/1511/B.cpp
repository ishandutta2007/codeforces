#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

int p[10]={0,7,83,661,6301,83207,227567,9887131,88548139,718028543};
int isprime(ll x) {
    if(x<2) return 0;
    for(ll i=2;i*i<=x;++i) if(x%i==0) return 0;
    return 1;
}
int getlen(int x) {
    return log10(x)+1;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int m = min({a, b, c}) - 1;
        a -= m;
        b -= m;
        c -= m;
        ll tmp = pow(10, m);
        if(a == b) {
            cout << p[a] * tmp << " " << (p[a] + 1) * tmp << endl;
        } else {
            cout << p[a] * tmp << " " << p[b] * tmp << endl;
        }
    }
}