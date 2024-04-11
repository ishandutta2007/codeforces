#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;

#define X first
#define Y second

const int N = 1520;
const int inf = 1e9 + 10;


int n, s, m, k;
int a[N], ra[N];
int coor[N];
int v[N];
int f[N][N];

bool minimize(int &x, int y) {
    if (y < x) x = y; else return 0;
    return 1;
}
deque<int> q[N];
bool check(int val) {
    //cout << val << '\n';
    for(int i = 1; i <= n; i++) ra[i] = (a[i] <= val) ? 1 : 0;
    for(int i = 1; i <= n; i++) ra[i] += ra[i - 1];


    for(int j = 0; j <= n + 1; j++)
        for(int i = 0; i <= n + 1; i++)
            f[j][i] = inf;

    f[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= k; j++){
            minimize(f[i][j], f[i - 1][j]);
            if (v[i] >= i)
                minimize(f[v[i]][min(k, j + ra[v[i]] - ra[i - 1])], f[i - 1][j] + 1);
        }
    }
    return f[n][k] <= m;
}
void prepare() {
    cin >> n >> s >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= s; i++){
        int L, R;
        cin >> L >> R;
        v[L] = max(v[L], R);
    }
    for(int i = 1; i <= n; i++)
        v[i] = max(v[i], v[i - 1]);

    for(int i = 1; i <= n; i++) coor[i] = a[i];
    sort(coor + 1, coor + n + 1);
    coor[n + 1] = -1;
}
int main() {
    prepare();


    int L = 1, R = n;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(coor[mid])) R = mid - 1;
        else L = mid + 1;
    }
    cout << coor[L];
}