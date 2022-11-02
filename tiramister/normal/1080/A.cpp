#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    cout << (N * 2 + K - 1) / K + (N * 5 + K - 1) / K + (N * 8 + K - 1) / K << endl;
    return 0;
}