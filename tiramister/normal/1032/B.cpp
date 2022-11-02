#include <iostream>

using namespace std;

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

int main() {
    string S;
    cin >> S;
    int N = S.size();

    int H = iceil(N, 20);
    int W = iceil(N, H);
    cout << H << " " << W << endl;

    int f = H * W - N;
    int cnt = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            if (j == 0 && f > 0) {
                cout << "*";
                --f;
            } else {
                cout << S[cnt];
                ++cnt;
            }
        }
        cout << endl;
    }
    return 0;
}