#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
vector<string> v[maxn];
unordered_map<string, int> to;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    string s; getline(cin, s);
    for (int i = 0; i < n; ++i) {
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s) v[i].push_back(s);        
    }
    string ans1 = "", ans2 = "";
    for (int j = 0; j < m; ++j) {
        int z[2] = { 0, 0 };
        for (int k = 0; k < 2; ++k) {
            for (int i = 0; i < n; ++i) {
                if (v[i].size() == 3) {
                    if (v[i][2] == "?") {
                        z[k] += k;
                        to[v[i][0]] = k;
                        continue;
                    }
                    z[k] += (v[i][2][j] == '1');
                    to[v[i][0]] = (v[i][2][j] == '1');
                } else {
                    int a = -1, b = -1;
                    if (v[i][2] == "?") a = k;
                    else if (v[i][2][0] >= 'a' && v[i][2][0] <= 'z') a = to[v[i][2]];
                    else a = (v[i][2][j] == '1');
                    if (v[i][4] == "?") b = k;
                    else if (v[i][4][0] >= 'a' && v[i][4][0] <= 'z') b = to[v[i][4]];
                    else b = (v[i][4][j] == '1');
                    if (v[i][3] == "XOR") z[k] += (a ^ b), to[v[i][0]] = (a ^ b);
                    else if (v[i][3] == "OR") z[k] += (a | b), to[v[i][0]] = (a | b);
                    else if (v[i][3] == "AND") z[k] += (a & b), to[v[i][0]] = (a & b);
                }
            }
        } 
        if (z[0] > z[1]) ans1 += '1';
        else ans1 += '0';
        if (z[1] > z[0]) ans2 += '1';
        else ans2 += '0';
    } 
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}