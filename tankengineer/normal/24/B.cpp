//24B
#include<cstdio>
#include<cstring>

const int p[11] = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};

int t, n, t1, top, point[55], wins[55][55], win;
char name[55], names[55][55];

bool cmp1(const int a, const int b) {
    if (point[a] < point[b]) return true;
    if (point[a] > point[b]) return false;
    for (int i = 1; i <= 50; i++) {
        if (wins[a][i] < wins[b][i]) return true;
        if (wins[a][i] > wins[b][i]) return false;
    }
    return false;
}

bool cmp2(const int a, const int b) {
    if (wins[a][1] < wins[b][1]) return true;
    if (wins[a][1] > wins[b][1]) return false;
    if (point[a] < point[b]) return true;
    if (point[a] > point[b]) return false;
    for (int i = 2; i <= 50; i++) {
        if (wins[a][i] < wins[b][i]) return true;
        if (wins[a][i] > wins[b][i]) return false;
    }
    return false;
}


int main() {
    scanf("%d", &t);
    for (; t; t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%s", &name);
            t1 = 0;
            for (int j = 1; j <= top; j++) {
                if (!strcmp(names[j], name)) {
                    t1 = j;
                    break;
                }
            }
            if (!t1) {
                t1 = ++top;
                for (int k = 0; k < strlen(name); k++) names[top][k] = name[k];
            }
            wins[t1][i] ++;
            if (i <= 10) point[t1] += p[i];
        }
    }

  win = 1;
    for (int i = 2; i <= top; i++) if (cmp1(win, i)) win = i;
    printf("%s\n", names[win]);
    win = 1;
    for (int i = 2; i <= top; i++) if (cmp2(win, i)) win = i;
    printf("%s\n", names[win]);

  return 0;
}