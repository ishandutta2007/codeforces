#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
vector <int> incomp[N];
vector <int> g[N];
int color[N], comp[N], rv[N], sz[N], calc[N];
int shure = 0, add = 0;
bool fix[N];

void make_all(int v, int val) {
    if (fix[v]) return;
    int c = comp[v];
    int was = color[v];
    for (int elem : incomp[c]) {
        int realcolor = color[elem] ^ rv[c];
        if (realcolor) add--;
        if (color[elem] == was) color[elem] = val;
        else color[elem] = val ^ 1;
        if (color[elem]) shure++;
        fix[elem] = 1;
        //cout << "! " << elem << ' ' << color[elem] << endl;
    }
}

void merge(int a, int b, int rev) {
    //cout << a << ' ' << b << ' ' << rev << endl;
    if (fix[a]) {
        make_all(b, color[a] ^ rev);
        return;
    }
    if (fix[b]) {
        make_all(a, color[b] ^ rev);
        return;
    }
    int c1 = comp[a], c2 = comp[b];
    if (c1 == c2) return;
    if (sz[c1] < sz[c2]) {
        swap(c1, c2);
        swap(a, b);
    }
    int was = color[b];
    int nbcolor = color[a] ^ rev;
    for (int elem : incomp[c2]) {
        incomp[c1].push_back(elem); 
        int realcolor = color[elem] ^ rv[c2];
        add -= realcolor;
        if (color[elem] == was) color[elem] = nbcolor;
        else color[elem] = nbcolor ^ 1;
        if (color[elem] ^ rv[c1]) add++, calc[c1]++;
        comp[elem] = c1;
    }
    incomp[c2].clear();
    incomp[c2].shrink_to_fit();
    sz[c1] += sz[c2];
    //cout << sz[c1] << ' ' << calc[c1] << ' ' << add << endl;
    if (calc[c1] > sz[c1] - calc[c1]) {
        add -= calc[c1];
        calc[c1] = sz[c1] - calc[c1];
        rv[c1] ^= 1;
        add += calc[c1];
    }
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = "?" + s;
    memset(fix, 0, sizeof(fix));
    memset(rv, 0, sizeof(rv));
    memset(color, 0, sizeof(color));
    for (int i = 1; i <= k; i++) {
        comp[i] = i;
        sz[i] = 1;
        calc[i] = 0;
        incomp[i].push_back(i);
    }
    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            g[x].push_back(i + 1); 
        }
    }
    for (int i = 1; i <= n; i++) {
        if (g[i].empty()) ;
        else if ((int) g[i].size() == 1) {
            if (s[i] == '0') make_all(g[i][0], 1);
            else make_all(g[i][0], 0);
        }
        else if (s[i] == '1') {
            merge(g[i][0], g[i][1], 0);
        } else {
            merge(g[i][0], g[i][1], 1); 
        }
        cout << add + shure << "\n";
        //cout << add << ' ' << shure << ' ' << add + shure << "\n";
        //cout << "ans = " << ' ' << add + shure << endl;
    }
    return 0;
}