#include <bits/stdc++.h>
//#define int long long

using namespace std;

struct Node {
    string color;
    bool safe;
    int locked; // 1 == locked; -1 == unlocked; 0 == none;
    Node(string title = "") {
        if (title == "lock" || title == "unlock" || title == "") {
            color = "";
            safe = false;
            locked = 0;
            if (title == "lock")
                locked = 1;
            if (title == "unlock")
                locked = 2;
        } else {
            color = title;
            safe = false;
            locked = 0;
        }
    }
};

const int N = 1 << 17;
Node t[2 * N];

void relax(int pos) {
    t[pos].locked = t[2 * pos + 1].locked;
    if (t[pos].locked == 0)
        t[pos].locked = t[2 * pos].locked;

    if (t[2 * pos + 1].color == "" || (t[2 * pos].locked == 1 && !t[2 * pos + 1].safe)) {
        t[pos].color = t[2 * pos].color;
        t[pos].safe = t[2 * pos].safe;
    } else {
        t[pos].color = t[2 * pos + 1].color;
        t[pos].safe = t[2 * pos + 1].safe || (t[2 * pos].locked != 0);
    }
}

void update(int pos, string new_val) {
    pos += N - 1;
    t[pos] = new_val;
    while (pos > 1) {
        pos /= 2;
        relax(pos);
    }
}

string get() {
    return (t[1].color == "" ? "blue" : t[1].color);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        update(i, s);
    }
    cout << get() << "\n";
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int pos;
        string new_val;
        cin >> pos >> new_val;
        update(pos, new_val);
        cout << get() << "\n";
    }
}