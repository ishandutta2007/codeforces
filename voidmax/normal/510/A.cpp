#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#define int long long
#define For(i, a, b) for(int i = a; i < b; ++i)
using namespace std;

int n, m;

main() {
    cin >> n >> m;
    For(i, 0, n) {
        if (i % 2 == 0) {
            For(q, 0, m) {
                cout << "#";
            }
            cout << endl;
        }
        else {
            if (i % 4 == 3) {
                cout << "#";
            }
            For(q, 0, m - 1) {
                cout << ".";
            }
            if (i % 4 == 1) {
                cout << "#";
            }
            cout << endl;
        }
    }
}