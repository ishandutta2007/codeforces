#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt = 0;
int ask(int b, int i, int j) {
    cout << b << " " << i << " " << j << endl;
    if(--cnt == 0) exit(0);
    int ret;
    cin >> ret;
    return ret;
}
int main() {
    int n;
    cin >> n;
    cnt = n * n;
    vector<pair<int,int>> v1, v2;
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= n; ++j) {
            if((i + j) & 1) v1.push_back({i, j});
            else v2.push_back({i, j});
        }
    }
    int p;
    cin >> p;
    for(int i = 0; i < n * n; ++i) {
        if(p == 1) {
            if(!v2.empty()) {
                auto cur = v2.back(); v2.pop_back();
                p = ask(2, cur.first, cur.second);
            } else {
                auto cur = v1.back(); v1.pop_back();
                p = ask(3, cur.first, cur.second);
            }
        }
        if(p == 2) {
            if(!v1.empty()) {
                auto cur = v1.back(); v1.pop_back();
                p = ask(1, cur.first, cur.second);
            } else {
                auto cur = v2.back(); v2.pop_back();
                p = ask(3, cur.first, cur.second);
            }
        }
        if(p == 3) {
            if(!v2.empty()) {
                auto cur = v2.back(); v2.pop_back();
                p = ask(2, cur.first, cur.second);
            } else {
                auto cur = v1.back(); v1.pop_back();
                p = ask(1, cur.first, cur.second);
            }
        }
    }

}