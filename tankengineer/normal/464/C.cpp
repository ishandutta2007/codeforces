#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;
char s[N], buf[N];

const int MOD = 1000000007;
pair<int, int> data[10];

pair<int, int> calc(string s) {
    int a = 0, b = 1;
    for (int i = 0; i < s.size(); ++i) {
        int u = s[i] - '0';
        a = ((long long)a * data[u].second + data[u].first) % MOD;
        b = (long long)b * data[u].second % MOD;
    }
    return make_pair(a, b);
}

int main() {
    scanf("%s", s);
    int k;
    scanf("%d", &k);
    vector<pair<int, string> > trans; 
    for (int i = 0; i < k; ++i) {
        scanf("%s", buf);
        trans.push_back(make_pair(buf[0] - '0', string(buf + 3))); 
    }
    for (int i = 0; i < 10; ++i) {
        data[i] = make_pair(i, 10 % MOD);
    }
    for (int i = k - 1; i >= 0; --i) {
        data[trans[i].first] = calc(trans[i].second);
    }
    printf("%d\n", calc(s).first);
    return 0;
}