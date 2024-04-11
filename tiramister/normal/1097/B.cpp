#include <bitset>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    bitset<3000> b(1);
    int sum = 0;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        b |= (b << a);
        sum += a;
    }

    for (int d = 0; d < 3000; ++d) {
        if (!b[d]) continue;
        if ((sum - d * 2) % 360 == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}