#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int s[222222];
int a[211111];
int n;
void inc(int x, int delta) {
    s[x] += delta;
    while((x += x & -x) <= n)
        s[x] += delta;
}
int getsum(int x) {
    int rtn(s[x]);
    while(x -= x & -x)
        rtn += s[x];
    return rtn;
}
int getposi(int x) {
    return getsum(x) - getsum(x - 1);
}
int main()
{
    int m;
    scanf("%d%d", &n, &m);
    memset(s, 0, sizeof(s));
    for(int i(1); i <= n; i++)
        inc(i, 1);
    int bg(1), ed(n);
    bool fp(false);
    for(int i(1); i <= m; i++) {
        int tp;
        scanf("%d", &tp);
        if(tp == 1) {
            int x;
            scanf("%d", &x);
            if(x * 2 <= ed - bg + 1) {
                if(!fp) {
                    for(int j(1); j <= x; j++) {
                        //printf("!%d\n", getposi(bg + j - 1));
                        inc(bg + 2 * x - j, getposi(bg + j - 1));
                        inc(bg + j - 1, -getposi(bg + j - 1));
                    }
                    bg += x;
                }else {
                    for(int j(1); j <= x; j++) {
                        inc(ed - 2 * x + j, getposi(ed - j + 1));
                        inc(ed - j + 1, -getposi(ed - j + 1));
                    }
                    ed -= x;
                }
            }else {
                x = ed - bg + 1 - x;
                if(fp) {
                    for(int j(1); j <= x; j++) {
                        inc(bg + 2 * x - j, getposi(bg + j - 1));
                        inc(bg + j - 1, -getposi(bg + j - 1));
                    }
                    bg += x;
                }else {
                    for(int j(1); j <= x; j++) {
                        inc(ed - 2 * x + j, getposi(ed - j + 1));
                        inc(ed - j + 1, -getposi(ed - j + 1));
                    }
                    ed -= x;
                }
                fp ^= 1;
            }
        }else {
            int x, y;
            scanf("%d%d", &x, &y);
            x++;
            if(fp) {
                x = ed - bg + 1 - x + 1;
                y = ed - bg + 1 - y + 1;
                swap(x, y);
            }
            printf("%d\n", getsum(bg + y - 1) - getsum(bg + x - 2));
        }
    }
    fclose(stdin);
    return 0;
}