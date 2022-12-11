#include <bits/stdc++.h>
#define int long long 

using namespace std;

const int N = 1007, K = 13;
vector <vector <int>> kek;
vector <int> q[K];
int res[K];

void gen(int pos, int k, vector <int> &cur) {
    if (pos == K) {
        if (k == 0) kek.push_back(cur);
        return;
    }
    gen(pos + 1, k, cur);
    if (k != 0) {
        cur.push_back(pos);
        gen(pos + 1, k - 1, cur);
        cur.pop_back();
    }
}

signed main() {
    vector <int> lol;
    gen(0, 6, lol);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int elem : kek[i]) q[elem].push_back(i);
    }
    for (int i = 0; i < K; i++) {
        if (!q[i].empty()) {
            cout << "? " << q[i].size();
            for (int elem : q[i]) cout << ' ' << elem + 1;
            cout << endl;
            cin >> res[i];
        } else {
            res[i] = 0;
        }
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int l = 0;
        for (int j = 0; j < K; j++) {
            if (l != (int) kek[i].size() && kek[i][l] == j) {
                l++;
                continue;
            }
            cur |= res[j]; 
        }
        cout << ' ' << cur;
    }
    cout << endl;
}