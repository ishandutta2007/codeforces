#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const int INF = 100100;
const int N = 1000;
const int M = 2 * N + 7;
const int Z = 1002;
bool a[M];
int m;
int dist[M];
int q[M];
int topQ;

void read()
{
    int n;
    scanf("%d%d", &m, &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        a[x] = 1;
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i < M; i++)
        dist[i] = INF;
    for (int i = 0; i <= N; i++)
    {
        if (a[i])
        {
            int v = Z + i - m;
            dist[v] = 1;
            q[topQ++] = v;
        }
    }
    for (int k = 0; k < topQ; k++)
    {
        int v = q[k];
        for (int p = 0; p <= N; p++)
        {
            if (!a[p]) continue;
            int u = v + p - m;
            if (u < 0 || u >= M) continue;
            if (dist[u] <= dist[v] + 1) continue;
            dist[u] = dist[v] + 1;
            q[topQ++] = u;
        }
    }
    if (dist[Z] < INF)
        printf("%d\n", dist[Z]);
    else
        printf("-1\n");

    return 0;
}