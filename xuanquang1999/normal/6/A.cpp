#include <iostream>

using namespace std;

int main() {
    int a[4];
    for(int i = 0; i < 4; ++i) cin >> a[i];

    for(int i = 0; i < 4; ++i) {
        for(int j = i+1; j < 4; ++j) {
            for(int k = j+1; k < 4; ++k) {
                if (a[i]+a[j] > a[k] && a[j]+a[k] > a[i] && a[k]+a[i] > a[j]) {
                    cout << "TRIANGLE";
                    return 0;
                }
            }
        }
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = i+1; j < 4; ++j) {
            for(int k = j+1; k < 4; ++k) {
                if (a[i]+a[j] == a[k] || a[i]+a[k] == a[j] || a[j]+a[k] == a[i]) {
                    cout << "SEGMENT";
                    return 0;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}