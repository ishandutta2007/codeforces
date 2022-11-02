#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>
#include <cstring>

using namespace std;

int n, p;
string s;

void check(string s, int pos) {
    if ((pos > 0) && (s[pos] == s[pos - 1])) {
        return;
    }
    if ((pos > 1) && (s[pos] == s[pos - 2])) {
        return;
    }
    for (int i = pos + 1; i < n; i++) {
        bool found = false;
        for (char c = 'a'; c < 'a' + p; c++) {
            s[i] = c;
            if ((i > 0) && (s[i] == s[i - 1])) {
                continue;
            }
            if ((i > 1) && (s[i] == s[i - 2])) {
                continue;
            }
            found = true;
            break;
        }
        if (!found) {
            return;
        }
    }
    cout << s << endl;
    exit(0);
} 

int main() {
    // freopen("input.txt", "r", stdin);
    cin >> n >> p;
    cin >> s;
    for (int i = n - 1; i >= 0; i--) {
        for (char c = s[i] + 1; c < 'a' + p; c++) {
            string e = s;
            e[i] = c;
            check(e, i);
        }
    }
    puts("NO");
}