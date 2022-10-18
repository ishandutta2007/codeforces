#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3005;

int n, k;
char s[MAXN];
vector<vector<int>> moves;

int main() {
    scanf("%d%d", &n, &k);
    scanf("%s", s);

    int sumMove = 0;
    while (true) {
        vector<int> cur;
        for(int i = 0; i < n-1; ++i) {
            if (s[i] == 'R' && s[i+1] == 'L') {
                swap(s[i], s[i+1]);
                cur.push_back(i+1);
                ++i;
                ++sumMove;
            }
        }

        if (cur.empty())
            break;        
        moves.push_back(cur);
    }

    // printf("%d\n", sumMove);

    // for(auto v: moves) {
    //     for(int x: v)
    //         printf("%d ", x);
    //     puts("");
    // }

    if (k < moves.size() || k > sumMove) {
        puts("-1");
        return 0;
    }

    vector<vector<int>> ans;

    int i = moves.size() - 1;

    for(int cur = moves.size() + 1; cur <= k; ++cur) {
        while (moves[i].size() < 2) {
            ans.push_back(moves[i]);
            --i;
        }
        ans.push_back({moves[i].back()});
        moves[i].pop_back();
    }

    while (i >= 0) {
        ans.push_back(moves[i]);
        --i;
    }

    for(int i = ans.size() - 1; i >= 0; --i) {
        printf("%d", ans[i].size());
        for(int x: ans[i])
            printf(" %d", x);
        puts("");
    }

    return 0;
}