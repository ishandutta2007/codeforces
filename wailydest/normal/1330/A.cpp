#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n, x;
    bool arr[1000];
    int val;
    while (t--) {
        for (int i = 0; i < 1000; ++i) arr[i] = 0;
        cin >> n >> x;
        for (int i = 0; i < n; ++i) {
            cin >> val;
            arr[val] = 1;
        }
        int i = 1;
        while (x) {
            if (!arr[i]) --x;
            ++i;
        }
        while (arr[i]) ++i;
        cout << i - 1 << '\n';
    }
    return 0;
}