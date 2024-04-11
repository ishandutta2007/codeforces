#include <iostream>
using namespace std;

int main()
{
    int n, val;
    cin >> n;
    int current_max = 0;
    while (n--) {
        cin >> val;
        cout << val + current_max << ' ';
        current_max = max(current_max, val + current_max);
    }
    cout << '\n';
    return 0;
}