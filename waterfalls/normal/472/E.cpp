#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Ball { int color,x,y,goX,goY;};

int n,m;
Ball balls[30][30];
Ball* c;
int A[30][30];
int tmp[30][30];
int B[30][30];
Ball* cur[30][30];
Ball* need[30][30];
vector<int> print;

void go(int dx, int dy) {
    int x = c->x, y = c->y;
    int nx = x+dx, ny = y+dy;
    print.push_back(nx*m+ny);
    Ball* next = cur[nx][ny];
    swap(cur[x][y],cur[nx][ny]);
    c->x = nx, c->y = ny;
    next->x = x, next->y = y;
}

void solve1() {
    int ok = 0;
    for (int a=0;a<m && !ok;a++) {
        for (int b=0;b<m && !ok;b++) {
            print.clear();
            for (int i=0;i<m;i++) tmp[0][i] = A[0][i];
            int cur = a;
            print.push_back(cur);
            while (cur<b) swap(tmp[0][cur],tmp[0][cur+1]), cur+=1, print.push_back(cur);
            while (cur>b) swap(tmp[0][cur],tmp[0][cur-1]), cur-=1, print.push_back(cur);
            int good = 1;
            for (int i=0;i<m;i++) if (tmp[0][i]!=B[0][i]) good = 0;
            if (good) ok = 1;
        }
    }
    if (!ok) print.clear();
}

void getvert(Ball* which, int off) {
    if (c->x!=n-1) go(1,0);
    if (c->x==which->x) go(which->x==n-1 ? -1 : 1,0);
    while (c->y<which->y) go(0,1);
    while (c->y>which->y) go(0,-1);
    while (c->x<which->x+off) go(1,0);
    while (c->x>which->x+off) go(-1,0);
}

void solve() {
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        int found = 0;
        for (int a=0;a<n && !found;a++) for (int b=0;b<m && !found;b++) {
            if (cur[a][b]->goX==-1 && cur[a][b]->color==B[i][j]) {
                found = 1;
                cur[a][b]->goX = i; cur[a][b]->goY = j;
                need[i][j] = cur[a][b];
            }
        }
        if (found==0) return;
    }
    c = need[n-1][m-1];
    print.push_back(c->x*m+c->y);
    for (int i=0;i<n-2;i++) for (int j=0;j<m;j++) {
        if (need[i][j]->x==n-1) getvert(need[i][j],-1), go(1,0);
        else getvert(need[i][j],+1);
        while (c->y!=j) {
            int l = c->y>j;
            go(-1,l ? -1 : 1);
            go(0,l ? 1 : -1);
            go(1,l ? -1 : 1);
        }
        while (c->x>i+1) {
            int l = j>0;
            go(-1,l ? -1 : 1);
            go(-1,l ? 1 : -1);
            go(1,0);
        }
    }
    while (c->y>0) go(0,-1);
    if (c->x!=n-1) go(1,0);
    for (int j=0;j<m-2;j++) for (int i=n-2;i<n;i++) {
        if (need[i][j]->x==i && need[i][j]->y==j) {
            if (i==n-2) go(-1,1);
            else go(1,0);
            continue;
        }
        if (c->x==need[i][j]->x) go(c->x==n-1 ? -1 : 1,0);
        while (c->y<need[i][j]->y) go(0,1);
        if (need[i][j]->x!=i) go(c->x==n-1 ? -1 : 1,0);
        go(c->x==n-1 ? -1 : 1,-1);
        go(0,1);
        while (need[i][j]->y>j) {
            int d = c->x==n-1;
            go(d ? -1 : 1,-1);
            go(d ? 1 : -1,-1);
            go(0,1);
        }
    }
    if (need[n-2][m-2]->x!=n-2 || need[n-2][m-2]->y!=m-2) {
        go(-1,0);
        go(need[n-2][m-2]->x-c->x,need[n-2][m-2]->y-c->y);
        if (c->y==m-1) go(c->x==n-1 ? 0 : 1,-1);
    }
    if (need[n-1][m-2]->x!=n-1 || need[n-1][m-2]->y!=m-2) go(need[n-1][m-2]->x-c->x,need[n-1][m-2]->y-c->y);
    if (c->x!=n-1) go(1,0);
}

int main() {
    scanf("%d%d",&n,&m);
    int flip = 0;
    if (min(n,m)==1 && m==1) flip = 1, swap(n,m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&A[i][j]);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) scanf("%d",&B[i][j]);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
        Ball next;
        next.color = A[i][j]; next.x = i; next.y = j; next.goX = -1;
        balls[i][j] = next;
        cur[i][j] = &balls[i][j];
    }
    if (min(n,m)==1) solve1();
    else solve();
    if (flip) swap(n,m);
    if (print.size()) {
        printf("%d\n",print.size()-1);
        for (int i=0;i<print.size();i++) printf("%d %d\n",print[i]/m+1,print[i]%m+1);
    } else printf("-1\n");
}