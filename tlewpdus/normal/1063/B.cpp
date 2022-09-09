#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m, s, t, x, y;
char ma[2010][2010];

bool ok(int x, int y) {return x>=0&&x<n&&y>=0&&y<m;}

int px[] = {1,0,-1,0};
int py[] = {0,1,0,-1};
int dis[2010][2010];
void bfs() {
    deque<pii> q;
    q.push_back(pii(0,s*m+t));
    dis[s][t] = 0;
    while(!q.empty()) {
        int x = q.front().second/m, y = q.front().second%m, w = q.front().first;
        q.pop_front();
        if (dis[x][y]!=w) continue;
        for (int d=0;d<4;d++) {
            int nx = x+px[d], ny = y+py[d];
            if (!ok(nx,ny)||ma[nx][ny]=='*') continue;
            if (dis[nx][ny]==-1||dis[nx][ny]>w+d%2) {
                dis[nx][ny]=w+d%2;
                if (d%2) q.push_back(pii(w+d%2,nx*m+ny));
                else q.push_front(pii(w,nx*m+ny));
            }
        }
    }
    int i, j, ans = 0;
    for (i=0;i<n;i++) {
        for (j=0;j<m;j++) {
            if (ma[i][j]=='*'||dis[i][j]<0) continue;
            int r = (dis[i][j]+j-t)/2, l = (dis[i][j]-j+t)/2;
            if (l<=x&&r<=y) ans++;
        }
    }
    printf("%d\n",ans);
}

int main() {
    int i, j;

    memset(dis,-1,sizeof(dis));
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    scanf("%d%d",&x,&y);
    s--;t--;
    for (i=0;i<n;i++) {
        scanf("%s",ma[i]);
    }
    bfs();

    return 0;
}