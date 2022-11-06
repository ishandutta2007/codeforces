#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char s[maxn];
int w[maxn];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    priority_queue<pair<int, int>> pq1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;
    for (int i = 0; i < n; ++i) pq2.emplace(w[i], i);
    scanf("%s", s);
    for (int i = 0; i < n + n; ++i) {
        if (s[i] == '0') {
            pair<int, int> p = pq2.top(); pq2.pop();
            printf("%d ", p.second + 1);
            pq1.push(p);
        } else {
            pair<int, int> p = pq1.top(); pq1.pop();
            printf("%d ", p.second + 1);
        }
    }
    puts("");
    return 0;
}