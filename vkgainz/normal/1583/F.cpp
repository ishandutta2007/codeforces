#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int len = 0;
    int tmp = n - 1;
    while (tmp) {
        tmp /= k;
        ++len;
    }
    cout << len << "\n";
    vector<vector<int>> sto(n);
    sto[0] = {0};
    vector<vector<int>> color(n, vector<int>(n));
    for (int i = 1; i < n; i++) { //node i gets labeled with i base k
        tmp = i;
        while (tmp) {
            sto[i].push_back(tmp % k);
            tmp /= k;
        }
        reverse(sto[i].begin(), sto[i].end());
        for (int j = i - 1; j >= 0; j--) {
            if (sto[i].size() > sto[j].size()) {
                color[j][i] = sto[i].size();
            } else {
                for (int r = 0; r < sto[i].size(); r++) { 
                    if (sto[i][r] > sto[j][r]) {
                        color[j][i] = sto[i].size() - r;
                    }
                }

            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << color[i][j] << " ";
        }
    }
    cout << "\n";
}