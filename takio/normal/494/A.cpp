#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

char s[100100];
int cnt1, cnt2, cnt3;

int main () {
    scanf ("%s", s);
    int e;
    int len = strlen (s);
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') cnt1++;
        else if (s[i] == ')') cnt2++;
        else cnt3++, e = i;
        if (cnt1 < cnt2 + cnt3) {
            cout << -1;
            return 0;
        }
    }
    int les = cnt1 - cnt2 - cnt3 + 1, t = cnt3;
    cnt1 = cnt2 = cnt3 = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') cnt1++;
        else if (s[i] == ')') cnt2++;
        else if (i == e) cnt3 += les;
        else cnt3++;
        if (cnt1 < cnt2 + cnt3) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 1; i < t; i++) {
        printf ("1\n");
    }
    cout << les << endl;
}