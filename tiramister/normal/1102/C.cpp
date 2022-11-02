#include <iostream>

using namespace std;

int main() {
    int N, X, Y;
    cin >> N >> X >> Y;

    int a[N];
    int heal = 0, one = 0;
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] <= X) {
            ++one;
            if (a[i] + Y > X) ++heal;
        }
    }

    if (X > Y) {
        cout << N << endl;
        return 0;
    }

    cout << one - heal / 2 << endl;
    return 0;
}