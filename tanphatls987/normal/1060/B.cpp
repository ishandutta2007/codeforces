#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9 + 10;
int f[100][2];
int DFS(const vector <int> &a, int pos, int add){
    if (pos == a.size()) {
        if (add == 1) return -inf;
        return 0;
    }
    int &ans = f[pos][add];
    if (ans != -1) return ans;
    int cur = a[pos] - add;
    ans = 0;
    for(int use = 0; use <= 1; use++){
        int rcur = cur + 10 * use;
        if (rcur < 0 || rcur >= 19) continue;
        ans = max(ans, DFS(a, pos + 1, use) + rcur);
    }
    return ans;
}
int main() {
    long long n;
    cin >> n;
    vector <int> a;
    while (n) { 
        a.push_back(n % 10);
        n /= 10;
    }
    memset(f, -1, sizeof(f));
    cout << DFS(a, 0, 0);
}