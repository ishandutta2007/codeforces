#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    map<pair<int,int>, char> mp;
    int same_cnt = 0, double_cnt = 0;
    for(int i = 1; i <= m; ++i) {
        char op;
        cin >> op;
        if(op == '+') {
            int u, v;
            char c;
            cin >> u >> v >> c;
            mp[{u, v}] = c;
            if(mp.count({v, u})) {
                double_cnt++;
                if(mp[{v, u}] == c) same_cnt++;
            }
        } else if(op == '-') {
            int u, v;
            cin >> u >> v;
            if(mp.count({u, v}) && mp.count({v, u})) {
                double_cnt--;
                if(mp[{u, v}] == mp[{v, u}]) same_cnt--;
            }
            mp.erase({u, v});
        } else {
            int k;
            cin >> k;
            if(same_cnt || (k % 2 == 1 && double_cnt)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
//        cout << double_cnt << " " << same_cnt << endl;
    }
}