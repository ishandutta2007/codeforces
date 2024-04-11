#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int a, b;
    while (t--) {
        cin >> a >> b;
        if (!(a % b)) {
            cout << 0 << '\n';
            continue;
        }
        cout << b - (a % b) << '\n';
    }
    return 0;
}