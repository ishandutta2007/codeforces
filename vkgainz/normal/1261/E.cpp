#include <bits/stdc++.h>
using namespace std;

string ans[1001];
vector<int> a;
int k = 0;
int n;

void solve(int i, int j) {
    //[i...j] unfilled
    if(i == j) return;
    if(a[k] >= j - i) {
        //put 0, 1 in the others
        for(int x = i + 1; x <= j; x++) {
            ans[x][k] = '1';
            --a[k];
        }
        for(int x = 0; x <= n; x++) {
            if((x < i || x > j) && a[k]) {
                ans[x][k] = '1';
                --a[k];
            }
        }
        ++k;
        solve(i + 1, j);
    }
    else {
        int lst = i;
        for(int x = i; x <= j; x++) {
            if(a[k]) {
                ans[x][k] = '1';
                --a[k];
                lst = x;
            }
        }
        ++k;
        solve(i, lst);
        solve(lst + 1, j);
    }
}

int main() {
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << n + 1 << "\n";
    for(int i = 0; i < n + 1; i++)
        for(int j = 0; j < n; j++)
            ans[i] += '0';
    solve(0, n);
    for(int i = 0; i < n + 1; i++)
        cout << ans[i] << "\n";
}