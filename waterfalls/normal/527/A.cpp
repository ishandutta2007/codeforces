#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    long long a,b;
    cin >> a >> b;
    if (a>b) swap(a,b);
    long long ans = 0;
    while (a!=b && a!=0) {
        ans+=b/a;
        b = b%a;
        if (b<a) swap(a,b);
    }
    if (a!=0) ans+=1;
    cout << ans << endl;

    return 0;
}