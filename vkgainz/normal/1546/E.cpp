#include <bits/stdc++.h>
using namespace std;

vector<bool> still_in;
vector<vector<int>> in;

void del(int ii, int n) {
    for (int j = 0; j < 2 * n; j++) {
        if (!still_in[j]) continue;
        bool clash = false;
        for (int i = 0; i < n; i++)
            if (in[j][i] == in[ii][i]) {
                clash = true;
                break;
            }
        if (clash) 
            still_in[j] = false;
    }
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        in.clear();
        in.resize(2 * n, vector<int>(n));
        for(int i = 0; i < 2 * n; i++)
            for(int j = 0; j < n; j++) 
                cin >> in[i][j], --in[i][j];
        vector<vector<int>> num(n);
        int ans = 1;
        vector<int> choose;
        still_in.clear();
        still_in.resize(2 * n, true);
        while ((int) choose.size() < n) {
            vector<int> temp;
            for (int col = 0; col < n; col++) {
                vector<int> occ(n), lst(n);
                for (int row = 0; row < 2 * n; row++) {
                    if (!still_in[row]) continue;
                    ++occ[in[row][col]];
                    lst[in[row][col]] = row;
                }
                for (int i = 0; i < n; i++) {
                    if (occ[i] == 1)
                        temp.push_back(lst[i]);
                }
            }
            sort(temp.begin(), temp.end());
            auto last = unique(temp.begin(), temp.end());
            temp.erase(last, temp.end());
            if (temp.empty()) {
                ans *= 2;
                ans %= 998244353;
                for (int row = 0; row < 2 * n; row++) 
                    if(still_in[row]) {
                        del(row, n);
                        choose.push_back(row);
                        break;
                    }
            }
            else {
                for (auto &it : temp)
                    del(it, n);
                choose.insert(choose.end(), temp.begin(), temp.end());
            }
        }
        cout << ans << "\n";
        for (auto &it : choose) cout << it + 1 << " ";
        cout << "\n";
    }
}