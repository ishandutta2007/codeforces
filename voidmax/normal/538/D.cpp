#include <cstdio>
#include <map>
#include <algorithm>
#include <set>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <vector>
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int n;
int arr[201][201];
bool ans[201][201];
vector <pair <int, int> > cango;
bool check1[201][201];
bool print[201][201];

int check(int x, int y) {
    For(i, -50, 51) {
        For(q, -50, 51) {
            if (arr[i + x][q + y] == 0) {
                ans[50 + i][50 + q] = 0;
            }
        }
    }
}

int color(int x, int y) {
    For(i, 0, cango.size()) {
        check1[x + cango[i].first][y + cango[i].second] = true;
        //if (x + cango[i].first - 50 >= 0 && y + cango[i].second - 50 >= 0) cout << x + cango[i].first - 50 << ' ' << y + cango[i].second - 50 << endl;
    }
}

main() {
    cin >> n;
    For(i, 0, 200) {
        For(q, 0, 200) {
            arr[i][q] = 1;
            ans[i][q] = 1;
        }
    }
    For(i, 0, n) {
        string s;
        cin >> s;
        For(q, 0, n) {
            if (s[q] == 'o') {
                arr[50 + i][50 + q] = 2;
            }
            else if (s[q] == 'x') {
                arr[50 + i][50 + q] = 1;
            }
            else {
                arr[50 + i][50 + q] = 0;
            }
        }
    }
    For(i, 0, 200) {
        For(q, 0, 200) {
            if (arr[i][q] == 2) {
                check(i, q);
            }
        }
    }
    For(i, -50, 51) {
        For(q, -50, 51) {
            if (ans[i + 50][q + 50]) {
                cango.push_back(make_pair(i, q));
            }
        }
    }
    For(i, 50, 105) {
        For(q, 50, 105) {
            if (arr[i][q] == 2) {
                color(i, q);
            }
        }
    }
    For(i, 0, n) {
        For(q, 0, n) {

            if (arr[i + 50][q + 50] == 1 && check1[i + 50][q + 50] == 0) {
                cout << "NO";
                return 0;
            }
        }
    }
    --n;
    int x = n, y = n;
    cout << "YES\n";
    For(i, -n, n + 1) {
        For(q, -n, n + 1) {
            if (i == 0 && q == 0) {
                cout << 'o';
            }
            else if (ans[50 + i][50 + q] == 1) {
                cout << 'x';
            }
            else {
                cout << '.';
            }
        }
        cout << endl;
    }
}