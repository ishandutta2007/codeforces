#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int n, k;
        cin >> n >> k;
        int len = n - 2 * (k - 1);
        string tar = string(len / 2, '(') + string(len / 2, ')');
        for(int i = 0; i < k - 1; i++) 
            tar = tar + "()";
        string s;
        cin >> s;

        vector<ii> ans;
        for(int i = 0; i < n; i++) if (s[i] != tar[i]) {
            int j = i + 1;
            while (s[j] != tar[i]) j++;
            reverse(s.begin() + i, s.begin() + j + 1); 
            ans.push_back(ii(i + 1, j + 1));
        }
        cout << ans.size() << '\n';
        for(auto i : ans) cout << i.first << " " << i.second << '\n';
    }
}