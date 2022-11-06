#include <bits/stdc++.h>
using namespace std;

const int kN = 1'000'000 + 5;
const int kInf = 1'000'000'000;
int nd[kN * 4], mk[kN * 4], tg[kN * 4];
char s[kN], t[kN];

void Push(int o) {
    for (int i = 1; i <= 2; ++i) {
        nd[o * 2 + i] += tg[o];
        mk[o * 2 + i] += tg[o];
        tg[o * 2 + i] += tg[o];
    }
    tg[o] = 0;
}

void Modify(int l, int r, int ql, int qr, int v, int o = 0) {
    if (l >= qr || ql >= r) return;
    if (l >= ql && r <= qr) {
        nd[o] += v;
        mk[o] += v;
        tg[o] += v;
        return;
    }
    Push(o);
    Modify(l, (l + r) >> 1, ql, qr, v, o * 2 + 1);
    Modify((l + r) >> 1, r, ql, qr, v, o * 2 + 2);
    nd[o] = max(nd[o * 2 + 1], nd[o * 2 + 2]);
    mk[o] = min(mk[o * 2 + 1], mk[o * 2 + 2]);
}

int QueryMax(int l, int r, int ql, int qr, int o = 0) {
    if (l >= qr || ql >= r) return -kInf;
    if (l >= ql && r <= qr) return nd[o];
    Push(o);
    return max(QueryMax(l, (l + r) >> 1, ql, qr, o * 2 + 1),
               QueryMax((l + r) >> 1, r, ql, qr, o * 2 + 2));
}

int QueryMin(int l, int r, int ql, int qr, int o = 0) {
    if (l >= qr || ql >= r) return kInf;
    if (l >= ql && r <= qr) return mk[o];
    Push(o);
    return min(QueryMin(l, (l + r) >> 1, ql, qr, o * 2 + 1),
               QueryMin((l + r) >> 1, r, ql, qr, o * 2 + 2));
}

int main() {
    int n; scanf("%d", &n);
    scanf("%s", s);
    int p = 0, sum = 0;
    set<int> pos;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') {
            if (s[i] != t[p]) {
                if (t[p] == ')') {
                    Modify(0, kN, p, kN, 1);
                    sum += 1;
                }
                Modify(0, kN, p, kN, 1);
                sum += 1;
            }
            t[p] = '(';
        }
        if (s[i] == ')') {
            if (s[i] != t[p]) {
                if (t[p] == '(') {
                    Modify(0, kN, p, kN, -1);
                    sum -= 1;
                }
                Modify(0, kN, p, kN, -1);
                sum -= 1;
            }
            t[p] = ')';
        }
        if (s[i] == 'L') {
            if (p > 0) p -= 1;
        }
        if (s[i] == 'R') {
            p += 1;
        }
        if (s[i] >= 'a' && s[i] <= 'z') {
            if (t[p] == '(') Modify(0, kN, p, kN, -1), sum -= 1;
            if (t[p] == ')') Modify(0, kN, p, kN, 1), sum += 1;
            t[p] = s[i];
        }
        if (sum != 0 || QueryMin(0, kN, 0, kN) < 0) printf("-1 ");
        else printf("%d ", QueryMax(0, kN, 0, kN));
    }
}