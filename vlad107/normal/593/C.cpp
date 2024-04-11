#include <stdio.h>
#include <vector>
#include <assert.h>
#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

string get_func(int c) {
    string res = "(t-" + to_string(c) + ")";
    res = "(" + res + "+" + "abs(" + res + "))";
    return res;
}

string solve(vector<int> a) {
    for (int i = 0; i < (int)a.size(); i++) if (a[i] & 1) a[i] ^= 1;
    string res = to_string(a[0]);
    for (int i = 1; i < (int)a.size(); i++) {
        string cur = "(" + get_func(i - 1) + "-" + get_func(i) + ")";
        int diff = (a[i] - a[i - 1])/2;
        string sdiff = diff >= 0 ? (to_string(diff)) : ("(0-" + to_string(-diff) + ")");
        cur = "(" + cur + "*" + sdiff + ")";
        res = "(" + res + "+" + cur + ")";
    }
    return res;
}

int main() {
    // freopen("input.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    vector<int> vx, vy;
    for (int i = 0; i < n; i++) {
        int x, y, r;
        scanf("%d%d%d", &x, &y, &r);
        vx.push_back(x);
        vy.push_back(y);
    }
    cout << solve(vx) << endl;
    cout << solve(vy) << endl;
}