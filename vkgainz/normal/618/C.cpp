#include <bits/stdc++.h>
using namespace std;

struct pt {
    int x, y, idx;
};

bool cmp(pt &a, pt &b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

bool line(pt a, pt b, pt c) {
    long long r = a.x * 1LL * (b.y - c.y) + b.x * 1LL * (c.y - a.y) + c.x * 1LL * (a.y - b.y);
    return r != 0;
}

int main() {
    int n; cin >> n;
    vector<pt> in(n);
    for(int i = 0; i < n; i++) {
        cin >> in[i].x >> in[i].y;
        in[i].idx = i;
    }
    sort(in.begin(), in.end(), cmp);
    for(int i = 2; i < n; i++) {
        if(line(in[0], in[1], in[i])) {
            cout << in[0].idx + 1 << " " << in[1].idx + 1 << " " << in[i].idx + 1<< "\n";
            return 0;
        }
    }
}