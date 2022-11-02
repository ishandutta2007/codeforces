#include <math.h>
#include <limits.h>
#include <complex>
#include <string>
#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <ctime>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <complex.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#define INF 1000000000

using namespace std;

int st[500500];
string s;
int t[500500], a, u;
long long res = 0;

int main() {
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);
    cin >> a;
    cin >> s;
    for (int i = 1; i <= s.size(); i++)
        st[i] = st[i - 1] + s[i - 1] - '0';
    for (int i = 0; i < s.size(); i++)
        for (int j = i + 1; j <= s.size(); j++) 
            t[st[j] - st[i]]++;
    int n = s.size();
    for (int i = 1; i <= s.size(); i++)
        for (int j = i; j <= s.size(); j++) {
            if (j < i)
                u = 0;
            else u = st[j] - st[i - 1];
            if (a == 0) {
                if (u == 0)
                    res += n * (n + 1) / 2;
                else res += t[0];
                continue;
            }
            if (u == 0)
                continue;
            if (a % u != 0)
                continue;
            if (a / u > st[s.size()])
                continue;
            res += t[a / u];
        }
    cout << res << endl;
}