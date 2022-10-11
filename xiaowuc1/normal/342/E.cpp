#include <iostream>
#include <memory>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <complex>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <ctime>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <utility>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
typedef pair<ll, ll> pll;

const int MAX_DEPTH = 17;

int lca[100000][MAX_DEPTH];
int depth[100000];
vector<int> red;
int n;
vector<int> edges[100000];
int dp[100000];
vector<int> temp;

int getDist(int x, int y) {
    if(depth[x] > depth[y]) {
        return getDist(y, x);
    }
    int ret = 0;
    for(int d = MAX_DEPTH-1; d >= 0; d--) {
        if(depth[y]-(1<<d) >= depth[x]) {
            ret += (1<<d);
            y = lca[y][d];
        }
    }
    for(int d = MAX_DEPTH-1; d > 0; d--) {
        if(lca[x][d] != lca[y][d]) {
            ret += (2<<d);
            x = lca[x][d];
            y = lca[y][d];
        }
    }
    while(x != y) {
        ret += 2;
        x = lca[x][0];
        y = lca[y][0];
    }
    return ret;
}

void update() {
    for(int i = 0; i < n; i++) {
        dp[i] = 1 << 25;
    }
    queue<int> q;
    for(int out: red) {
        q.push(out);
        dp[out] = 0;
    }
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int out: edges[curr]) {
            if(dp[out] > 1 + dp[curr]) {
                dp[out] = 1 + dp[curr];
                q.push(out);
            }
        }
    }
}

void query() {
    int type, node;
    scanf("%d%d", &type, &node);
    node--;
    if(type == 1) {
        temp.push_back(node);
        if(temp.size() == 100) {
            for(int out: temp) {
                red.push_back(out);
            }
            temp.clear();
            update();
        }
    }
    else {
        int ret = dp[node];
        for(int out: temp) {
            ret = min(ret, getDist(out, node));
        }
        printf("%d\n", ret);
    }
}

void genTree() {
    for(int i = 1; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        a--; b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        lca[i][0] = -1;
    }
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        for(int out: edges[curr]) {
            if(lca[out][0] == -1) {
                lca[out][0] = curr;
                depth[out] = 1 + depth[curr];
                q.push(out);
            }
        }
    }
    for(int a = 1; a < MAX_DEPTH; a++) {
        for(int i = 0; i < n; i++) {
            lca[i][a] = lca[lca[i][a-1]][a-1];
        }
    }
}

int main() {
    int qq;
    scanf("%d%d", &n, &qq);
    red.push_back(0);
    genTree();
    update();
    while(qq--) query();
}