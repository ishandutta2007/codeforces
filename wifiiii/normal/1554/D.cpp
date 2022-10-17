#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        // n is even : 000..0010....0
        //              n/2-1    n/2

        // n is odd : 000...010....02
        //             n/2-1    n/2

        int n;
        cin >> n;
        if(n == 1) {
            cout << "a" << endl;
        } else if(n % 2 == 0) {
            cout << string(n / 2 - 1, 'a') + "b" + string(n / 2, 'a') << endl;
        } else {
            cout << string(n / 2 - 1, 'a') + "b" + string(n / 2, 'a') + "c" << endl;
        }
    }
}