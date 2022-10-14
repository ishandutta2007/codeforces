// eh whatever ill just copy code for this shit
#include <bits/stdc++.h>
#define long long long int
using namespace std;
 
// @author: pashka
 
void solve_test() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n * m; i++) {
        a[i].second = -a[i].second;
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        sort(a.begin() + (m * i), a.begin() + (m * i + m));
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < j; k++) {
                if (a[i * m + k].second > a[i * m + j].second) res++;
            }
        }
    }
    cout <<res << "\n";
}
 
int main() {
    ios::sync_with_stdio(false);
 
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve_test();
    }
 
    return 0;
}