#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 10;
int f[N][5];
pair<int, int> tr[N][5];

bool minimize(int &x, int y) {
    if (x > y) x = y; else return 0;
    return 1;
}
int main() { 

    int test;
    cin >> test;
    while (test--) { 
        string s;
        cin >> s;
        int n = s.length();
        s = "@" + s;

        for(int j = 1; j < 5; j++) f[0][j] = n + 1;
        for(int j = 1; j < s.length(); j++) { 
            char ch = s[j];
            for(int i = 0; i < 5; i++) {
                f[j][i] = f[j - 1][i] + 1;
                tr[j][i] = {i, 1};
            }
            if (ch == 'o') {
                for(int i = 0; i <= 4; i++) if (i != 4)
                    if (minimize(f[j][1], f[j - 1][i]))
                        tr[j][1] = {i, 0};
            } else if (ch == 'n') {
                if (minimize(f[j][2], f[j - 1][1]))
                    tr[j][2] = {1, 0};
                for(int i = 0; i <= 4; i++) if (i != 1)
                    if (minimize(f[j][0], f[j - 1][i]))
                        tr[j][0] = {i, 0};
            }  else if (ch == 'e') {
                for(int i = 0; i <= 4; i++) if (i != 2)
                    if (minimize(f[j][0], f[j - 1][i]))
                        tr[j][0] = {i, 0};
            } 
            else if (ch == 't') {

                for(int i = 0; i <= 4; i++) 
                    if (minimize(f[j][3], f[j - 1][i]))
                        tr[j][3] = {i, 0};

            } else if (ch == 'w') {
                if (minimize(f[j][4], f[j - 1][3]))
                    tr[j][4] = {3, 0};
                for(int i = 0; i <= 4; i++) if (i != 3)
                    if (minimize(f[j][0], f[j - 1][i]))
                        tr[j][0] = {i, 0};
            } else {
                for(int i = 0; i <= 4; i++) 
                    if (minimize(f[j][0], f[j - 1][i]))
                        tr[j][0] = {i, 0};
            }
            //for(int i = 0; i < 5; i++) cout << f[j][i] << " "; cout << endl;
        }
        int pos = min_element(f[n], f[n] + 5) - f[n];
        cout << f[n][pos] << '\n';

        vector<int> ans;
        for(int i = n; i >= 1; i--) {
            if (tr[i][pos].second) ans.push_back(i);
            pos = tr[i][pos].first;
        }
        //reverse(ans.begin(), ans.end());
        for(auto i : ans) cout << i << " ";
        cout << '\n';
    }
}