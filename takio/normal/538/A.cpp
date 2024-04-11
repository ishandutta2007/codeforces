#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 100100;

string t = "CODEFORCES", s;

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> s;
    int len = s.length();
    if (len < 10) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i <= 10; i++) {
        int tlen = 10 - i;
//        cout << s.substr(0, i) + s.substr(len - tlen, tlen) << endl;
        if (s.substr(0, i) + s.substr(len - tlen, tlen) == t) {
            printf ("YES");
            return 0;
        }
    }
    cout << "NO";
}