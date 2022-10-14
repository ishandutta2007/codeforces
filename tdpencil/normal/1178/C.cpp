#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b;
    cin >> a >> b;
    int x = 1;
    const int res = 998244353;
    while(a--) {
        x<<=1;
        x%=res;
    }
    while(b--) {
        x<<=1;
        x%=res;
    }
    cout << x;
}