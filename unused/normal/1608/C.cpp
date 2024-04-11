#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

pair<int, int> a[100005], b[100005];
vector<int> graph[100005];
bool visit[100005];

void dfs(int t)
{
    visit[t] = true;
    for (int nxt : graph[t])
    {
        if (!visit[nxt]) dfs(nxt);
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%d", &a[i].first);
        for (int i = 0; i < n; i++) scanf("%d", &b[i].first);
        for (int i = 0; i < n; i++) a[i].second = i;
        for (int i = 0; i < n; i++) b[i].second = i;

        sort(a, a + n, greater<>());
        for (int i = 1; i < n; i++) graph[a[i].second].push_back(a[i - 1].second);
        sort(b, b + n, greater<>());
        for (int i = 1; i < n; i++) graph[b[i].second].push_back(b[i - 1].second);

        dfs(a[0].second);
        dfs(b[0].second);

        for (int i = 0; i < n; i++) printf("%d", visit[i]);
        printf("\n");

        for (int i = 0; i < n; i++) graph[i].clear();
        for (int i = 0; i < n; i++) visit[i] = false;
    }
}