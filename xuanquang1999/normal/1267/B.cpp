#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int n;
vector<pair<char, int>> a;
char s[MAXN];

int solve() {
    int k = a.size();
    if (k%2 == 0)
        return 0;

    for(int i = 0; i < k/2; ++i)
        if (a[i].first != a[k-i-1].first || a[i].second + a[k-i-1].second == 2) {
//            printf("%d %d\n", i, n-i-1);
            return 0;
        }

    if (a[k/2].second == 1)
        return 0;

    return a[k/2].second + 1;
}

int main() {
    scanf("%s", s);
    n = strlen(s);

    char last = s[0];
    int cnt = 1;
    for(int i = 1; i < n; ++i) {
        if (s[i] == last)
            ++cnt;
        else {
            a.push_back({last, cnt});
            cnt = 1;
            last = s[i];
        }
    }
    a.push_back({last, cnt});

//    for(auto e: a)
//        printf("%c %d\n", e.first, e.second);

    printf("%d", solve());

    return 0;
}