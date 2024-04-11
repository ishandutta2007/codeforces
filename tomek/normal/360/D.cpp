//{{{
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <ctime>
#include <queue>
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define REP(i,n) for(int _n=n, i=0;i<_n;++i)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;++i)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define TRACE(x) cerr << "TRACE(" #x ")" << endl;
#define DEBUG(x) cerr << #x << " = " << (x) << endl;

typedef long long LL;
typedef unsigned long long ULL;
const int INF = 1000000000; const LL INFLL = LL(INF) * LL(INF);
template<class T> inline int size(const T&c) { return c.size(); }
int rint() { int x; if(scanf("%d",&x)!=1) return -1; return x; }
string rstring() { static char buf[100000]; if(scanf("%s",buf)!=1) return ""; return buf; }
//}}}

int P;
vector<int> A;
vector<int> divisors;
vector<int> primes;
vector<char> ok;

int gcd(int a,int b) {
  return b==0 ? a : gcd(b, a%b);
}

inline int mul(int a,int b) { return LL(a)*LL(b)%P; }

int mypower(int a,int b) {
  if(b==0) return 1;
  int res = mypower(mul(a,a), b/2);
  if(b%2) res = mul(res, a);
  return res;
}

void ReadInput() {
  int n = rint(), m = rint();
  P = rint();
  REP(i,n) A.push_back(rint());
  int B = P-1;
  REP(i,m) B = gcd(B, rint());
  REP(i,n) A[i] = mypower(A[i], B);
}

void CalcPrimes() {
  int n = P-1;
  for(int p=2;p*p<=n;++p) {
    if(n%p==0) {
      primes.push_back(p);
      while(n%p==0) n/=p;
    }
  }
  if(n>1) primes.push_back(n);
}

void CalcDivisors() {
  int n = P-1;
  for(int i=1;i*i<=n;++i) {
    if(n%i==0) {
      divisors.push_back(i);
      if(i*i<n) divisors.push_back(n/i);
    }
  }
  sort(divisors.begin(), divisors.end());
}

int GetExponent(int a) {
  int e = 1;
  for(int p : primes) {
    while((P-1)/e % p==0 && mypower(a, (P-1)/(e*p))==1) e*=p;
  }
  return e;
}

int Index(int d) {
  auto it = lower_bound(divisors.begin(), divisors.end(), d);
  assert(*it==d);
  return it - divisors.begin();
}

int Phi(int n) {
  int res = n;
  for(int p : primes) if(n%p==0) {
    res = res/p * (p-1);
  }
  return res;
}

void CalcOK() {
  int n = size(divisors);
  ok.assign(n,0);
  for(int a : A) ok[Index(GetExponent(a))] = 1;
  REP(i,n) {
    int d = divisors[i];
    for(int p: primes) if(d%p==0) {
      ok[i] = ok[i] || ok[Index(d/p)];
    }
  }
}

int Count() {
  int n = size(divisors);
  int res = 0;
  REP(i,n) if(ok[i]) {
    res += Phi((P-1)/divisors[i]);
  }
  return res;
}

int main() {
  ReadInput();
  CalcPrimes();
  CalcDivisors();
  CalcOK();
  int res = Count();
  printf("%d\n", res);
}