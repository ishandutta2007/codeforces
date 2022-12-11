#include <iostream>

using namespace std;

int main() {
    int v1, v2, v3, vm;
    cin >> v1 >> v2 >> v3 >> vm;
    for (int i = 1; i <= 200; i++) {
        for (int j = 1; j < i; j++) {
            for (int k = 1; k < j; k++) {
                if (i >= v1 && j >= v2 && k >= v3 && k >= vm) {
                    if (2 * v1 >= i && 2 * v2 >= j && 2 * v3 >= k && 2 * vm >= k) {
                        if (2 * vm < i && 2 * vm < j) {
                            cout << i << endl << j << endl << k << endl;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << "-1" << endl;
    return 0;
}