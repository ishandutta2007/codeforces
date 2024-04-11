#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
vector<int> map[200001];
int ans[200001];
int loc[200001];
int v[200001];
int main() {
    int n, a, b;
    scanf("%d", &n);
    for(int i=1; i<n; i++) {
        scanf("%d%d", &a, &b);
        map[a].push_back(b);
        map[b].push_back(a);
    }
    for(int i=0; i<n; i++) {
        scanf("%d", ans+i);
        loc[ans[i]] = i;
    }
    vector<int> res;
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        res.push_back(x);
        v[x] = 1;
        sort(map[x].begin(), map[x].end(), [](int a, int b) {return loc[a] < loc[b];});
        for(auto xx: map[x]) {
            if(v[xx]) continue;
            Q.push(xx);
        }
    }
    for(int i=0; i<n; i++) {
        if(ans[i] != res[i]) {
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    return 0;
}