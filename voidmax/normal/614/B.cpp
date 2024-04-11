#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second

using namespace std;

typedef long long base;
int n;
string now;
string rp = "1";
int zero;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        cin >> now;
        if (now == "0") {
            cout << 0 << endl;
            return 0;
        }
        while (now[(int)now.size() - 1] == '0') {
            ++zero; now.pop_back();
        }
        if (now.size() != 1 || now[0] != '1') {
            rp = now;
        }
    }
    cout << rp; For(i, 0, zero) cout << '0'; cout << endl;
}