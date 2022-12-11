#include <bits/stdc++.h>
//#define int long long

using namespace std;

struct state {
    int n, a, b;
    state() {}
    state(int n, int a, int b): n(n), a(a), b(b) {}
    
};

struct cmp {
    bool operator()(const state &lhs, const state &rhs) const {
        if (lhs.n != rhs.n)
            return (lhs.n < rhs.n);
        if (lhs.a != rhs.a)
            return (lhs.a < rhs.a);
        return (lhs.b < rhs.b);
    }
};

string s;
map <state, vector <int>, cmp> ans;
const int N = 1e5 + 7;
pair <int, int> minimax[N];

void init() {
    minimax[1] = {0, 0};
    for (int i = 2; i < N; i++) {
        int l = i / 2, r = i - l;
        minimax[i].first = min(l, r) + minimax[l].first + minimax[r].first;
        minimax[i].second = l + r - 1 + minimax[l].second + minimax[r].second;
    }
}

vector <int> rev(vector <int> perm) {
    vector <int> ans(perm.size(), 0);
    for (int i = 0; i < (int) perm.size(); i++)
        ans[perm[i]] = i;
    return ans;
}

vector <int> get(state st) {
    if (ans.find(st) != ans.end())
        return ans[st];
    ans[st] = {};
    auto [n, a, b] = st;
    int l = n / 2, r = n - l;
    if (!(minimax[n].first <= b - a + 1 && b - a + 1 <= minimax[n].second))
        return {};

    if (n == 1) {
        ans[st] = {0};
        return {0};
    }

    int cnt0 = 0, cnt1 = 0;
    for (int uk = b; uk >= a; uk--) {
        if (s[uk] == '0')
            cnt0++;
        else
            cnt1++;
        if (cnt0 > l || cnt1 > r)
            break;
        if (cnt0 == l && cnt1 == r)
            break;

        if (cnt0 < l && cnt1 < r)
            continue;

        if (cnt0 == l && s[b] != '0')
            break;

        if (cnt1 == r && s[b] != '1')
            break;

        for (int len = minimax[l].first; len <= minimax[l].second && a + len <= uk; len++) {
            int len_r = (uk - a) - len;
            if (len_r > minimax[r].second)
                continue;
            if (len_r < minimax[r].first)
                break;
            auto l_ans = get(state(l, a, a + len - 1));
            if (l_ans.empty())
                continue;
            auto r_ans = get(state(r, a + len, uk - 1));
            if (r_ans.empty())
                continue;

            vector <int> total_ans(n);
            int lptr = 0, rptr = 0;
            for (int i = 0; i <= b - uk; i++) {
                if (s[uk + i] == '0')
                    total_ans[i] = l_ans[lptr++];
                else
                    total_ans[i] = l + r_ans[rptr++];
            }
            assert((lptr == l) ^ (rptr == r));
            for (int i = b - uk + 1; i < n; i++) {
                if (lptr != l)
                    total_ans[i] = l_ans[lptr++];
                else {
                    assert(rptr < r);
                    total_ans[i] = l + r_ans[rptr++];
                }
            }
            assert(lptr == l && rptr == r);
            ans[st] = total_ans;
            return total_ans;
        }
    }
    return {};
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    init();
    cin >> s;
    for (int n = 1; n < N; n++) {
        auto x = get(state(n, 0, (int) s.size() - 1));
        if (!x.empty()) {
            auto ans = rev(x);
            vector <int> cnt(ans.size(), 0);
            for (auto elem : ans)
                cnt[elem]++;
            for (auto elem : cnt)
                assert(elem == 1);
            cout << ans.size() << "\n";
            for (int elem : ans) {
                cout << elem + 1 << ' ';
            }
            cout << "\n";
            return 0;
        }
    }
    return -1;
}