#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int b[8] = {0, 1,6,4,2,3,5,4};

int ask_and(int x, int y) {
    //return b[x] & b[y];
    printf("and %d %d\n",x,y);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int ask_or(int x, int y) {
    //return b[x] | b[y];
    printf("or %d %d\n",x,y);
    fflush(stdout);
    int ret;
    scanf("%d",&ret);
    return ret;
}

int n, k;
int ans[2][2][2][2][2][2][3];
int a[10100];

int sft(int x, int y) {
    return (x >> y) & 1;
}

int main() {
    for (int v1 = 0; v1 <= 1; v1++) {
        for (int v2 = 0; v2 <= 1; v2++) {
            for (int v3 = 0; v3 <= 1; v3++) {
                int a12 = v1 & v2;
                int a13 = v1 & v3;
                int a23 = v2 & v3;
                int o12 = v1 | v2;
                int o13 = v1 | v3;
                int o23 = v2 | v3;
                ans[a12][a13][a23][o12][o13][o23][0] = v1;
                ans[a12][a13][a23][o12][o13][o23][1] = v2;
                ans[a12][a13][a23][o12][o13][o23][2] = v3;
                //printf("? %d %d %d : %d %d %d %d %d %d\n",v1,v2,v3,a12,a13,a23,o12,o13,o23);
            }
        }
    }
    scanf("%d%d",&n,&k);
    int a12 = ask_and(1, 2);
    int o12 = ask_or(1, 2);
    for (int i = 3; i <= 3; i++) {
        int a13 = ask_and(1, i);
        int a23 = ask_and(2, i);
        int o13 = ask_or(1, i);
        int o23 = ask_or(2, i);
        //printf("? %d: %d %d %d %d %d %d\n",i,a12,a13,a23,o12,o13,o23);
        for (int b = 30; b >= 0; b--) {
            a[1] |= ans[sft(a12, b)][sft(a13, b)][sft(a23, b)][sft(o12, b)][sft(o13, b)][sft(o23, b)][0] << b;
            a[2] |= ans[sft(a12, b)][sft(a13, b)][sft(a23, b)][sft(o12, b)][sft(o13, b)][sft(o23, b)][1] << b;
            a[i] |= ans[sft(a12, b)][sft(a13, b)][sft(a23, b)][sft(o12, b)][sft(o13, b)][sft(o23, b)][2] << b;
        }
    }
    int qaq[2][2][2];
    for (int v1 = 0; v1 <= 1; v1++) {
        for (int v2 = 0; v2 <= 1; v2++) {
            int a = v1 & v2;
            int o = v1 | v2;
            qaq[a][o][v1] = v2;
            //printf("%d %d %d %d\n",a,o,v1,v2);
        }
    }
    for (int i = 4; i <= n; i++) {
        int a1i = ask_and(1, i);
        int o1i = ask_or(1, i);
        for (int b = 0; b <= 30; b++) {
            a[i] |= qaq[sft(a1i, b)][sft(o1i, b)][sft(a[1], b)] << b;
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d ",a[i]);puts("");
    sort(a+1,a+n+1);
    printf("finish %d\n",a[k]);
    fflush(stdout);
}