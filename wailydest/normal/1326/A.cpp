#include <iostream>
using namespace std;

void solve (int n)
{
    if (n == 1) {
        cout << -1;
        return;
    }
    for (int i = 0; i < n - 1; ++i) cout << 5;
    cout << 4;
}

int main()
{
    int t;
    cin >> t;
    
    int n;
    while (t--) {
        cin >> n;
        solve(n);
        cout << '\n';
    }
    return 0;
}