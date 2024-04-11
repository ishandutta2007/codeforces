#include <bits/stdc++.h>

using ll = long long;

const int maxn = 2e6;

int mx = -1;
char res[maxn];
bool used[maxn];
std::set<int> ins;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for(int i = 0; i < maxn; i++) {
        ins.insert(i);
    }
    int n;
    std::cin >> n;
    for(int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        int k;
        std::cin >> k;
        int len = (int) s.size();
        for(int j = 0; j < k; j++) {
            int x;
            std::cin >> x;
            x--;
            mx = std::max(mx, x + len - 1);
            while(true) {
                auto it = ins.lower_bound(x);
                int pos = *it;
                if(x + len <= pos) break;
                res[pos] = s[pos - x];
                used[pos] = true;
                ins.erase(it);
            }
        }
    }
    for (int i = 0; i <= mx; i++) {
        if (used[i]) std::cout << res[i];
        else std::cout << 'a';
    }
    return 0;
}