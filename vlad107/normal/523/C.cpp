#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int j = 0;
    int first = t.size(), last = -1;
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == s[j]) j++;
        if (j == s.size()) {
            first = i;
            break;
        }
    }
    j = s.size() - 1;
    for (int i = t.size() - 1; i >= 0; i--) {
        if (t[i] == s[j]) j--;
        if (j == -1) {
            last = i;
            break;
        }
    }
    printf("%d\n", max(0, last - first));
}