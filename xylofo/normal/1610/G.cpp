#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
//#define debug(v) cerr << "[ " << #v << " = " << v << " ]"  << endl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef uint64_t ull;
static int C = rng()%(int(1e8))+int(1e8); // initialized below

// Arithmetic mod two primes and 2^32 simultaneously.
// "typedef uint64_t H;" instead if Thue-Morse does not apply.
template<int M, class B>
struct A {
  int x; B b; A(int x=0) : x(x), b(x) {}
  A(int x, B b) : x(x), b(b) {}
  A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
  A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
  A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
  explicit operator ull() { return x ^ (ull) b << 21; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  string s;
  cin>>s;
  int n = sz(s);
  vi match(n,-1);
  vi st;
  for(int i = n; i--;) {
    if(s[i] == '(') {
      if(sz(st)) {
        match[i] = st.back()+1;
        st.pop_back();
      }
    }
    else if(s[i] == ')') {
      st.emplace_back(i);
    }
    else assert(false);
  }

  int LG = 32;
  vector<vi> jmp(n+1,vi(LG,-1));
  vector<vector<H>> hsh(n+1, vector<H>(LG,0));
  H hlow = '(';
  vector<H> pwC(n+100,1);
  rep(i,1,sz(pwC)) pwC[i] = pwC[i-1]*C;

  vi par(n+1,-1);
  vi par_char(n+1,'e');

  for(int i = n; i--;) {
    par[i] = i+1;
    par_char[i] = s[i];
    jmp[i][0] = par[i];
    hsh[i][0] = par_char[i];
    rep(k,0,LG) {
      int x = jmp[i][k];
      if(x == -1) break;
      jmp[i][k+1] = jmp[x][k];
      hsh[i][k+1] = hsh[i][k] + pwC[(1<<k)] * hsh[x][k];
    }
    if(match[i] != -1) {
      int x = i, y = match[i];
      for(int k = LG; k--;) {
        if(jmp[x][k] == -1 || jmp[y][k] == -1) continue;
        if(ull(hsh[x][k]) == ull(hsh[y][k])) x = jmp[x][k], y = jmp[y][k];
      }
      if(jmp[y][0] == -1 || (jmp[x][0] != -1 && ull(hsh[y][0]) == ull(hlow))) { // y <= x
        par[i] = match[i];
        par_char[i] = 'e';
      }
    }

    if(par_char[i] == 'e') {
      jmp[i] = jmp[par[i]];
      hsh[i] = hsh[par[i]];
    }
  }


  int x = 0;
  while(x != n) {
    if(par_char[x] != 'e') cout << char(par_char[x]);
    x = par[x];
  }
  cout << endl;
}