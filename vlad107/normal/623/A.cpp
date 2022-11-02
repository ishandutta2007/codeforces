#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
 
using namespace std;
 
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << "(" << #x << ", " << #y << ") = (" << x << ", " << y << ")\n";
#define sz(a) (int)(a).size()
#define all(a) (a).begin(), (a).end()
 
#define equal equalll
#define less lesss

const int N = 1111;
const int INF = 1e9 + 19;

int a[N], n, m, g[N][N];
 
int main(){
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        g[u][v] = g[v][u] = 1;
    }
    int x = -1;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (!g[i][j]) {
                flag = true;
                break;
            }
        }
        if (flag) {
            x = i;
            break;
        }
    }
    if (x < 0) {
        puts("Yes");
        for (int i = 0; i < n; i++) putchar('b');
        return 0;
    }
    memset(a, -1, sizeof(a));
    a[x] = 0;
    for (int i = 0; i < n; i++) {
        if ((i != x) && (g[i][x] == 0)) a[i] = 2;
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) {
            for (int j = 0; j < n; j++) {
                if ((g[i][j] == 0) && (i != j)) a[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (a[i] < 0) a[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int ng = abs(a[i] - a[j]) <= 1;
            if (g[i][j] != ng) {
                puts("No"); 
                return 0;
            }
        }
    }
    puts("Yes");
    for (int i = 0; i < n; i++) putchar(a[i] + 'a');
    return 0;
}