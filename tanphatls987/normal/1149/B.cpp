#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
const int maxL = 256;
const int alp = 26;

int n;
int nextCh[N][alp];
string pat;
int f[maxL][maxL][maxL];
string s[3]; 

bool minimize(int &x, int y) {
    if (x > y) x = y; else return 0;
    return 1;
}
void calculate(int i0, int i1, int i2) {
    if (i0 == 0 && i1 == 0 && i2 == 0) return;
    int &ans = f[i0][i1][i2]; ans = n + 1;
    if (i0 > 0) 
        minimize(ans, nextCh[f[i0 - 1][i1][i2]][s[0][i0 - 1] - 'a'] + 1);
    if (i1 > 0) 
        minimize(ans, nextCh[f[i0][i1 - 1][i2]][s[1][i1 - 1] - 'a'] + 1);
    if (i2 > 0) 
        minimize(ans, nextCh[f[i0][i1][i2 - 1]][s[2][i2 - 1] - 'a'] + 1);
}
int main() {
    int test;
    cin >> n >> test >> pat;
    for(int i = 0; i < alp; i++) nextCh[n][i] = nextCh[n + 1][i] = n; 
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < alp; j++) nextCh[i][j] = nextCh[i + 1][j];
        nextCh[i][pat[i] - 'a'] = i;
    }
    while (test--) {
        char ch; int pos;
        cin >> ch >> pos; pos--;
        if (ch == '-') s[pos].pop_back();
        else {
            char use; cin >> use;
            s[pos].push_back(use);
            for(int i0 = (pos == 0) * s[0].length(); i0 <= s[0].length(); i0++) 
                for(int i1 = (pos == 1) * s[1].length(); i1 <= s[1].length(); i1++)
                    for(int i2 = (pos == 2) * s[2].length(); i2 <= s[2].length(); i2++) 
                        calculate(i0, i1, i2);
        }
        //cout << f[s[0].length()][s[1].length()][s[2].length()] << '\n';
        cout << (f[s[0].length()][s[1].length()][s[2].length()] <= n ? "YES\n" : "NO\n");
    }
}