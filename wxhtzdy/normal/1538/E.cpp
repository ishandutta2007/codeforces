#include <bits/stdc++.h>
using namespace std;

int cnt(string s) {
    int N = (int) s.size(), ret = 0;

    for (int i = 0; i < N - 3; i++)
        if (s.substr(i, 4) == "haha")
            ret++;

    return ret;
}

string update(string s) {
    if (s.size() <= 3) return s;
    else return s.substr(0, 3);
}

struct word {
    int64_t cnt_haha = 0;
    string left, right;

    word() {}

    word(string s) {
        cnt_haha = cnt(s);
        left = right = s;
        fix();
    }

    void fix() {
        if (left.size() > 3)
            left = left.substr(0, 3);
        if (right.size() > 3)
            right = right.substr(right.size() - 3, 3);
    }
};

word Merge(word x, word y) {
    word ret;
    ret.cnt_haha = x.cnt_haha + y.cnt_haha;
    ret.cnt_haha += cnt(x.right + y.left);
    ret.left = x.left + y.left;
    ret.right = x.right + y.right;
    ret.fix();
    return ret;
}

void run_case() {
    int N;
    cin >> N;
    map<string, word> mp;
    int64_t ans;

    for (int i = 0; i < N; i++) {
        string id, type;
        cin >> id >> type;

        if (type == ":=") {
            string s;
            cin >> s;
            mp[id] = word(s);
        } else {
            string a, useless, b;
            cin >> a >> useless >> b;
            mp[id] = Merge(mp[a], mp[b]);
        }

        ans = mp[id].cnt_haha;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests--)
        run_case();
}