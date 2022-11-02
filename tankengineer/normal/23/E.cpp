//23E
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

struct gjd {
    int l, num[30];
    gjd(int n = 0) {
        memset(num, 0, sizeof(num));
        l = 1; num[1] = n;
    }

    void print() {
        printf("%d", num[l]);
        for (int i = l - 1; i > 0; i--) printf("%04d", num[i]);
        printf("\n");
    }

    gjd operator * (const gjd &b) {
    gjd c;
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= b.l; j++) {
                c.num[i + j - 1] += num[i] * b.num[j];
            }
        }
        c.l = l + b.l;
        for (int i = 1; i < c.l; i++) {
            c.num[i + 1] += c.num[i] / 10000;
            c.num[i] %= 10000;
        }
        if (!c.num[c.l]) c.l--;
        return c;
    }

    bool operator < (const gjd &b) {
    if (l < b.l) {
          return true;
        } else if (l > b.l) {
            return false;
        }
        for (int i = l; i > 0; i--) {
            if (num[i] > b.num[i]) {
                return false;
            } else if (num[i] < b.num[i]) {
                return true;
            }
        }
        return false;
    }


} dp[705][705];

int top, t1, t2, v[1405], next[1405], head[705], cnt[705], n;
bool vis[705];

gjd maxs(gjd a, gjd b) {return a < b ? b : a;}

void DFS(const int &i) {
  vis[i] = true;
    cnt[i] = 1;
    dp[i][1] = gjd(1);
    for (int j = head[i]; j; j = next[j]) {
        if (vis[v[j]]) continue;
        DFS(v[j]);
        for (int k = cnt[i]; k > 0; k--) {
          for (int l = cnt[v[j]]; l >= 0; l--) {
                dp[i][k + l] = maxs(dp[i][k + l], dp[i][k] * dp[v[j]][l]);
            }
        }
        cnt[i] += cnt[v[j]];
    }
    for (int j = 1; j <= cnt[i]; j++) dp[i][0] = maxs(dp[i][0], dp[i][j] * gjd(j));
    dp[i][0] = maxs(dp[i][0], gjd(cnt[i]));
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &t1, &t2);
        top++; v[top] = t2; next[top] = head[t1]; head[t1] = top;
        top++; v[top] = t1; next[top] = head[t2]; head[t2] = top;
    }
    DFS(1);
    dp[1][0].print();
  return 0;
}