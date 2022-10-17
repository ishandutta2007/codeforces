#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

struct T {
  int beg, en, blocks, hash;
  T() : beg(0), en(0), blocks(0), hash(0) {};
};

const int MOD = 998244353;
const int N = 2e5 + 10;
const int P = 239017;
const int B = sqrt(N);
int p_pow[N];
inline void add(int &a, int b) {
  a += b;
  if (a >= MOD) {
    a -= MOD;
  }
}

inline int mult(int a, int b) {
  return (a * 1ll * b) % MOD;
}

T add_begin_0(T cur) {
  if (cur.blocks == 0) {
    if (cur.beg == 0) {
      cur.blocks++;
      cur.hash = 1;
    }
    if (cur.beg & 1) {
      cur.beg--;
      cur.en = 1;
      cur.blocks++;
      cur.hash = 1;
    }
    else {
      cur.en = 0;
      cur.blocks++;
      cur.hash = 1;
    }
  }
  else {
    if (cur.beg & 1) {
      cur.beg--;
      cur.hash = mult(cur.hash, P);
      cur.blocks++;
      add(cur.hash, 1);
    }
    else {
      add(cur.hash, 1);
    }
  }
  return cur;
}

T add_begin_1(T cur) {
  if (cur.blocks == 0) {
    cur.beg++;
    cur.en++;
  }
  else {
    cur.beg++;
  }
  return cur;
}

T add_end_0(T cur) {
  if (cur.blocks == 0) {
    cur.en = 0;
    cur.hash = cur.blocks = 1;    
  }
  else {
    if (cur.en == 1) {
      cur.en = 0;
      add(cur.hash, p_pow[cur.blocks++]);
    }
    else {
      add(cur.hash, p_pow[cur.blocks - 1]);
    }
  }
  return cur;
}

T add_end_1(T cur) {
  if (cur.blocks == 0) {
    cur.beg++;
    cur.en++;
  }
  else {
    if (cur.en == 1) {
      cur.en = 0;
      cur.beg += 2;
    }
    else {
      cur.en = 1;
    }
  }
  return cur;
}

inline bool eq(T res1, T res2) {
  if (res1.hash != res2.hash) {
    return false;
  }
  if (res1.blocks != res2.blocks) {
    return false;
  }
  return res1.beg == res2.beg && res1.en == res2.en;
}

T calc[B + 10][B + 10];
int a[N], L[B + 10], R[B + 10];
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  p_pow[0] = 1;
  for (int i = 1; i <= 2e5; i++) {
    p_pow[i] = mult(p_pow[i - 1], P);
  }
	int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[i] = c - '0';
  }
  int mx_block = (n - 1) / B;
  for (int i = 0; i <= mx_block; i++) {
    L[i] = B * i;
    R[i] = min(B * (i + 1), n) - 1;
  }
  for (int i = 0; i <= mx_block; i++) {
    int prv = L[i] - 1;
    for (int j = i; j <= mx_block; j++) {
      if (j > i) {
        calc[i][j] = calc[i][j - 1];
      }
      while (prv < R[j]) {
        prv++;
        if (a[prv] == 0) {
          calc[i][j] = add_end_0(calc[i][j]);
        }
        else {
          calc[i][j] = add_end_1(calc[i][j]);
        }
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int l1, l2, len;
    cin >> l1 >> l2 >> len;
    l1--, l2--;
    int r1 = l1 + len - 1, r2 = l2 + len - 1;
    if (len <= 2 * B) {
      T res1, res2;
      for (int j = l1; j <= r1; j++) {
        if (a[j] == 0) {
          res1 = add_end_0(res1);
        }
        else {
          res1 = add_end_1(res1);
        }
      }
      for (int j = l2; j <= r2; j++) {
        if (a[j] == 0) {
          res2 = add_end_0(res2);
        }
        else {
          res2 = add_end_1(res2);
        }
      }
      if (eq(res1, res2)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
    else {
      int tl1 = l1, tr1 = r1, tl2 = l2, tr2 = r2;
      while (L[tl1 / B] != tl1) {
        tl1++;
      }
      while (R[tr1 / B] != tr1) {
        tr1--;
      }
      while (L[tl2 / B] != tl2) {
        tl2++;
      }
      while (R[tr2 / B] != tr2) {
        tr2--;
      }
      T res1 = calc[tl1 / B][tr1 / B], res2 = calc[tl2 / B][tr2 / B];
      for (int j = tl1 - 1; j >= l1; j--) {
        if (a[j] == 0) {
          res1 = add_begin_0(res1);
        }
        else {
          res1 = add_begin_1(res1);
        } 
      }
      for (int j = tr1 + 1; j <= r1; j++) {
        if (a[j] == 0) {
          res1 = add_end_0(res1);
        }
        else {
          res1 = add_end_1(res1);
        }
      }
      for (int j = tl2 - 1; j >= l2; j--) {
        if (a[j] == 0) {
          res2 = add_begin_0(res2);
        }
        else {
          res2 = add_begin_1(res2);
        } 
      }
      for (int j = tr2 + 1; j <= r2; j++) {
        if (a[j] == 0) {
          res2 = add_end_0(res2);
        }
        else {
          res2 = add_end_1(res2);
        }
      }
      if (eq(res1, res2)) {
        cout << "YES\n";
      }
      else {
        cout << "NO\n";
      }
    }
  }  
}