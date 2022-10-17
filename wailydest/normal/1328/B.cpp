#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    int n, k;
    int first_pos;
    while (t--) {
        cin >> n >> k;
        first_pos = 1;
        int i;
        for (i = 1; (long long) first_pos + i <= k; ++i) {
            first_pos += i;
        }
        for (int j = n - 1; j >= 0; --j) {
            if (j == i || j == k - first_pos) cout << 'b';
            else cout << 'a';
        }
        cout << '\n';
    }
    return 0;
}