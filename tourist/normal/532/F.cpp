#include <bits/stdc++.h>

int const N = 234567;
int const X = 33533;
long long M1;
long long M2;  // TODO TODO CHANGE
long long const MASK = (1LL << 32) - 1;

long long POW1[N], POW2[N];

long long add1(long long h1, int c) {
  return (h1 * X + c) % M1;
}

long long add2(long long h1, int c) {
  return (h1 * X + c) % M2;
}

long long add(long long const & a, int c) {
  return (add1(a >> 32, c) << 32) | add2(a & MASK, c);
}

long long rem1(long long h1, int len) {
    h1 -= POW1[len];
    if (h1 < 0) h1 += M1;
    return h1;
}

long long rem2(long long h2, int len) {
    h2 -= POW2[len];
    if (h2 < 0) h2 += M2;
    return h2;
}

long long rem(long long const & a, int len) {
  return (rem1(a >> 32, len) << 32) | rem2(a & MASK, len);
}

int n;

std::mt19937 rnd(std::chrono::system_clock::now().time_since_epoch().count());
  
int const HALFBILLION = 500000000;

bool prime(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return false;
  }
  return true;
}

void gen(long long & M) {
  M = rnd() % HALFBILLION + HALFBILLION;
  while (!prime(M)) {
    ++M;
  }
}

int s[N], t[N], ans[N];

long long tmp[42], h[42], sh[42];
int id1[42], id2[42], mp[42];

void read(int & n, int * s) {
    int c = getchar();
    while (c <= 32) c = getchar();
    n = 0;
    while (c > 32) {
        s[n++] = c - 'a';
        c = getchar();
    }
}

bool check() {
    std::sort(id2, id2 + 26, [](int i, int j) { return sh[i] < sh[j]; });
    for (int i = 0; i < 26; i++) mp[i] = -1;
    for (int it = 0; it < 26; it++) {
        int i = id1[it];
        int j = id2[it];
        if (h[i] != sh[j]) return false;
        if (h[i] == 0 && sh[j] == 0) continue;
        if (mp[i] >= 0 && mp[i] != j) return false;
        if (mp[j] >= 0 && mp[j] != i) return false;
        mp[i] = j;
        mp[j] = i;
    } 
    return true;
}

int main() {
    gen(M1);
    gen(M2);
    POW1[0] = POW2[0] = 1;
    for (int i = 1; i < N; i++) {
      POW1[i] = POW1[i - 1] * X % M1;
      POW2[i] = POW2[i - 1] * X % M2;
    }
    int n, m;
    scanf("%d%d", &n, &m);
    read(n, s);
    read(m, t);
    for (int i = 0; i < 26; i++) {
        h[i] = 0;
        for (int j = 0; j < m; j++) {
            h[i] = add(h[i], t[j] == i);
        }
    }
    for (int i = 0; i < 26; i++) id1[i] = id2[i] = i;
    std::sort(id1, id1 + 26, [](int i, int j) { return h[i] < h[j]; });
    for (int i = 0; i < 26; i++) sh[i] = 0;
    for (int i = 0; i < n && i < m; i++) {
        for (int j = 0; j < 26; j++) sh[j] = add(sh[j], s[i] == j);
    }
    int ac = 0;
    if (check()) {
        ans[ac++] = 0;
    }
    long long xor1 = 0;
    for (int i = 0; i < 26; i++) xor1 ^= h[i];
    for (int i = m; i < n; i++) {
        long long xor2 = 0;
        int torem = s[i - m];
        for (int j = 0; j < 26; j++) {
            sh[j] = add(sh[j], s[i] == j);
            if (j != torem) xor2 ^= sh[j];
        }
        sh[torem] = rem(sh[torem], m);
        xor2 ^= sh[torem];
        if (xor1 == xor2 && check()) {
            ans[ac++] = i - m + 1;
        }
    }
    printf("%d\n", ac);
    for (int i = 0; i < ac; i++) {
        if (i > 0) putchar(' ');
        printf("%d", ans[i] + 1);
    }
    puts("");
}