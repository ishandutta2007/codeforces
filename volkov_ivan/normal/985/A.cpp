#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int p[n / 2];
    for (int i = 0; i < n / 2; i++) {
        cin >> p[i];
    }
    sort(p, p + n / 2);
    int ans1 = 0, ans2 = 0;
    for (int i = 0; i < n / 2; i++) {
        ans1 += abs(p[i] - (2 * i + 1));
        ans2 += abs(p[i] - (2 * (i + 1)));
    }
    cout << min(ans1, ans2) << endl;
    return 0;
}