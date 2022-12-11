#include <iostream>
#include <vector>

using namespace std;

const long long MAX_L = 1005, M = 1e9 + 7;
long long c_n_k[MAX_L][MAX_L];
int num[MAX_L];
vector <int> use;

int calc_one(int n) {
    int ans = 0;
    for (int i = 1; i <= 2000; i *= 2) {
        if ((n & i) != 0) ans++;
    }
    return ans;
}

int rec(int n) {
    if (n == 1) return 0;
    return rec(calc_one(n)) + 1;
}

void init() {
    for (int i = 0; i < MAX_L; i++) {
        for (int j = 0; j < MAX_L; j++) {
            c_n_k[i][j] = 0;
        }
    }
    c_n_k[0][0] = 1;
    for (int i = 1; i < MAX_L; i++) {
        for (int j = 0; j < MAX_L; j++) {
            c_n_k[i][j] = c_n_k[i - 1][j];
            if (j > 0) c_n_k[i][j] = (c_n_k[i][j] + c_n_k[i - 1][j - 1]) % M;
        }
    }
    for (int i = 1; i < MAX_L; i++) {
        num[i] = rec(i);
        //if (i <= 16) cout << i << ' ' << num[i] << endl;
    }
}

long long calc_ans(string s, int n, int k) {
    long long ans = 0;
    int new_k;
    for (int elem : use) {
        /*for (int i = 1; i < n; i++) {
            ans = (ans + c_n_k[i][elem]) % M;
        }*/
        //cout << ans << endl;
        new_k = elem;
        for (int i = 0; i < n; i++) {
            if (new_k < 0) break;
            if (s[i] == '0') continue;
            ans = (ans + c_n_k[n - i - 1][new_k]) % M;
            new_k--;
        }
        if (k == elem) ans = (ans + 1) % M;
    }
    return ans;
}

int main() {
    init();
    string s;
    int k, n;
    cin >> s >> k;
    n = s.length();
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }
    int ones = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') ones++;
    }
    for (int i = 1; i < MAX_L; i++) {
        if (num[i] == k - 1) use.push_back(i);
    }
    if (k == 1) {
        cout << n - 1 << endl;
        return 0;
    }
    cout << calc_ans(s, n, ones) << endl;
    return 0;
}