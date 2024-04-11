#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int a, b;
    while (t--) {
        cin >> a >> b;
        if (a >= b && ((b % 2 && a % 2) || (!(b % 2) && !(a % 2)))) {
            if (a >= (long long)b * b) cout << "YES";
            else cout << "NO";
        }
        else cout << "NO";
        cout << '\n';
    }
    return 0;
}