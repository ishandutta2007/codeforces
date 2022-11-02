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

using namespace std;

const int N = 5e3 + 1;
const int M = 15e6;

bool f[N][N];
int cq;
int cnt[M];
vector< pair<int, int> > nxt[M];
string res;

void go(int x, int &k) {
    k -= cnt[x];
    if (k <= 0) {
        cout << res << endl;
        exit(0);
    }
    res += '!';
    sort(nxt[x].begin(), nxt[x].end());
    for (int it = 0; it < nxt[x].size(); it++) {
        int i = nxt[x][it].first;
        int y = nxt[x][it].second;
        res[res.size() - 1] = char(i + 'a');
        go(y, k);
    }
    res.erase(res.size() - 1);
}

int main() {
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    string s;
    char buff[5005];
    gets(buff);
    buff[strlen(buff)] = 0;
    // for (int i = 0; i < 5000; i++) s += char(rand()%26 + 'a');
    s = buff;
    int k;
    cin >> k;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i; j < n; j++) {
            f[i][j] = (s[i] == s[j]);
            if (i + 2 <= j - 2) f[i][j] &= f[i + 2][j - 2];
        }
    }
    cq = 1;
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = i; j < n; j++) {
            int x = s[j] - 'a';
            int it = 0;
            while ((it < nxt[cur].size()) && (nxt[cur][it].first != x)) it++;
            if (it == nxt[cur].size()) nxt[cur].push_back(make_pair(x,cq++));
            cur = nxt[cur][it].second;
            if (f[i][j]) cnt[cur]++;
        }
    }
    res = "";
    go(0, k);
    // cerr << "Execution time = " << clock() * 1.0 / CLOCKS_PER_SEC << endl;
}