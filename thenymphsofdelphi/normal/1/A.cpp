#include <iostream>
using namespace std;

int main(){
    unsigned long long m, n, a;
    cin >> n >> m >> a;
    if (m % a == 0) m /= a;
    else m = m / a + 1;
    if (n % a == 0) n /= a;
    else n = n / a + 1;
    unsigned long long ans = m * n;
    cout << ans;
}