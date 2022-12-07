#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 1000005
using namespace std;
int n, m;
struct edge{
    int to, next;
    edge(int to, int next) : to(to), next(next) {}
    edge(){}
}e[maxn << 1];

int cnt = 1, h[maxn];
void Add_Edge(int fr, int to){
    e[++cnt] = edge(to, h[fr]);
    h[fr] = cnt;
    e[++cnt] = edge(fr, h[to]);
    h[to] = cnt;
}

double DP(int x, int fa){
    double ans = 0;
    int k = 0;
    for (int i = h[x]; i; i = e[i].next){
        int op = e[i].to;
        if (op == fa) continue;
        ans += DP(op, x) + 1;
        k++;
    }
    if (k == 0) return 0;
    return ans / k;
}

int main(){
    scanf("%d", &n);
    int x, y;
    for (int i = 1; i < n; i++){
        scanf("%d%d", &x, &y);
        Add_Edge(x, y);
    }
    printf("%.10lf", DP(1, 1));
    return 0;
}