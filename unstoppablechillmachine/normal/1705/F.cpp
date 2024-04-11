#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    string s(n, 'T');
    string t = s;
    for (int i = 1; i < n; i += 2) {
        t[i] = 'F';
    }
    auto query = [n](const string &s) {
        cout << s << endl;
        int res;
        cin >> res;
        if (res == n || res == -1) {
            exit(0);
        }
        return res;
    };
    int res_s = query(s), res_t = query(t);
    int cur = 0;
    string answer = s;
    auto solve_for_single_position = [&](int pos) {
        string kek = s;
        kek[pos] = 'F';
        int new_res = query(kek);
        if (new_res > res_s) {
            answer[pos] = 'F';
        } else {
            answer[pos] = 'T';
        }
    };
    while (cur + 2 < n) {
        string kek1 = s;
        kek1[cur] = kek1[cur + 1] = 'F';
        int new_res = query(kek1);
        if (new_res == res_s + 2) {
            answer[cur] = answer[cur + 1] = 'F';
            solve_for_single_position(cur + 2);
        } else if (new_res == res_s - 2) {
            answer[cur] = answer[cur + 1] = 'T';
            solve_for_single_position(cur + 2);
        } else {
            string kek2 = t;
            if (kek2[cur] == 'F') {
                kek2[cur] = 'T';
                kek2[cur + 1] = 'F';
                kek2[cur + 2] = 'T';
            } else {
                kek2[cur] = 'F';
                kek2[cur + 1] = 'T';
                kek2[cur + 2] = 'F';
            }
            int new_res2 = query(kek2);
            if (new_res2 == res_t + 3) {
                answer[cur] = kek2[cur];
                answer[cur + 1] = kek2[cur + 1];
                answer[cur + 2] = kek2[cur + 2];
            } else if (new_res2 == res_t - 3) {
                answer[cur] = t[cur];
                answer[cur + 1] = t[cur + 1];
                answer[cur + 2] = t[cur + 2];
            } else if (new_res2 == res_t + 1) {
                answer[cur] = kek2[cur];
                answer[cur + 1] = kek2[cur + 1];
                answer[cur + 2] = t[cur + 2];
            } else {
                answer[cur] = t[cur];
                answer[cur + 1] = t[cur + 1];
                answer[cur + 2] = kek2[cur + 2];
            }
        }
        cur += 3;
    }
    while (cur < n) {
        solve_for_single_position(cur);
        cur++;
    }
    assert(query(answer) == n);
    return 0;
}