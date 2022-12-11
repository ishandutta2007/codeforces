#include <bits/stdc++.h>

using namespace std;

int h[10];
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        h[val]++;
    }
    if (h[1] == 0) {
        for(int i = 1; i <= h[2]; i++) cout << "2 ";
        return 0;
    }
    if (h[2] == 0) {
        for(int i = 1; i <= h[1]; i++) cout << "1 ";
        return 0;
    }
    cout << "2 1 ";
    for(int i = 1; i < h[2]; i++) cout << "2 ";
    for(int i = 1; i < h[1]; i++) cout << "1 ";
}