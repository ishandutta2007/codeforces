#include <iostream>
#include <vector>
using namespace std;

int get_another(int a, int b)
{
    if (a != 1 && b != 1) return 1;
    if (a != 2 && b != 2) return 2;
    return 3;
}

void solve()
{
    int n;
    cin >> n;
    
    vector<int> type(n);
    
    for (int i = 0; i < n; ++i) cin >> type[i];
    
    int k = 1;
    
    int first_one = type[0];
    for (int i = 0; i < n && k == 1; ++i) if (type[i] != first_one) k = 2;
    
    if (k == 2 && n % 2) {
        k = 3;
        if (type[0] == type[n - 1]) k = 2;
        for (int i = 1; i < n && k == 3; ++i) if (type[i] == type[i - 1]) k = 2;
    }
    
    if (k == 1) {
        cout << 1 << '\n';
        for (int i = 0; i < n; ++i) cout << 1 << ' ';
        cout << '\n';
        return;
    }
    if (k == 2) {
        cout << 2 << '\n';
        
        cout << 1 << ' ';
        if (n % 2) {
            bool wassame = false;
            int prev = 1;
            for (int i = 1; i < n; ++i) {
                if (type[i] == type[i - 1] && !wassame) {
                    wassame = true;
                }
                else {
                    prev = - prev + 3;
                }
                cout << prev << ' ';
            }
        }
        else {
            for (int i = 1; i < n; ++i) cout << (i % 2 ? 2 : 1) << ' ';
        }
        cout << '\n';
        return;
    }
    
    cout << 3 << '\n';
    cout << 1 << ' ';
    int prev = 1;
    for (int i = 1; i < n - 1; ++i) {
        if (type[i] != type[i - 1]) prev = - prev + 3;
        cout << prev << ' ';
    }
    cout << 3 << '\n';
}

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}