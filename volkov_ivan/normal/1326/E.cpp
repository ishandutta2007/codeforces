#include <bits/stdc++.h>

using namespace std;

struct Node{
    int free = 0, need = 0;
    Node() {free = 0; need = 0;}
};

const int N = 1 << 19;
Node t[2 * N];
bool a[N], b[N];
int p[N], q[N], pos[N];

void relax(int pos) {
    if (t[2 * pos + 1].free >= t[2 * pos].need) {
        t[pos].free = t[2 * pos].free + t[2 * pos + 1].free - t[2 * pos].need;
        t[pos].need = t[2 * pos + 1].need;
    } else {
        t[pos].free = t[2 * pos].free; 
        t[pos].need = t[2 * pos].need - t[2 * pos + 1].free + t[2 * pos + 1].need;
    }
}

void upd(int p) {
    int pos = p + N - 1;
    t[pos] = Node();
    if (a[p] && !b[p]) t[pos].need = 1;
    if (!a[p] && b[p]) t[pos].free = 1;
    //cout << "!! " << t[pos].need << ' ' << t[pos].free << endl;
    while (pos > 1) {
        pos /= 2;
        relax(pos);
    }
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
        //cout << p[i] << ' ' << pos[p[i]] << endl;
    }
    for (int i = 1; i <= n; i++) cin >> q[i];
    int res = n;
    //cout << pos[n] << endl;
    a[pos[n]] = 1;
    //cout << t[1].need << ' ' << t[1].free << endl;
    upd(pos[n]);
    //cout << t[1].need << ' ' << t[1].free << endl;
    cout << n << ' ';
    for (int i = 1; i < n; i++) {
        b[q[i]] = 1;
        //cout << b[q[i]] << ' ' << a[q[i]] << endl;
        upd(q[i]); 
        //cout << t[1].need << ' ' << t[1].free << endl;
        while (res != 0 && t[1].need == 0) {
            res--;
            a[pos[res]] = 1;
            upd(pos[res]);
        }
        cout << res << ' ';
    }
    return 0;
}