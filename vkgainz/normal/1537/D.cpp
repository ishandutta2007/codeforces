#include <bits/stdc++.h>
using namespace std;
 
int main() {
    //if i is odd, win[i] = 0
    //i - d != 2^(2k + 1) ==> (i - 2^(2k + 1)) * r = i ==> i = 2^(2k + 1) * r / (r - 1), r - 1 = 2 ^ g
    //if i is 2^(2*k + 1), win[i] = 0
    //2^(2k + 1) - 2^r = 2^(2g + 1)
    //otherwise win[i] = 1
    //i is even and not an odd power of 2
    //suppose i is not a power of 2
    //then there exists odd divisor of i ==> i - d is odd win[i - d] = 0 !win[i - d] = 1
    //i is an even power of 2 then take i / 2 ==> i / 2 will be odd power of 2
    //

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int p = 0, power = 1;
        while(power < n) {
            power *= 2, p++;
        }
        if(power == n && p % 2 == 1) {
            cout << "Bob" << "\n";
        }
        else if(n % 2) {
            cout << "Bob" << "\n";
        }
        else {
            cout << "Alice" << "\n";
        }

    }
}