#include <iostream>
#include <vector>
#include <set>

using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;

set<int> v;
set<pi> mv;

void dfs(int x) {
    vi tmp;
    for(int to : v) 
        if(mv.count({x, to}) == 0) tmp.push_back(to);
    for(int to : tmp) v.erase(to);
    for(int to : tmp) dfs(to);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; ++i) v.insert(i);
    for(int i = 1; i <= m; ++i) {
        int a, b; cin >> a >> b;
        mv.insert({a, b}), mv.insert({b, a});
    }

    int res = -1;
    for(int i = 1; i <= n; ++i) if(v.count(i)) ++res, v.erase(i), dfs(i);
    cout << res << endl;
}