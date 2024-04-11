#include<map>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100005;

int n;

long long sum[N];

int val[26];

char s[N];

int main() {
    for (int i = 0; i < 26; ++i) {
        scanf("%d", val + i);
    }
    scanf("%s", s);
    n = strlen(s);
    sum[0] = 0;
    for (int i = 0; i < n; ++i) {
        sum[i + 1] = sum[i] + val[s[i] - 'a'];
    }
    map<pair<long long, char>, int> tr;
    for (int i = 0; i < n; ++i) {
        tr[make_pair(sum[i], s[i])]++;
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        tr[make_pair(sum[i], s[i])]--;
        ans += tr[make_pair(sum[i + 1], s[i])];
    }
    cout << ans << endl;
    return 0;
}