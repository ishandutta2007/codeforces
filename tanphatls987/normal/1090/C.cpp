#include <bits/stdc++.h>

using namespace std;

int n, m;

const int N = 5e5 + 10;

int h[2][N];
set<int> trans;
set<int> mse[N];

int ansn = 0;
int ans[N][3];
void modifiedL(int x, int val) {
    if (h[0][x] == 0 && h[1][x]) trans.erase(x);
    h[0][x] += val;
    if (h[0][x] == 0 && h[1][x]) trans.insert(x);
}
void modifiedR(int x, int val) {
    if (h[0][x] == 0 && h[1][x]) trans.erase(x);
    h[1][x] += val;
    if (h[0][x] == 0 && h[1][x]) trans.insert(x);
}
void give(int x, int y, int pos) {
    mse[y].insert(pos);
    mse[x].erase(pos);
    modifiedR(pos, -1);
    modifiedL(pos, 1);
    ++ansn;
    ans[ansn][0] = x, ans[ansn][1] = y, ans[ansn][2] = pos;
}
int per[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    int sumg = 0;
    for(int i = 1; i <= n; i++) {
        int n1;
        cin >> n1;
        sumg += n1;
        while (n1--) {
            int x;
            cin >> x;
            mse[i].insert(x);
        }
    }

    int modn = sumg % n;
    for(int i = 1; i <= n; i++) per[i] = i;
    sort(per + 1, per + n + 1,[](int x, int y) {
            return mse[x].size() < mse[y].size();
        });

    for(auto use : mse[per[n]]) 
        modifiedR(use, 1);
    for(auto use : mse[per[1]])
        modifiedL(use, 1);
    for(int i = 1, j = n; i < j;) {
        //cout << i << " " << j << " " <<mse[per[i]].size() << " " << 
            //mse[per[j]].size() << '\n';
        int tarj = sumg / n;
        if (n - j + 1 <= modn) tarj++;
        if (mse[per[j]].size() == tarj) {
            for(auto use : mse[per[j]])
                modifiedR(use, -1);
            j--;
            for(auto use : mse[per[j]])
                modifiedR(use, 1);
            continue;
        }
        int tari = sumg / n;
        if (n - i + 1 <= modn) tari++;
        if (mse[per[i]].size() == tari) {
            for(auto use : mse[per[i]])
                modifiedL(use, -1);
            i++;
            for(auto use : mse[per[i]])
                modifiedL(use, 1);
            continue;
        }
        give(per[j], per[i], (*trans.begin()));
    }
    cout << ansn << '\n';
    for(int i = 1; i <= ansn; i++)  {
        for(int j = 0; j < 3; j++) cout << ans[i][j] << " ";
        cout << '\n';
    }
}