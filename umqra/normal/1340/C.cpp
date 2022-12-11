#include <bits/stdc++.h>

using namespace std;

const int N = (int)1e4 + 10;
const int T = 2010;
pair<int, int> q[T][N];
int q_bot[T], q_top[T];
bool used[N][T];
int q_sum = 0;
int p[N];
int g, r;
set<int> filled_q;
bool is_filled[T];

void push(int q_id, int pos, int t) {
    if (used[pos][t % g]) {
        return;
    }
    if (!is_filled[q_id % T]) {
        filled_q.insert(q_id);
        is_filled[q_id % T] = true;
    }
    used[pos][t % g] = 1;
    q_sum++;
    q[q_id % T][(q_top[q_id % T]++) % N] = make_pair(pos, t);
}

pair<int, int> pop(int q_id) {
    q_sum--;
    auto res = q[q_id % T][(q_bot[q_id % T]++) % N];
    if (q_bot[q_id % T] == q_top[q_id % T]) {
        is_filled[q_id % T] = false;
        filled_q.erase(q_id);
    }
    return res;
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    sort(p, p + m);
    scanf("%d%d", &g, &r);
    push(0, 0, 0);

    int cur = 0;
    while (q_sum > 0) {
        while (q_bot[cur % T] != q_top[cur % T]) {
            auto [pos, time] = pop(cur);
            if (pos == m - 1) {
                int count = (time - 1) / g;
                printf("%d\n", time + count * r);
                return 0;
            }
            int hit_time = (time / g + 1) * g - time;
            if (pos > 0) {
                int d = p[pos] - p[pos - 1];
                if (d <= hit_time) {
                    push(cur + d, pos - 1, time + d);
                }
            }
            if (pos + 1 < m) {
                int d = p[pos + 1] - p[pos];
                if (d <= hit_time) {
                    push(cur + d, pos + 1, time + d);
                }
            }
        }
        if (q_sum > 0) {
            cur = *filled_q.lower_bound(cur);
        }
    }
    puts("-1");

    return 0;
}