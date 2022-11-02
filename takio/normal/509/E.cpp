#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#define LL long long
#define pii pair <int, LL>
#define piii pair <pii, int>
using namespace std;

const int N = 510000;
const LL INF = 1LL << 60;
double sum1[N], sum2[N];
int ok[300];
char s[N];

int main () {
    scanf ("%s", s);
    int len = strlen (s);
    ok[(int)('A')] = 1;
    ok[(int)('E')] = 1;
    ok[(int)('I')] = 1;
    ok[(int)('O')] = 1;
    ok[(int)('U')] = 1;
    ok[(int)('Y')] = 1;
    for (int i = len; i >= 1; i--) {
        sum1[i] = sum1[i + 1] + 1.0 / i;
//        cout << sum1[i] << ' ';
    }
//    cout << endl;
    for (int i = 1; i <= len; i++) {
        sum2[i] = sum2[i - 1] + sum1[i] - sum1[len - i + 2];
//        cout << sum2[i] << ' ';
    }
//    cout << endl;
    int m = len / 2;
    double res = 0;
    for (int i = 0; i < len; i++) {
        if (ok[(int)s[i]]) {
            if (i <= m) res += sum2[i + 1];
            else res += sum2[len - i];
        }
    }
    printf ("%.8f", res);
}