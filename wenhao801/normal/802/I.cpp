#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 200200;
struct SAM { int slink, len, trans[26]; bool pre; } t[MAXN];
int top = 1, las = 1;

void add (int c){
    int tmp = ++top; t[tmp].len = t[las].len + 1, t[tmp].pre = true;
    int i, j;
    for (i = las; i && !t[i].trans[c]; i = t[i].slink) t[i].trans[c] = tmp;
    if (!i) t[tmp].slink = 1;
    else {
        int rua = t[i].trans[c];
        if (t[rua].len == t[i].len + 1) t[tmp].slink = rua;
        else {
            int cl = ++top; t[cl] = t[rua];
            t[cl].len = t[i].len + 1;
            for (j = i; t[j].trans[c] == rua; j = t[j].slink) t[j].trans[c] = cl;
            t[tmp].slink = t[rua].slink = cl;
            t[cl].pre = false;
        }
    }
    las = tmp;
}

inline int read () {
    char c = getchar(); int len = 0;
    while (c < 'a' || c > 'z') c = getchar();
    while (c >= 'a' && c <= 'z') ++len, add(c - 'a'), c = getchar();
    return len;
}

int inn[MAXN], eplen[MAXN];
bool vis[MAXN];
queue <int> q;

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        int i, j;
        for (i = 1; i <= top; i++) {
            t[i].len = t[i].pre = t[i].slink = 0;
            for (j = 0; j < 26; j++) t[i].trans[j] = 0;
        }
        top = las = 1;
        read();
        for (i = 1; i <= top; i++) inn[i] = vis[i] = eplen[i] = 0;
        for (i = 2; i <= top; i++) ++inn[t[i].slink];
        for (i = 2; i <= top; i++) if (!inn[i]) q.push(i);
        while (!q.empty()) {
            int f = q.front(); q.pop();
            vis[f] = true;
            eplen[f] += t[f].pre;
            --inn[t[f].slink], eplen[t[f].slink] += eplen[f];
            if (!inn[t[f].slink] && !vis[t[f].slink]) 
                q.push(t[f].slink), vis[t[f].slink] = true;
        }
        long long ans = 0;
        for (i = 2; i <= top; i++) ans += 1ll * (t[i].len - t[t[i].slink].len) * eplen[i] * eplen[i];
        printf("%lld\n", ans);
    }
    return 0;
}