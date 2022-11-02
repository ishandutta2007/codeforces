#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    int id = 1, incr = 1;
    while (id <= N) {
        cout << S[id - 1];
        id += incr;
        ++incr;
    }

    cout << endl;
    return 0;
}