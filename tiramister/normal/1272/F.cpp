#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

template <class T>
std::vector<T> vec(int len, T elem) { return std::vector<T>(len, elem); }

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    int n = s.length(), m = t.length();
    int hmax = n + m;

    auto revc = vec(n + 1, vec(m + 1, vec(hmax, '*')));
    revc[0][0][0] = '$';
    auto revt = vec(n + 1, vec(m + 1, vec(hmax, std::make_tuple(-1, -1, -1))));

    std::queue<std::tuple<int, int, int>> que;
    que.emplace(0, 0, 0);

    while (!que.empty()) {
        int i, j, h;
        std::tie(i, j, h) = que.front();
        que.pop();

        {
            int ni = i + (i < n && s[i] == '('),
                nj = j + (j < m && t[j] == '('),
                nh = h + 1;
            if (nh < hmax && revc[ni][nj][nh] == '*') {
                revc[ni][nj][nh] = '(';
                revt[ni][nj][nh] = std::make_tuple(i, j, h);
                que.emplace(ni, nj, nh);
            }
        }

        {
            int ni = i + (i < n && s[i] == ')'),
                nj = j + (j < m && t[j] == ')'),
                nh = h - 1;
            if (nh >= 0 && revc[ni][nj][nh] == '*') {
                revc[ni][nj][nh] = ')';
                revt[ni][nj][nh] = std::make_tuple(i, j, h);
                que.emplace(ni, nj, nh);
            }
        }
    }

    int i = n, j = m, h = 0;
    std::string ans;
    while (i > 0 || j > 0 || h > 0) {
        char c = revc[i][j][h];
        ans.push_back(c);
        std::tie(i, j, h) = revt[i][j][h];
    }

    std::reverse(ans.begin(), ans.end());
    std::cout << ans << std::endl;
}

int main() {
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios::sync_with_stdio(false);

    solve();

    return 0;
}