
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <utility>
using namespace std;

int main () {

    set<int> st;
    map<int, int> mp;
  map<int, int> rmp;
    vector<pair<int, int> > src;
    int m, k;
    cin >> m >> k;
    int mp_sz = 0;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        st.insert(a);
        st.insert(b);
        if (mp.find(a) == mp.end()) {
            mp[a] = mp_sz;
            rmp[mp_sz] = a;
            ++mp_sz;
        }
        if (mp.find(b) == mp.end()) {
            mp[b] = mp_sz;
            rmp[mp_sz] = b;
            ++mp_sz;
        }
        src.push_back(make_pair(mp[a], mp[b]));
    }
    int n = mp_sz;
    vector<vector<int> > mat(n, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
            mat[src[i].first][src[i].second] = mat[src[i].second][src[i].first] = 1;
    }
    vector<vector<int> > answer(n);
    for (int i = 0; i < n; ++i) {
        int amt = 0;
        for (int j = 0; j < n; ++j) {
            amt += mat[i][j];
        }
        for (int j = 0; j < n; ++j) {
            if (i != j && mat[i][j] == 0){
                int cur = 0;
                for (int t = 0; t < n; ++t) {
                    if (t != i && t != j) {
                        if (mat[i][t] && mat[t][j]) {
                            ++cur;
                        }
                    }
                }
                if (cur * 100 >= k * amt) { //%
                    answer[i].push_back(j);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < answer[i].size(); ++j) {
            answer[i][j] = rmp[answer[i][j]];
        }
        if (!answer[i].empty()) {
            sort(answer[i].begin(), answer[i].end());
        }
    }
    vector<int> prn(st.begin(), st.end());
    for (int i = 0; i < st.size(); ++i) {
        int cur = mp[prn[i]];
        cout << prn[i] << ": " << answer[cur].size();
        for (int j = 0; j < answer[cur].size(); ++j) {
            cout << " " << answer[cur][j];
        }
        cout << "\n";

    }
    return 0;
}