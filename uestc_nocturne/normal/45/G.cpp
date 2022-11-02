#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
int p[1000100], is[1000100], pt;
void init() {
    memset(is, 0, sizeof(is));
    pt = 0;
    int i, j;
    //  p[pt++]=1;
    for (i = 2; i <= 1000050; i++) {
        if (is[i])
            continue;
        p[pt++] = i;
        for (j = 2; j * i <= 1000050; j++)
            is[j * i] = 1;
    }
}
bool check(int x) {
    for (int i = 0; p[i] * p[i] <= x; i++)
        if (x % p[i] == 0)
            return false;
    return true;
}
int n, i, j, id;
int out[6600];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    init();
    while (~scanf("%d", &n)) {
        //if(n==3){puts("-1");continue;}
        int s = n * (n + 1) / 2;
        id = -1;
        if (check(s)) {
            for (i = 1; i <= n; i++) {
                if (i != 1)
                    printf(" ");
                printf("1");
            }
            puts("");
            continue;
        }
            memset(out, 0, sizeof(out));
        if(check(s-2))
        {
            for (i = 1; i <= n; i++) {
                    if (i != 1)
                        printf(" ");
                    if (i== 2)
                        printf("2");
                    else
                        printf("1");
                }
                puts("");
                continue;
        }
        if(s%2==0)
        {
            for (i = 0; p[i] < s; i++) {
                int te = s - p[i];
                if (check(te)) {
                    id = p[i];
                    break;
                }
            }
            if (id == 3) {
                out[3] = 1;
                for (i = 1; i <= n; i++) {
                    if (i != 1)
                        printf(" ");
                    if (out[i] == 0)
                        printf("2");
                    else
                        printf("%d", out[i]);
                }
                puts("");
            } else {
                int x = id, y;
                for (j = n; j >= 1; j--) {
                    int ts = (n - j) * (j + n + 1) / 2 + (1 << ((int) (log(
                            (double) j) / log(2.0)))) * 2 - 1;
                    //  printf("TS = %d %d\n",j,ts);
                    if (ts >= x) {
                        y = j;
                        break;
                    }
                }
                for (j = y + 1; j <= n; j++)
                    out[j] = 1;
                x -= (y + 1 + n) * (n - y) / 2;
                int t = 1;
                //printf("X = %d Y = %d\n",x,y);
                while (x > 0) {
                    if (x % 2 == 1)
                        out[t] = 1;
                    t *= 2;
                    x /= 2;
                }
                for (i = 1; i <= n; i++) {
                    if (i != 1)
                        printf(" ");
                    if (out[i] == 0)
                        printf("2");
                    else
                        printf("%d", out[i]);
                }
                puts("");
            }
        } else {
            out[3] = 3;
            for (i = 0; p[i] < s; i++) {
            int te = s-3 - p[i];
            if (check(te)) {
                id = p[i];
                break;
            }
        }//printf("%d %d %d\n",n,id,s-id);
            int x = id, y;
            for (j = n; j >= 1; j--) {
                int ts = (n - j) * (j + n + 1) / 2 + (1 << ((int) (log(
                        (double) j) / log(2.0)))) * 2 - 1;
                //  printf("TS = %d %d\n",j,ts);
                if (ts >= x) {
                    y = j;
                    break;
                }
            }
            for (j = y + 1; j <= n; j++)
                out[j] = 1;
            x -= (y + 1 + n) * (n - y) / 2;
            int t = 1;
            //printf("X = %d Y = %d\n",x,y);
            while (x > 0) {
                if (x % 2 == 1)
                    out[t] = 1;
                t *= 2;
                x /= 2;
            }
            for (i = 1; i <= n; i++) {
                if (i != 1)
                    printf(" ");
                if (out[i] == 0)
                    printf("2");
                else
                    printf("%d", out[i]);
            }
            puts("");
        }
    }
}