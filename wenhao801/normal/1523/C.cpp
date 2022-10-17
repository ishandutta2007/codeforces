#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}
vector <int> v;
int main () {
    int T = read();
    while (T--) {
        v.clear();
        int n = read() - 1; v.push_back(1);
        int x = read(); puts("1");
        while (n--) {
            x = read();
            if (x == 1) v.push_back(1);
            else { while (v.back() != x - 1) v.pop_back(); v.pop_back(), v.push_back(x); }
            cout << v[0]; for (int i= 1; i < v.size(); i++) printf(".%d", v[i]); puts("");
        }
    }
    return 0;
}