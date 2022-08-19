#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline void add(int &a, int b, int md = MOD) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b, int md = MOD) {
  return (long long) a * b % md;
}

inline int power(int a, int b, int md = MOD) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a, md);
    }
    a = mul(a, a, md);
    b >>= 1;
  }
  return res;
}

inline int inv(int x) {
  return power(x, MOD - 2);
}

struct node {
  int value;
  int len;
};

node seq(int n7, int n6, int k) {
  int p10k = power(10, k);
  int t = mul(p10k, 10);
  int e = n6 - power(10, k, MOD - 1) + 1;
  if (e < 0) {
    e += MOD - 1;
  }
  int it1 = inv(t - 1);
  int sum = mul(power(t, e) + MOD - 1, it1);
  int z = mul(p10k, sum);
  int res = z;
  int cnt = n7 - p10k + 1;
  if (cnt < 0) {
    cnt += MOD;
  }
  add(res, mul(sum - cnt + MOD, it1));
  return {res, mul(e, k + 1, MOD - 1)};
}

node concat(node a, node b) {
  int value = mul(a.value, power(10, b.len));
  add(value, b.value);
  return {value, (a.len + b.len) % (MOD - 1)};
}

node multi(node a, int b) {
  if (b == 1) {
    return a;
  }
  if (b % 2 == 1) {
    return concat(multi(a, b - 1), a);
  }
  node z = multi(a, b / 2);
  return concat(z, z);
}

const int N = 100010;

node prec[N];

node big_seq(int n7, int n6, int k) {
  node res = seq(n7, n6, k - 1);
  for (int i = k - 2; i >= 0; i--) {
    res = concat(prec[i], res);
  }
  return res;
}

char s[N];
int pos;

node solve_exp() {
  int start = pos;
  int v7 = 0;
  int v6 = 0;
  while ('0' <= s[pos] && s[pos] <= '9') {
    v7 = mul(v7, 10);
    add(v7, s[pos] - '0');
    v6 = mul(v6, 10, MOD - 1);
    add(v6, s[pos] - '0', MOD - 1);
    pos++;
  }
  int len_v = pos - start;
  if (s[pos] == '+') {
    pos++;
    return concat({v7, len_v}, solve_exp());
  }
  if (s[pos] == '-') {
    pos++;
    int start2 = pos;
    int w7 = 0;
    int w6 = 0;
    while ('0' <= s[pos] && s[pos] <= '9') {
      w7 = mul(w7, 10);
      add(w7, s[pos] - '0');
      w6 = mul(w6, 10, MOD - 1);
      add(w6, s[pos] - '0', MOD - 1);
      pos++;
    }
    int len_w = pos - start2;
    add(v7, MOD - 1);
    add(v6, (MOD - 1) - 1, MOD - 1);
    node v = big_seq(v7, v6, len_v);
    node w = big_seq(w7, w6, len_w);
    int diff = w.len - v.len;
    if (diff < 0) {
      diff += MOD - 1;
    }
    int real_value = w.value;
    add(real_value, MOD - mul(v.value, power(10, diff)));
    int real_len = w.len;
    add(real_len, (MOD - 1) - v.len, MOD - 1);
    if (s[pos] == '+') {
      pos++;
      return concat({real_value, real_len}, solve_exp());
    }
    return {real_value, real_len};
  }
  if (s[pos] == '(') {
    int finish = pos;
    pos++;
    node z = solve_exp();
    node res = {0, 0};
    for (int i = start; i < finish; i++) {
      res = multi(res, 10);
      if (s[i] != '0') {
        res = concat(res, multi(z, s[i] - '0'));
      }
    }
    pos++;
    if (s[pos] == '+') {
      pos++;
      return concat(res, solve_exp());
    }
    return res;
  }
  return {v7, len_v};
}

int main() {
/*  int real = 0;
  for (int i = 1; i <= 12345; i++) {
    real = mul(real, i <= 9 ? 10 : (i <= 99 ? 100 : (i <= 999 ? 1000 : (i <= 9999 ? 10000 : 100000))));
    add(real, i);
  }
  printf("%d\n", real);*/
  int v7 = 0;
  int v6 = 0;
  for (int k = 0; k < N; k++) {
    v7 = mul(v7, 10);
    add(v7, 9);
    v6 = mul(v6, 10, MOD - 1);
    add(v6, 9, MOD - 1);
    prec[k] = seq(v7, v6, k);
  }
  scanf("%s", s);
  pos = 0;
  node res = solve_exp();
  printf("%d\n", res.value);
  return 0;
}