#include <bits/stdc++.h>

using namespace std;

int n, w[24];
int lg2[1 << 24];
vector<int> v[30];
bitset<1 << 24> f;
vector<int> rv[30];
void DFS(int sum, int mask, int pos) {
    if (sum > n - 1) return;
    if (pos == n + 1) return;
    int nsum = sum;
    int nmask = mask;

    DFS(sum, mask, pos + 1);
    for(auto use : v[pos]) {
        nmask |= 1 << use; 
        nsum += pos;
        if (nsum > n) break;
        if ((nmask & -nmask) != nmask) {
            rv[nsum].push_back(nmask);
            //cout << nmask << " " << nsum << '\n';
        }
        DFS(nsum, nmask, pos + 1);
    }
}
void DFS2(int sum, int mask, int use) {
    if (use == n) return;
    DFS2(sum, mask, use + 1);
    sum += w[use];
    mask |= 1 << use;
    if (sum < n){
        if ((mask & -mask) != mask)
            rv[sum].push_back(mask);
        DFS2(sum, mask, use + 1);
    }
}
int main() {
    cin >> n;
    for(int i = 0; i < n; i++) cin >> w[i];
    sort(w, w + n);
    for(int i = 0; i < n; i++) 
        v[w[i]].push_back(i);
    //DFS(0, 0, 1);
    DFS2(0, 0, 0);
    

    for(int i = 2; i < (1 << n); i++) 
        lg2[i] = lg2[i / 2] + 1;

    int st = 0;
    while (st < n && w[st] == 1) st++;
    f[(1 << st) - 1] = 1;
    for(int i = (1 << st) - 1; i < (1 << (n - 1)); i++) if (f[i]) {
        int cur = lg2[i] + 1;
        //cout << i << '\n';
        for(auto j : rv[w[cur] - 1]) if ((j & i) == j)
            f[(i ^ j) | (1 << cur)] = 1; 
    }
    cout << (f[1 << (n - 1)] ? "YES" : "NO");
}