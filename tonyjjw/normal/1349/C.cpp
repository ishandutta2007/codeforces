#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
#define fst first
#define snd second

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int MN = 1e3 + 1;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int N, M, Q;
int A[MN][MN];
int good_time[MN][MN];

int main() {
    scanf("%d%d%d", &N, &M, &Q);
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &A[i][j]);
            good_time[i][j] = -1;
        }
    }

    queue<pii> que;
    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < 4; k++) {
                int nx = i + dx[k], ny = j + dy[k];
                if (nx < 0 || ny < 0 || nx >= N || ny >= M)
                    continue;
                if(!(A[i][j] ^ A[nx][ny]))
                    good_time[i][j] = 0;
            }
            if (good_time[i][j] == 0)
                que.emplace(i, j);
        }
    }
    while(!que.empty()) {
        auto head = que.front();
        que.pop();
        for (int k = 0; k < 4; k++) {
            int nx = head.fst + dx[k], ny = head.snd + dy[k];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M)
                continue;
            if(good_time[nx][ny] == -1) {
                good_time[nx][ny] = good_time[head.fst][head.snd] + 1;
                que.emplace(nx, ny);
            }
        }
    }
    for(int q = 0; q < Q; q++) {
        int x, y;
        ll t;
        scanf("%d%d%lld", &x, &y, &t); x--, y--;
        if (good_time[x][y] == -1)
            printf("%d\n", A[x][y]);
        else
            printf("%d\n", A[x][y] ^ max(0ll, (t - good_time[x][y])) & 1);
    }
    return 0;
}