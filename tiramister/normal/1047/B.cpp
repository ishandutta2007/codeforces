#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int z[N];
    for (int i = 0; i < N; ++i) {
        int x, y;
        cin >> x >> y;
        z[i] = x + y;
    }
    cout << *max_element(z, z + N) << endl;
    return 0;
}