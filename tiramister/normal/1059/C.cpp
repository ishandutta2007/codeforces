#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int g = 1;
    while (N > 0) {
        if (N == 3) {
            cout << g << " " << g << " " << g * 3;
            break;
        }

        for (int i = 1; i <= N; i += 2) cout << g << " ";
        N /= 2;
        g *= 2;
    }
    cout << endl;
    return 0;
}