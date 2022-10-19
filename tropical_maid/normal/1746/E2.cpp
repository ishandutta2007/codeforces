#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

const int N = 30;
int dp[N + N + 5][N + N + 5];
int nS[N + N + 5][N + N + 5];
int nF[N + N + 5][N + N + 5];
bool vis[N + N + 5][N + N + 5];

int get(int s, int f) {
    if (vis[s][f]) return 100;
    if (s + f <= 2 || dp[s][f] > 0) return dp[s][f];
    vis[s][f] = true;
    dp[s][f] = 100;
    for (int s1 = 0; s1 <= s; ++s1) {
        for (int f1 = 0; f1 < max(f, 1); ++f1) {
            int x = max(get(s1 + f - f1, s - s1), get(s - s1 + f1, s1)) + 1;
            if (x < dp[s][f]) nS[s][f] = s1, nF[s][f] = f1, dp[s][f] = x;
        }
    }
    vis[s][f] = false;
    return dp[s][f];
}

int main() {
    ios_base::sync_with_stdio(0);
    dp[2][1] = 2;
    vector<int> S, F;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) S.push_back(i);
    while (S.size() + F.size() > 2) {
        vector<int> S2[2], F2[2];
        if (int(S.size()) <= N && int(F.size()) <= N) {
            get(S.size(), F.size());
            for (int i = 0; i < int(S.size()); ++i) {
                S2[i < nS[S.size()][F.size()]].push_back(S[i]);
            }
            for (int i = 0; i < int(F.size()); ++i) {
                F2[i < nF[S.size()][F.size()]].push_back(F[i]);
            }
        }
        else {
            for (int i = 0; i < int(S.size()); ++i) {
                S2[i % 2].push_back(S[i]);
            }
            for (int i = 0; i < int(F.size()); ++i) {
                F2[i % 2].push_back(F[i]);
            }
        }
        cout << "? " << (S2[0].size() + F2[1].size());
        for (int i : S2[0]) cout << ' ' << i;
        for (int i : F2[1]) cout << ' ' << i;
        cout << endl;
        string s;
        cin >> s;
        S.clear();
        F.clear();
        if (s[0] == 'Y') {
            for (int i : S2[0]) S.push_back(i);
            for (int i : S2[1]) F.push_back(i);
            for (int i : F2[1]) S.push_back(i);
        }
        else {
            for (int i : S2[1]) S.push_back(i);
            for (int i : S2[0]) F.push_back(i);
            for (int i : F2[0]) S.push_back(i);
        }
    }
    for (int i : S) {
        cout << "! " << i << endl;
        string s;
        cin >> s;
        if (s[1] == ')') return 0;
    }
    for (int i : F) {
        cout << "! " << i << endl;
        string s;
        cin >> s;
        if (s[1] == ')') return 0;
    }
    return 0;
}