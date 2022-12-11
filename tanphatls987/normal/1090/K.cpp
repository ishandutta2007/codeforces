#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
map<int, int> gr;
int n;
string s[N];
vector<vector<int>> ans;
vector<int> v[N];
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        int mask = 0;
        for(auto ch : s2) mask |= 1 << (ch - 'a');

        if (!gr[mask]) 
            gr[mask] = gr.size();

        while (!s1.empty() && (mask & (1 << (s1.back() - 'a')))) s1.pop_back();
        s[i] = s1;
        v[gr[mask]].push_back(i);
        //cout << mask << " " << s[i] << '\n';
    }

    for(int i = 1; i <= gr.size(); i++) {
        sort(v[i].begin(), v[i].end(),[](int x, int y) {
                return s[x] < s[y];
            });

        for(int en = 0; en < v[i].size(); ) {
            int st = en;
            while (en < v[i].size() && s[v[i][en]] == s[v[i][st]]) en++;
            ans.push_back(vector<int>());
            for(int j = st; j < en; j++) {
                ans.back().push_back(v[i][j]);
            }
        }
    }

    cout << ans.size() << '\n';
    for(auto i : ans) {
        cout << i.size() << " ";
        for(auto j : i) cout << j << " ";
        cout << '\n';
    }
}