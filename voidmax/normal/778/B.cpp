#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".in").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long long base;

int n, m;
string s[5001];
string sol[5001];
int dp[5001][2];
map <string, int> num;
pair <pair <int, int>, int> func[5001];
bool ans[5001][2];

int f(int a, int b, int c) {
    if (c == 0) {
        return a & b;
    }
    if (c == 1) {
        return a | b;
    }
    return a ^ b;
}

void check(int j) {
    int cnt[2] = {0, 0};
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (sol[i].size()) {
            dp[i][0] = sol[i][j] - '0';
            dp[i][1] = sol[i][j] - '0';
        } else {
            dp[i][0] = f(dp[func[i].x.x][0], dp[func[i].x.y][0], func[i].y);
            dp[i][1] = f(dp[func[i].x.x][1], dp[func[i].x.y][1], func[i].y);
            cnt[0] += dp[i][0];
            cnt[1] += dp[i][1];
        }
    }
    if (cnt[0] <= cnt[1]) {
        ans[j][0] = 0;
    } else {
        ans[j][0] = 1;
    }
    if (cnt[0] >= cnt[1]) {
        ans[j][1] = 0;
    } else {
        ans[j][1] = 1;
    }
    //cout << cnt[0] << ' ' << cnt[1] << endl;
}

int main() {
    srand(time(0));
    ios::sync_with_stdio(0);
    //read(FileName);
    cin >> n >> m;
    num["?"] = 0;
    for (int i = 1; i <= n; ++i) {
        string res;
        cin >> res;
        num[res] = i;
        cin >> res;
        cin >> res;
        if (res[0] == '0' || res[0] == '1') {
            sol[i] = res;
        } else {
            pair <pair <int, int>, int> k;
            k.x.x = num[res];
            cin >> res;
            if (res == "AND") k.y = 0;
            if (res == "OR") k.y = 1;
            if (res == "XOR") k.y = 2;
            cin >> res;
            k.x.y = num[res];
            //cout << k.x.x << ' ' << k.x.y << ' ' << k.y << endl;
            func[i] = k;
        }
    }
    for (int i = 0; i < m; ++i) {
        check(i);
    }
    for (int i = 0; i < m; ++i) cout << ans[i][0]; cout << endl;
    for (int i = 0; i < m; ++i) cout << ans[i][1]; cout << endl;
}