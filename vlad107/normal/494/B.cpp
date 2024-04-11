#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

const int N = 500500;
const int BASE = 1e9 + 7;

string s, t;
int p[N], ex[N], f[N], g[N];

void add(int &x, int y) {
    x += y;
    if (x >= BASE) x -= BASE;
}

int main() {
//  freopen("input.txt", "r", stdin);
    cin >> s;
    cin >> t;
    p[0] = 0;
    for (int i = 1; i < t.size(); i++) {
        int j = p[i - 1];
        while ((j > 0) && (t[i] != t[j])) j = p[j - 1];
        if (t[i] == t[j]) ++j;
        p[i] = j;
    }
    int j = 0;
    for (int i = 0; i < s.size(); i++) {
        while ((j > 0) && (s[i] != t[j])) j = p[j - 1];
        if (s[i] == t[j]) ++j;
        if (j == t.size()) {
            ex[i] = true;
        }
    }
    int fst = -1;
    for (int i = 0; i < s.size(); i++) {
        if (ex[i]) {
            fst = i;
            break;
        }
    }
    if (fst < 0) {
        puts("0");
        return 0;
    }
    int lst = -1;
    for (int i = fst; i < s.size(); i++) {
        if (ex[i]) lst = i - t.size();
        f[i] = lst + 2;
        if (lst >= 0) add(f[i], g[lst]);
        if (i > 0) add(f[i], f[i - 1]);
        g[i] = f[i];
        if (i > 0) add(g[i], g[i - 1]);
//      cerr << f[i] << " " << g[i] << endl;
    }
    printf("%d\n", f[s.size() - 1]);
}