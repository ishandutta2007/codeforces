#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

int n, h, x;
vector<pair<int, int> > candy[2];

const int N = 2005;
bool eaten[2][N];

int main() {
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
        int type, h, m;
        scanf("%d%d%d", &type, &h, &m);
        candy[type].push_back(make_pair(h, m));
    }
    int ans = 0;
    for (int st = 0; st < 2; ++st) {
        memset(eaten, 0, sizeof(eaten));
        int tmp = 0, curh = x, find = st;
        while (true) {
            int pos = -1;
            for (int i = 0; i < (int)candy[find].size(); ++i) {
                if (!eaten[find][i] && curh >= candy[find][i].first) {
                    if (pos == -1 || candy[find][i].second > candy[find][pos].second) {
                        pos = i;
                    }
                }
            }
            if (pos == -1) {
                break;
            }
            ++tmp;
            eaten[find][pos] = true;
            curh += candy[find][pos].second;
            find ^= 1;
        }
        ans = max(ans, tmp);
    }
    printf("%d\n", ans);
    return 0;
}