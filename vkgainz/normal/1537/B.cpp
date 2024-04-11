#include <bits/stdc++.h>
using namespace std;

long long dist(pair<int, int> x, pair<int, int> y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, x, y; cin >> n >> m >> x >> y;
        vector<pair<int, int>> in(4);
        in[0] = {1, 1}, in[1] = {1, m}, in[2] = {n, 1}, in[3] = {n, m};
        long long ans = 0;
        pair<int, int> st = make_pair(x, y);
        pair<int, int> ret = {0, 0};
        for(int i  = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                if(dist(st, in[i]) + dist(in[i], in[j]) + dist(in[j], st) > ans) {
                    ans = dist(st, in[i]) + dist(in[i], in[j]) + dist(in[j], st);
                    ret = {i, j};
                }
            }
        }
        cout << in[ret.first].first << " " << in[ret.first].second << " " << in[ret.second].first << " " << in[ret.second].second << "\n";
    }
}