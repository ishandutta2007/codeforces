#include <bits/stdc++.h>
using namespace std;

vector<int> gen(int x) {
    vector<int> vec;
    int i = (x / 50) % 475;
    for (int j = 0; j < 25; ++j) {
        i = (i * 96 + 42) % 475;
        vec.push_back(26 + i);
    }
    return vec;
}

int main() {
    int p, x, y; cin >> p >> x >> y;
    int cnt = 0;
    while (x < y) {
        vector<int> vec = gen(y);
        for (int i : vec) if (i == p) return cout << cnt << endl, 0;
        x += 100; cnt++; 
    }
    if (x > y) {
        int t = 1;
        while (x - 50 * t >= y) {
            vector<int> vec = gen(x - 50 * t);
            for (int i : vec) if (i == p) return cout << cnt << endl, 0;
            ++t;
        }
    }
    while (true) {
        vector<int> vec = gen(x);
        for (int i : vec) if (i == p) return cout << cnt << endl, 0;
        if (x - 50 > y) {
            vector<int> vec = gen(x - 50);
            for (int i : vec) if (i == p) return cout << cnt << endl, 0;
        }
        x += 100; cnt++;
    }
    return 0;
}