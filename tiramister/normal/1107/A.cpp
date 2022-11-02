#include <iostream>
#include <string>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    for (int q = 0; q < Q; ++q) {
        int N;
        string S;
        cin >> N >> S;
        if (N == 2 && S[0] >= S[1]) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            cout << 2 << endl;
            S.insert(S.begin() + 1, ' ');
            cout << S << endl;
        }
    }
    return 0;
}