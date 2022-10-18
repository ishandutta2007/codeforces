using namespace std;
#include <cstdio>
#include <queue>

int d[10005];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    queue<int> q;
    q.push(n);
    d[n] = 1;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        int x = u*2;
        if (x <= 10000 && !d[x]) {
            q.push(x);
            d[x] = d[u]+1;
        }
        x = u-1;
        if (x > 0 && !d[x]) {
            q.push(x);
            d[x] = d[u]+1;
        }
    }

    printf("%d", d[m]-1);

}