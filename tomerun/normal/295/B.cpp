#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

int N;
int L[500][500];
int P[500][500];
int X[500];
bool visited[500];

struct State {
    int pos, len;
};

bool operator<(const State& l, const State& r) {
    return l.len > r.len;
}

void dijkstra(int st) {
    priority_queue<State> q;
    q.push({st, 0});
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        if(P[st][cur.pos] < cur.len) continue;
        P[st][cur.pos] = cur.len;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) continue;
            if (P[st][i] <= cur.len + L[cur.pos][i]) continue;
            P[st][i] = cur.len + L[cur.pos][i];
            q.push({i, P[st][i]});
        }
    }
    q.push({st, 0});
    while (!q.empty()) {
        auto cur = q.top();
        q.pop();
        if(P[cur.pos][st] < cur.len) continue;
        P[cur.pos][st] = cur.len;
        for (int i = 0; i < N; ++i) {
            if (!visited[i]) continue;
            if (P[i][st] <= cur.len + L[i][cur.pos]) continue;
            P[i][st] = cur.len + L[i][cur.pos];
            q.push({i, P[i][st]});
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            scanf("%d", L[i]+j);
            P[i][j] = 1 << 30;
        }
    }
    for (int i = 0; i < N; ++i) {
        scanf("%d", X+i);
        --X[i];
    } 
    ll ans[500];
    for (int i = N-1; i >= 0; --i) {
        dijkstra(X[i]);
        for (int j = i+1; j < N; ++j){
            for (int k = i+1; k < N; ++k) {
                if (P[X[j]][X[k]] > P[X[j]][X[i]] + P[X[i]][X[k]]) {
                    P[X[j]][X[k]] = P[X[j]][X[i]] + P[X[i]][X[k]];
                }
            }
        }
        visited[X[i]] = true;
        ans[i] = 0;
        for (int j = i; j < N; ++j){
            for (int k = i; k < N; ++k) {
                ans[i] += P[X[j]][X[k]];
            }
        }
    }
    for (int i = 0; i < N; ++i) {
        cout << ans[i];
        if (i < N-1) cout << " ";
    }
    cout << endl;
}