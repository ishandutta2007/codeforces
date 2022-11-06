#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
#define For(i, a, b) for (int i = a; i < b; ++i)
#define L first
#define B second
#define point pair <int, int>
#define int long long

using namespace std;

int arr[27][27];
bool used[27];
int n;
string a, b;
vector <string> check;

main() {
    cin >> n;
    cin >> b;
    check.push_back(b);
    For(i, 0, n - 1) {
        cin >> a;
        check.push_back(a);
        swap(a, b);
        if (a.size() < b.size()) {
            For(q, 0, a.size()) {
                if (a[q] != b[q]) {
                    if (arr[a[q] - 'a'][b[q] - 'a'] == 1) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                    arr[a[q] - 'a'][b[q] - 'a'] = -1;
                    arr[b[q] - 'a'][a[q] - 'a'] = 1;
                    break;
                }
            }
        }
        else {
            bool OK = false;
            For(q, 0, b.size()) {
                if (a[q] != b[q]) {
                    if (arr[a[q] - 'a'][b[q] - 'a'] == 1) {
                        cout << "Impossible" << endl;
                        return 0;
                    }
                    arr[a[q] - 'a'][b[q] - 'a'] = -1;
                    arr[b[q] - 'a'][a[q] - 'a'] = 1;
                    OK = true;
                    break;
                }
            }
            if (!OK) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    string ans;
    For(i, 0, 26) {
        For(q, 0, 26) {
            if (!used[q]) {
                bool OK = true;
                For(j, 0, 26) {
                    if (arr[q][j] == 1) {
                        OK = false;
                        break;
                    }
                }
                if (OK) {
                    ans += 'a' + q;
                    used[q] = true;
                    For(j, 0, 26) {
                        arr[j][q] = 0;
                    }
                    break;
                }
            }
        }
    }
    if (ans.size() != 26) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << ans;
}