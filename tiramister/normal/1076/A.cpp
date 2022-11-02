#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i < N - 1; ++i) {
        if (S[i] <= S[i + 1]) {
            cout << S[i];
        } else {
            for (int j = i + 1; j < N; ++j) {
                cout << S[j];
            }
            break;
        }
    }
    cout << endl;
    return 0;
}