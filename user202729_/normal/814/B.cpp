// problem b

#include <iostream>
#include <vector>

int len;
std::vector<int> a, b, diff, fil;
std::vector<bool> rest;

int main() {
    std::cin >> len;
    a.resize(len); b.resize(len);
    rest.resize(len+1, true);
    for (int i = 0; i < len; ++i) {
        std::cin >> a[i];
    }
    for (int i = 0; i < len; ++i) {
        std::cin >> b[i];
        if (a[i] != b[i]) {
            diff.push_back(i);
        } else {
            rest[a[i]] = false;
        }
    }

    // diff.size() == 1 or 2

    for (int i = 1; i <= len; ++i) {
        if (rest[i]) fil.push_back(i);
    }

    // fil.size() == diff.size()
    if (diff.size() == 1) {
        a[diff[0]] = fil[0];
    } else {
        if (
            ((a[diff[0]] == fil[0]) ^ (a[diff[1]] == fil[1])) &&
            ((b[diff[0]] == fil[0]) ^ (b[diff[1]] == fil[1]))
        ) {
            a[diff[0]] = fil[0];
            a[diff[1]] = fil[1];
        } else {
            a[diff[0]] = fil[1];
            a[diff[1]] = fil[0];
        }
    }
    std::cout << a[0];
    for (int i = 1; i < len; ++i) std::cout << " " << a[i];
    std::cout << "\n";
}