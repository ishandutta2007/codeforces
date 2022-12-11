#include <bits/stdc++.h>

using namespace std;

string dict = "AGCT";

const int N = 3e5 + 10;
string ans[N];
string a[N], b[N];

int n, m;
string s[N];
void solve() {
    ///altenate row
    for(int i = 0; i < n; i++) b[i].resize(m);
    for(int i = 0; i < n; i++) ans[i].resize(m);
    int answ = 0;
    for(int u1 = 0; u1 < 4; u1++)
        for(int u2 = u1 + 1; u2 < 4; u2++) {
            int u3 = 0;
            while (u3 == u1 || u3 == u2) u3++;
            int u4 = 6 - u1 - u2 - u3;
            int cans = 0;
            
            for(int i = 0; i < n; i++) { 
                vector<char> turn;
                if (i % 2) turn = {dict[u1], dict[u2]};
                else turn = {dict[u3], dict[u4]};  
                int w[2] = {0, 0};
                for(int j = 0; j < m; j++) {
                    for(int sw = 0; sw <= 1; sw++) {
                        w[sw] += s[i][j] == turn[(j % 2) ^ sw];
                    }
                }
                if (w[1] > w[0]) {
                    swap(turn[0], turn[1]);
                    swap(w[0], w[1]);
                }
                cans += w[0];
                for(int j = 0; j < m; j++) b[i][j] = turn[j % 2];
            }
            if (cans > answ) {
                answ = cans;
                for(int i = 0; i < n; i++) ans[i] = b[i];
            }
        }
    //for(int i = 0; i < n; i++) cout << ans[i] << '\n';
    ///altenate col
    for(int u1 = 0; u1 < 4; u1++)
        for(int u2 = u1 + 1; u2 < 4; u2++) {
            int u3 = 0;
            while (u3 == u1 || u3 == u2) u3++;
            int u4 = 6 - u1 - u2 - u3;
            int cans = 0;
            
            for(int j = 0; j < m; j++) { 
                vector<char> turn;
                if (j % 2) turn = {dict[u1], dict[u2]};
                else turn = {dict[u3], dict[u4]};  
                int w[2] = {0, 0};
                for(int i = 0; i < n; i++) {
                    for(int sw = 0; sw <= 1; sw++) {
                        w[sw] += s[i][j] == turn[(i % 2) ^ sw];
                    }
                }
                if (w[1] > w[0]) {
                    swap(turn[0], turn[1]);
                    swap(w[0], w[1]);
                }
                cans += w[0];
                for(int i = 0; i < n; i++) b[i][j] = (turn[i % 2]);
            }
            if (cans > answ) {
                answ = cans;
                for(int i = 0; i < n; i++) ans[i] = b[i];
            }
        }
    //for(int i = 0; i < n; i++) cout << ans[i] << '\n';
    ///shake row
    int p[4];
    for(int i = 0; i < 4; i++) p[i] = i;
    do {
        string pat[2];
        for(int i = 0; i < 4; i++) pat[0].push_back(dict[p[i]]);
        pat[1] = pat[0].substr(2, 2) + pat[0].substr(0, 2);
        int cans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) cans += s[i][j] == pat[i % 2][j % 4]; 
        if (cans > answ) {
            answ = cans;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++) ans[i][j] = pat[i % 2][j % 4];
        }
    }while (next_permutation(p, p + 4));
    for(int i = 0; i < 4; i++) p[i] = i;
    do {
        string pat[2];
        for(int i = 0; i < 4; i++) pat[0].push_back(dict[p[i]]);
        pat[1] = pat[0].substr(2, 2) + pat[0].substr(0, 2);
        int cans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) cans += s[i][j] == pat[j % 2][i % 4]; 
        if (cans > answ) {
            answ = cans;
            for(int i = 0; i < n; i++)
                for(int j = 0; j < m; j++) ans[i][j] = pat[j % 2][i % 4];
        }
    }while (next_permutation(p, p + 4));

    for(int i = 0; i < n; i++) cout << ans[i] << '\n';
}
int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) 
        cin >> s[i];
    solve();
}