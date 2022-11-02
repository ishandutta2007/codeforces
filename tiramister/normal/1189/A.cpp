#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    if (count(S.begin(), S.end(), '0') * 2 != N) {
        cout << 1 << endl;
        cout << S << endl;
    } else {
        cout << 2 << endl;
        cout << S[0] << " " << S.substr(1) << endl;
    }
    return 0;
}