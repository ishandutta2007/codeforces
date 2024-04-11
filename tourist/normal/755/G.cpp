#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;
const int gen = 3;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

int pw(int a, int b) {
  int x = 1, step = 1 << 30;
  while (step > 0) {
    x = (long long)x * x % md;
    if (step & b) x = (long long)x * a % md;
    step >>= 1;
  }
  return x;
}

void fft(vector <int> &a) {
  int n = a.size();
  for (int i = 0; i < n; i++) {
    int j = 0;
    int x = i, y = n - 1;
    while (y > 0) {
      j = (j << 1) + (x & 1);
      x >>= 1;
      y >>= 1;
    }
    if (i < j) swap(a[i], a[j]);
  }
  for (int len = 1; len < n; len *= 2) {
    int root = pw(gen, (md - 1) / (2 * len));
    for (int i = 0; i < n; i += 2 * len) {
      int w = 1;
      for (int j = 0; j < len; j++) {
        int u = a[i + j];
        int v = (long long)a[i + j + len] * w % md;
        a[i + j] = u + v;
        if (a[i + j] >= md) a[i + j] -= md;
        a[i + j + len] = u - v;
        if (a[i + j + len] < 0) a[i + j + len] += md;
        w = (long long)w * root % md;
      }
    }
  }
}

int nn;

vector <int> multiply(vector <int> a, vector <int> b) {
  a.resize(2 * nn);
  b.resize(2 * nn);
  fft(a);
  fft(b);
  for (int i = 0; i < 2 * nn; i++) a[i] = (long long)a[i] * b[i] % md;
  reverse(++a.begin(), a.end());
  fft(a);
  int inv = pw(2 * nn, md - 2);
  for (int i = 0; i < 2 * nn; i++) a[i] = (long long)a[i] * inv % md;
  a.resize(nn);
  return a;
}

pair < vector <int>, vector <int> > get(int n) {
  // <v_n, v_{n+1}>
  if (n == 1) {
    vector <int> a(nn, 0);
    vector <int> b(nn, 0);
    a[0] = 1;
    b[0] = 1; b[1] = 1;
    return make_pair(a, b);
  }
  if (n == 2) {
    vector <int> a(nn, 0);
    vector <int> b(nn, 0);
    a[0] = 1; a[1] = 1;
    b[0] = 1; b[1] = 3; b[2] = 1;
    return make_pair(a, b);
  }
  if (n % 2 == 1) {
    pair < vector <int>, vector <int> > p = get(n - 1);
    vector <int> a = p.first;
    vector <int> b = p.second;
    vector <int> c(nn, 0);
    for (int i = 0; i < nn; i++) {
      add(c[i], b[i]);
      if (i > 0) {
        add(c[i], b[i - 1]);
        add(c[i], a[i - 1]);
      }
    }
    return make_pair(b, c);
  }
  pair < vector <int>, vector <int> > p = get(n / 2);
  vector <int> a = p.first;
  vector <int> b = p.second;
  vector <int> a2 = multiply(a, a);
  vector <int> b2 = multiply(b, b);
  vector <int> my_b(nn, 0);
  for (int i = 0; i < nn; i++) {
    add(my_b[i], b2[i]);
    if (i > 0) {
      add(my_b[i], a2[i - 1]);
    }
  }
  vector <int> z(nn, 0);
  for (int i = 0; i < nn; i++) {
    add(z[i], md - a[i]);
    if (i + 1 < nn) {
      add(z[i], b[i + 1]);
      add(z[i], md - a[i + 1]);
    }
  }
  vector <int> z2 = multiply(z, z);
  vector <int> my_z(nn, 0);
  for (int i = 0; i < nn; i++) {
    add(my_z[i], a2[i]);
    if (i > 0) {
      add(my_z[i], z2[i - 1]);
    }
  }
  vector <int> aux(nn, 0);
  for (int i = 0; i < nn; i++) {
    add(aux[i], my_b[i]);
    if (i > 0) {
      add(aux[i], md - my_z[i - 1]);
    }
  }
  vector <int> my_a(nn, 0);
  my_a[0] = aux[0];
  for (int i = 1; i < nn; i++) {
    my_a[i] = aux[i];
    add(my_a[i], md - my_a[i - 1]);
  }
  return make_pair(my_a, my_b);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  nn = 4;
  while (nn <= k) {
    nn *= 2;
  }
  vector <int> a = get(n + 1).first;
  for (int i = 1; i <= k; i++) {
    if (i > 1) putchar(' ');
    printf("%d", i < nn ? a[i] : 0);
  }
  printf("\n");
  return 0;
}