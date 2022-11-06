#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
int a[maxn], b[maxn];

char ask(int i, int j) {
    cout << "? " << i << ' ' << j << endl;
}

bool ans(int i, int j) {
    cout << "! " << i << ' ' << j << endl; 
}

int main() {
    srand(time(nullptr));
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        vector<int> cmp;
        for (int i = 1; i <= n; i += 2) {
            if (i + 1 <= n) {
                ask(i, i + 1);
                char c; cin >> c;
                if (c == '<') a[i] = i, b[i] = i + 1;
                else if (c == '=') a[i] = i, b[i] = i;
                else a[i] = i + 1, b[i] = i;
            } else {
                a[i] = i, b[i] = i;
            }
            cmp.push_back(i);
        }
        int cura = a[cmp[0]], curb = b[cmp[0]];
        for (int i = 1; i < cmp.size(); ++i) {
            ask(cura, a[cmp[i]]);
            char c; cin >> c;
            if (c == '>') cura = a[cmp[i]];
            ask(curb, b[cmp[i]]);
            cin >> c;
            if (c == '<') curb = b[cmp[i]];
        }
        ans(cura, curb);
    }
    return 0;
}