#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define x first
#define y second
#define point pair <int, bool>
#define dir second
#define mp make_pair
using namespace std;

int n, m, counter;
char arr[100][100];
bool used[100];

int check(int i, int q) {
    For(j, 0, m) {
        if (!used[j]) {
            if (arr[i][j] > arr[q][j]) {
                return j;
            }
            if (arr[i][j] < arr[q][j]) {
                return -1;
            }
        }
    }
    return -1;
}

main() {
    //freopen("learning.in", "r", stdin);
    //freopen("learning.out", "w", stdout);
    cin >> n >> m;
    For (i, 0, n) {
        For (q, 0, m) {
            cin >> arr[i][q];
        }
    }
    bool change = true;
    while (change) {
        change = false;
        For (i, 0, n) {
            For (q, i + 1, n) {
                int ans = check(i, q);
                if (ans != -1) {
                    used[ans] = true;
                    change = true;
                    --q;
                    ++counter;
                }
            }
        }
    }
    cout << counter;
}