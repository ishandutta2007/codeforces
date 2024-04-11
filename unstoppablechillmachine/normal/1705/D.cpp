#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

int stupid_solve(const string &s, const string &t) {
    map<string, int> dist;
    dist[s] = 0;
    queue<string> q;
    q.push(s);
    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        for (int i = 1; i + 1 < cur.size(); i++) {
            if (cur[i - 1] != cur[i + 1]) {
                string nxt = cur;
                nxt[i] ^= 1;
                if (!dist.count(nxt)) {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
    }
    if (!dist.count(t)) {
        return -1;
    }
    return dist[t];
}

int smart_solve(const string &s, const string &t) {
    if (s[0] != t[0] || s.back() != t.back()) {
        return -1;
    }
    int n = static_cast<int>(s.size());
    vector<int> parts_s = {1}, parts_t = {1};
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            parts_s.push_back(1);
        } else {
            parts_s.back()++;
        }

        if (t[i] != t[i - 1]) {
            parts_t.push_back(1);
        } else {
            parts_t.back()++;
        }
    }
    if (parts_s.size() != parts_t.size()) {
        return -1;
    }
    int ptr = 0, answer = 0;
    for (int i = 0; i < parts_s.size(); i++) {
        if (parts_s[i] > parts_t[i]) {
            parts_s[i + 1] += (parts_s[i] - parts_t[i]);
            answer += (parts_s[i] - parts_t[i]);
            parts_s[i] = parts_t[i];
        } else {
            ptr = max(ptr, i + 1);
            while (parts_s[i] < parts_t[i]) {
                int delta = min(parts_s[ptr] - 1, parts_t[i] - parts_s[i]);
                //cout << i << ' ' << ptr << ' ' << delta << '\n';
                parts_s[i] += delta;
                parts_s[ptr] -= delta;
                answer += (ptr - i) * delta;
                ptr++;
            }
            ptr--;
        }
        /*for (auto it : parts_s) {
            cout << it << ' ';
        }
        cout << '\n';
        for (auto it : parts_t) {
            cout << it << ' ';
        }
        cout << '\n' << answer;
        cout << '\n' << '\n';*/
    }
    return answer;
}

mt19937 rnd(228);

pair<string, string> generator() {
    int n = rnd() % 10 + 2;
    string s(n, '1'), t(n, '1');
    for (int i = 0; i < n; i++) {
        if (rnd() & 1) {
            s[i] ^= 1;
        }
    }
    t[0] = s[0];
    t.back() = s.back();
    for (int i = 1; i + 1 < n; i++) {
        if (rnd() & 1) {
            t[i] ^= 1;
        }
    }
    return {s, t};
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    /*for (int i = 0; i < 1000; i++) {
        auto [s, t] = generator();
        if (stupid_solve(s, t) != smart_solve(s, t)) {
            cout << "error!\n";
            cout << s << '\n' << t << '\n' << "my answer: " << smart_solve(s, t) << '\n' << "correct answer: " << stupid_solve(s, t) << '\n';
            return 0;
        }
    }
    cout << "all tests passed!\n";*/
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        cout << smart_solve(s, t) << '\n';
    }
    return 0;
}