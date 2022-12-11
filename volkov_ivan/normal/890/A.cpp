#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    int a[6];
    int summ = 0;
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
        summ += a[i];
    }
    if (summ % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    summ /= 2;
    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 6; j++) {
            for (int k = j + 1; k < 6; k++) {
                if (a[i] + a[j] + a[k] == summ) {
                    cout << "YES" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}