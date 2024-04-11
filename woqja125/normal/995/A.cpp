#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int d[101];
int l[101];
int map[4][101];
struct P {
    int a, b, c;
};
std::vector<P> out;
int n, k;
int next(int x) {
    x++;
    if(x == 0) x = 1;
    if(x == n+1) x = -n;
    return x;
}
int &Map(int x) {
    if(x < 0) return map[1][-x];
    else return map[2][x];
}
void print(int x, int l, int type = 0) {
    int r = 0;
    if(l > 0) r = 3;
    else r = 2;
    if(type) r = r*3 - 5;
    l = abs(l);
    out.push_back({x, r, l});
 //   printf("%%%d %d %d\n", x, r, l);
}
int main() {
    scanf("%d%d", &n, &k);
    for(int i=0; i<4; i++) for(int j=1; j<=n; j++) scanf("%d", &map[i][j]);
    for(int i=1; i<=n; i++) d[map[0][i]] = -i;
    for(int i=1; i<=n; i++) l[map[1][i]] = -i;
    for(int i=1; i<=n; i++) l[map[2][i]] = i;
    for(int i=1; i<=n; i++) d[map[3][i]] = i;

    int empty = l[0];
    int remain = k;
    int f = 1;
    do {
        if(f) f = 0;
        else {
            if(empty == 0) { 
                printf("-1\n");
                return 0;
            }
            int i = empty, t;
            do{
                t = next(i);
                //printf("&&%d %d %d\n", i, t, Map(t));
                Map(i) = Map(t);
                l[Map(i)] = i;
                if(Map(i) != 0) {
                    print(Map(i), i);
                }
                i = t;
            } while(next(i) != empty);
            Map(empty = i) = 0;
        }
        for(int i=1; i<=k; i++) {
            if(d[i] == l[i]) {
                print(i, d[i], 1);
                remain--;
                empty = l[i];
                Map(l[i]) = 0;
                l[i] = 0;
     //   for(int i=0; i<4; printf("\n", i++)) for(int j=1; j<=n; j++) printf(")%d ", map[i][j]);
            }
        }
    } while(remain > 0);
    printf("%u\n", out.size());
    for(auto e:out) {
        printf("%d %d %d\n", e.a, e.b, e.c);
    }
    return 0;
}