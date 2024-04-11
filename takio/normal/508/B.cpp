#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#define LL long long
#define pii pair <int, int>

using namespace std;

const int N = 100100;

char s[N];

int main () {
    scanf ("%s", s);
    int len = strlen (s);
    for (int i = 0; i < len - 1; i++) {
        if ((s[i] - '0') % 2 == 0 && s[i] < s[len - 1]) {
            swap (s[i], s[len - 1]);
            printf ("%s", s);
            return 0;
        }
    }
    for (int i = len - 2; i >= 0; i--) {
        if ((s[i] - '0') % 2 == 0 && s[i] > s[len - 1]) {
            swap (s[i], s[len - 1]);
            printf ("%s", s);
            return 0;
        }
    }
    printf ("-1");
}