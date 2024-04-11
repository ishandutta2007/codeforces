#include <bits/stdc++.h>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::string s;
    std::cin >> s;
    int N = s.size();
    int i = 0;
    while (i < N && s[i] == 'a') ++i;
    if (i == N) {
        s.back() = 'z';
    } else {
        while (i < N && s[i] != 'a') {
            --s[i];
            ++i;
        }
    }
    std::cout << s << '\n';
    exit(0);
}