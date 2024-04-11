#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int A = 26;
const int N = 100100;
char s[N];
bool good[A];
int pref[N];
int n;
int m, q;
char t[N];
int starPos;

bool solve()
{
    if (starPos == -1) {
        if (m != n) return false;
        for (int i = 0; i < n; i++) {
            if (s[i] == '?') {
                if (!good[(int)(t[i] - 'a')])
                    return false;
            } else {
                if (s[i] != t[i])
                    return false;
            }
        }
        return true;
    }
    if (m < n - 1) return false;
    int b = m - n + starPos;
    for (int i = 0; i < starPos; i++) {
        if (s[i] == '?') {
            if (!good[(int)(t[i] - 'a')])
                return false;
        } else {
            if (s[i] != t[i])
                return false;
        }
    }
    for (int i = starPos; i <= b; i++)
        if (good[(int)(t[i] - 'a')])
            return false;
    for (int i = 1; starPos + i < n; i++) {
        if (s[starPos + i] == '?') {
            if (!good[(int)(t[b + i] - 'a')])
                return false;
        } else {
            if (s[starPos + i] != t[b + i])
                return false;
        }
    }
    return true;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i++)
        good[(int)(s[i] - 'a')] = 1;
    scanf("%s", s);
    n = strlen(s);

    starPos = -1;
    for (int i = 0; i < n; i++)
        if (s[i] == '*')
            starPos = i;

    scanf("%d", &q);
    while(q--) {
        scanf("%s", t);
        m = strlen(t);
        if (solve())
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}