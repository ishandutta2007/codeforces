#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        cin >> v[i];
    }

    sort(v.rbegin(), v.rend());
    int x = v.front();
    int y = 0;
    for (int i = 0; i < N; ++i) {
        if (v[i] == v[i + 1] || x % v[i] > 0) {
            y = v[i];
            break;
        }
    }

    cout << x << " " << y << endl;
    return 0;
}