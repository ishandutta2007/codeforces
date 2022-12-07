#include <vector>
#include <iostream>
using namespace std;


int a[100000];

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            cin >> a[j];
        }
        cout << 1 << " " << n << endl;
    }
}