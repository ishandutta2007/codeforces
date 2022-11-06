#include <bits/stdc++.h>
using namespace std;

const int maxn = 120 + 5;
int a[5][maxn], ac[5], n;

bool check(int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n; 
    for (int i = 0; i < n; ++i) for (int j = 0; j < 5; ++j) cin >> a[j][i];
    for (int i = 0; i < 5; ++i) for (int j = 0; j < n; ++j) {
        if (a[i][j] != -1) ac[i]++;
    }
    for (int bot = 0; bot < 500000; ++bot) {
        if (check(bot)) return cout << bot << '\n', 0;
    }
    cout << "-1\n";
    return 0;
}

bool check(int bot) {
    int tot = n + bot;
    vector<int> solve(ac, ac + 5), par;
    // for (int i = 0; i < 5; ++i) par.push_back(n);
    for (int p = 0; p < 5; ++p) {
        if (a[p][0] == -1) continue;
        if (a[p][1] == -1) continue;
        if (a[p][0] < a[p][1]) continue;
        solve[p] += bot;
    }
    int score[2] = {0, 0};
    for (int p = 0; p < 5; ++p) {
        double per = (double)solve[p] / (double)tot;
        int sc = 0;
        if (per > 0.5) sc = 500;
        else if (per > 0.25) sc = 1000;
        else if (per > 0.125) sc = 1500;
        else if (per > 0.0625) sc = 2000;
        else if (per > 0.03125) sc = 2500;
        else sc = 3000;
        for (int i = 0; i < 2; ++i) if (a[p][i] != -1) {
            score[i] += (int)((double)sc * ((double)1 - (double)a[p][i] / (double)250));
        }
    }
    return score[0] > score[1];
}