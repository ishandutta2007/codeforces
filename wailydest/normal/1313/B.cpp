#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int n, x, y;
    while (t--) {
        cin >> n >> x >> y;
        if (x + y <= n || n == 1) cout << 1 << ' ';
        else {
            cout << (x + y - n + 1 <= n ? x + y - n + 1 : n) << ' ';
        }
        cout << (x + y - 1 <= n ? x + y - 1 : n) << '\n';
    }
    return 0;
}