#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    bool judge = false;
    for (int i = 0; i < 5; ++i) {
        string T;
        cin >> T;
        for (int j = 0; j < 2; ++j) {
            if (S[j] == T[j]) judge = true;
        }
    }

    cout << (judge ? "YES" : "NO") << endl;
    return 0;
}