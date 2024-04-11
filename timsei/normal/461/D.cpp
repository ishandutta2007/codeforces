#include <bits/stdc++.h>
using namespace std;
 
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
 
namespace {
  int add(int x) {return (x >= mod) ? x - mod : x;}
  int sub(int x) {return (x < 0) ? x + mod : x;}
  void Add(int &x, int y) {x = add(x + y);}
  void Sub(int &x, int y) {x = sub(x - y);}
  int Pow(int x, int y = mod - 2) {
    int res = 1;
    for(; y; y >>= 1, x = 1LL * x * x % mod) {
      if(y & 1)
    res = 1LL * res * x % mod;
    }
    return res;
  }
}
 
int n, m, x, y, fa[N + 5], Tr[N + 5];
char c[N];
 
int getf(int x) {
  if(fa[x] == x) return x;
  int now = getf(fa[x]);
  Tr[x] ^= Tr[fa[x]];
  return fa[x] = now;
}
 
int merge(int L, int R, int who) {
  //for(int i = 1; i <= n + 2; ++ i)
  //cerr << i <<" " << fa[i] <<" " << Tr[i] << endl;
  int l = getf(L), r = getf(R);
  if(l == r) {
    //cerr << Tr[L] <<" " << Tr[R] << " " << who << endl;
    if((Tr[L] ^ Tr[R]) != who) {
      puts("0");
      exit(0);
    }
    else return 0;
  }
  Tr[l] = (Tr[R] ^ who ^ Tr[L]);
  fa[l] = r;
  return 1;
}
 
int main() {
  cin >> n >> m;
  int tot = n;
  for(int i = 1; i < N; ++ i) fa[i] = i, Tr[i] = 0;
  for(int i = 1; i <= m; ++ i) {
    scanf("%d%d%s", &x, &y, c);
    int who = 0;
    if(c[0] == 'o') who = 1;
    if(x + y > n + 1) {
      x = n - x + 1,
      y = n - y + 1;
    }
    if(x > y) swap(x, y);
    int L = y - (x - 1), R = y + (x - 1);
    int Min = L & 1; if(Min == 0) Min = 2;
    int Max = n; if((Max & 1) != (R & 1)) -- Max;
    L = max(L, Min); R = min(R, Max);
    R += 2;
    //cerr << x <<" " << y <<" " << who << " " << L <<' ' << R << endl;
    tot -= merge(L, R, who);
  }
  //cerr << ((-1) & 1) << endl;
  cout << Pow(2, tot) << endl;
}