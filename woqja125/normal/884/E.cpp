
#include <cstdio>
#include <queue>

int dx[] = {-1, 0};
int dy[] = {0, -1};

int p[2*(1<<14)];

char in[2][(1<<12)+1];

int n, m;
int get(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return -1;
    char c = in[x&1][y>>2];
    int v = 0;
    if(c >= '0' && c <= '9') v = c - '0';
    else v = c - 'A' + 10;
    v = (v>>((y&3)^3))&1;
    if(v == 0) return -1;
    return ((x&1)<<14) + y;
}

short R(int x) {
    if(p[x] == x) return x;
    return p[x] = R(p[x]);
}

int uni(int x, int y) {
    x = R(x); y = R(y);
    if(x == y) return 0;
    p[y] = x;
    return 1;
}

int main() {
    int ans = 0;
    scanf("%d%d ", &n, &m);
    for(int i=0; i<=(1<<14); i+=(1<<14)) for(int j=0; j<m; j++) p[i+j] = i+j;

    for(int i=0; i<n; i++) {
        scanf("%s", in[i&1]);
        int b = ((i&1)^1)<<14;
        b = ((i&1))<<14;
        for(int j=0; j<m; j++) {
            p[b+j] = b+j;
        }

        for(int y=0; y<m; y++) {
            int u = get(i, y);
            if(u == -1) continue;
            ans++;
                //printf("*%d %d %d\n", i, y, ans);
            for(int d=0; d<2; d++) {
                int v = get(i+dx[d], y+dy[d]);
                if(v==-1) continue;
                ans -= uni(u, v);
                //printf("^%d %d %d %d\n", i, y, d, ans);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}