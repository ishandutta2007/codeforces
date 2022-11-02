//24A
#include<cstdio>
#include<algorithm>
using namespace std;

int sum, cnt, n, t1, t2, t3, top, head[105], next[205], v[205], l[205];
bool vis[105];

void DFS(const int i) {
  vis[i] = true;
    for (int j = head[i]; j; j = next[j]) {
        if (!vis[v[j]]) {
            cnt += l[j];
            DFS(v[j]);
        } else if (i == 1 && !l[j]) {
            cnt += l[j % 2 ? j + 1 : j - 1];
        }
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &t1, &t2, &t3);
        top++; v[top] = t2; next[top] = head[t1]; head[t1] = top; l[top] = 0;
        top++; v[top] = t1; next[top] = head[t2]; head[t2] = top; l[top] = t3;
        sum += t3;
    }
  DFS(1);
    printf("%d\n", min(cnt, sum - cnt));
    return 0;
}