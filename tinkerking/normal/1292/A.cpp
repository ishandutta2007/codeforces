#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int N,Q;
int lava[3][100010];
int cnt = 0;

int main() {
    scanf("%d%d",&N,&Q);
    while(Q--) {
        int x,y;
        scanf("%d%d",&x,&y);
        if (lava[x][y]) {
            lava[x][y] = 0;
            bool b1 = false;
            for (int i=y-1;i<=y+1;i++) {
                if (i < 1 || i > N) continue;
                if (lava[3-x][i]) {
                    b1 = true;
                    bool b2 = false;
                    for (int j=i-1;j<=i+1;j++) {
                        if (j < 1 || j > N) continue;
                        if (lava[x][j]) {
                            b2 = true;
                        }
                    }
                    if (!b2) {
                        cnt--;
                    }
                }
            }
            cnt -= b1;
        } else {
            bool b1 = false;
            for (int i=y-1;i<=y+1;i++) {
                if (i < 1 || i > N) continue;
                if (lava[3-x][i]) {
                    b1 = true;
                    bool b2 = false;
                    for (int j=i-1;j<=i+1;j++) {
                        if (j < 1 || j > N) continue;
                        if (lava[x][j]) {
                            b2 = true;
                        }
                    }
                    if (!b2) {
                        cnt++;
                    }
                }
            }
            cnt += b1;
            lava[x][y] = 1;
        }
        puts(cnt ? "No":"Yes");
    }
}