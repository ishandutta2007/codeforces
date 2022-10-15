#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N(111);
struct Train {
    int x, y, len;
    Train(int x, int y, int len) : x(x), y(y), len(len) {
    }
};
__inline bool check(int x, int y, vector<Train> & trains, int t) {
    for(int i(0); i < (int)trains.size(); i++) {
        if(trains[i].x == x && trains[i].y - (t - 1) * 2 <= y && y <= trains[i].y + trains[i].len - 1 - (t - 1) * 2) {
            return false;
        }
    }
    return true;
}
bool ok[7][N];
char st[N];
int main() {
    int tests;
    scanf("%d", &tests);
    for(int qq(1); qq <= tests; qq++) {
        int n, k;
        scanf("%d%d", &n, &k);
        vector<Train> trains;
        int init;
        for(int i(1); i <= 3; i++) {
            scanf("%s", st);
            if(st[0] == 's') {
                init = i;
            }
            for(int j(0); j < n; j++) {
                if(st[j] != 's' && st[j] != '.') {
                    int k(j);
                    for(; k < n; k++) {
                        if(st[k] != st[j]) {
                            break;
                        }
                    }
                    trains.push_back(Train(i, j + 1, k - j));
                    //printf("%d %d %d\n", i, j + 1, k - j);
                    j = k - 1;
                }
            }
        }
        for(int i(1); i <= 3; i++) {
            for(int j(1); j <= n; j++) {
                ok[i][j] = false;
            }
        }
        ok[init][1] = true;
        //printf("%d\n", init);
        for(int j(1); j < n; j++) {
            for(int i(1); i <= 3; i++) {
                if(ok[i][j]) {
                    //printf("%d %d\n", i, j);
                    if(i > 1 && check(i, j + 1, trains, j) && check(i - 1, j + 1, trains, j) && check(i - 1, j + 1, trains, j + 1)) {
                        ok[i - 1][j + 1] = true;
                    }
                    if(i < 3 && check(i, j + 1, trains, j) && check(i + 1, j + 1, trains, j) && check(i + 1, j + 1, trains, j + 1)) {
                        ok[i + 1][j + 1] = true;
                    }
                    if(check(i, j + 1, trains, j) && check(i, j + 1, trains, j + 1)) {
                        ok[i][j + 1] = true;
                    }
                }
            }
        }
        printf("%s\n", ok[1][n] || ok[2][n] || ok[3][n] ? "YES" : "NO");
    }
}