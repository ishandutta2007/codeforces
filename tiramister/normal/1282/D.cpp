#include <iostream>
#include <string>

int query(const std::string& t) {
    std::cout << t << std::endl;
    int res;
    std::cin >> res;
    if (res < 0) std::terminate();
    if (res == 0) std::exit(0);
    return res;
}

int main() {
    std::string t;
    t = std::string(300, 'a');
    int qa = query(t);
    t = std::string(300, 'b');
    int qb = query(t);

    int n = 600 - qa - qb;  // a + b
    int ab = qb - qa;       // a - b
    int a = (n + ab) / 2;
    int b = n - a;

    std::string ans;
    while (a > 0 && b > 0) {
        t = ans + "b" + std::string(a, 'a');
        int res = query(t);

        if (res == b - 1) {
            ans.push_back('b');
            --b;
        } else {
            ans.push_back('a');
            --a;
        }
        --n;
    }

    if (a == 0) {
        ans += std::string(b, 'b');
    } else {
        ans += std::string(a, 'a');
    }

    query(ans);
    std::terminate();
    return 0;
}