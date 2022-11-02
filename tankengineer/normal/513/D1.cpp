#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1000005;

int n, m;

vector<int> edge[N][2];

int ch[N][2];

bool flag = true;

int go(int l, int r) {
//    cout << l << ' ' << r << endl;
    int nxt = l + 1, bar = l;
    for (int i = 0; i < (int)edge[l][0].size(); ++i) {
        bar = max(bar, edge[l][0][i]);
        if (edge[l][0][i] <= l) {
            flag = false; 
        }
    }
    if (bar > l) {
        ch[l][0] = nxt;
//        cout << l << "LEFT" << ' ' << ch[l][0] << endl;
        nxt = go(nxt, bar) + 1;
        bar = nxt - 1;
        for (int i = 0; i < (int)edge[l][1].size(); ++i) {
            bar = max(bar, edge[l][1][i]);
            if (edge[l][1][i] < nxt) {
                flag = false; 
            }
        }
        if (bar == nxt - 1 && nxt > r) {
            return nxt - 1;
        } else {
            bar = max(bar, r);
            ch[l][1] = nxt;
//        cout << l << "RIGHT" << ' ' << ch[l][1] << endl;
            return go(nxt, bar);
        }
    } else {
        bar = l;
        for (int i = 0; i < (int)edge[l][1].size(); ++i) {
            bar = max(bar, edge[l][1][i]);
            if (edge[l][1][i] <= l) {
                flag = false; 
            }
        }
        if (bar > l || r > l) {
            ch[l][1] = nxt;
//            cout << l << "RIGHT" << ' ' << ch[l][1] << endl;
            bar = max(bar, r);
            return  go(nxt, bar);
        } else {
            return l;
        }
    }
}

int cnt = 0;

void output(int u) {
    if (ch[u][0] != -1) {
        output(ch[u][0]);
    }
    printf("%d%c", u + 1, ++cnt == n ? '\n' : ' ');
    if (ch[u][1] != -1) {
        output(ch[u][1]);
    }
}

int main() {
    memset(ch, -1, sizeof(ch));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        char s[10];
        scanf("%d%d%s", &u, &v, s);
        --u, --v;
        int op = s[0] == 'R';
        edge[u][op].push_back(v);
    }
    go(0, n - 1); 
    if (!flag) {
        puts("IMPOSSIBLE");
    } else {
        output(0);
    }
    return 0;
}