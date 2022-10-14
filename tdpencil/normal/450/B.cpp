#include <iostream>
using namespace std;

const int mod=1e9+7;
int main() {
    int a, b, n;
    cin >> a >> b >> n;
    if(b<mod) b+=mod;
    if(a<mod) a+=mod;
    if(n <= 2) {
        if(n == 1) cout << a << "\n";
        else if(n == 2) cout << b << "\n";
        return 0;
    }
    int x;
    for(int i = 2;i<n;i++) {
        x=b-a;
        a=b;
        b=x;
    }
    cout << (x%mod+mod)%mod << "\n";
}