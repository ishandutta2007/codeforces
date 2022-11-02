#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#define LL long long
#define pii pair <int, int>
using namespace std;

const int N = 110;

char s[N], t[N];

int main () {
//    freopen ("in.txt", "r", stdin);
    scanf ("%s%s", s + 1, t + 1);
    int len = strlen (s + 1);
    int e = len;
    s[e]++;
    while (s[e] == 'z' + 1) s[e] = 'a', s[--e]++;
    if (!e || strcmp(s + 1, t + 1) == 0) {
        printf ("No such string\n");
        return 0;
    }
    cout << s + 1 << endl;
}