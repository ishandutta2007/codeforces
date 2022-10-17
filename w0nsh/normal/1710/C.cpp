#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto & i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define PR std::pair
#define MP std::make_pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;


constexpr int MOD = 998244353;

constexpr int STATES = 3;
void add(int& a, int b){
  a = (a + b >= MOD ? a + b - MOD : a + b);
}

int dp[1<<3][4][STATES];
int next[1<<3][4][STATES];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  std::string s;
  std::cin >> s;
  int n = SZ(s);

  auto bb = [&](int a, int b, int c){
    if(a == 0) return 0;
    if(b == 0) return 1;
    return 2;
    // if(c == 0) return 2;
    // assert(false);
  };

  auto bez = [&](int a, int b){
    if(a != 0 && b != 0) return 0;
    if(a != 1 && b != 1) return 1;
    return 2;
  };

  dp[0][0][0] = 1;
  FOR(i, n){
    FOR(mask, 1<<3) FOR(l, 4) FOR(state, STATES){
      int curval = dp[mask][l][state];
      int nextmask = 0;
      FOR(a, 2){
        nextmask = (nextmask | 1) ^ 1;
        if(mask & 1) nextmask |= 1;
        else if(s[i] == '0' && a == 1) continue;
        else if(s[i] == '1' && a == 0) nextmask |= 1;
        FOR(b, 2){
          nextmask = (nextmask | 2) ^ 2;
          if(mask & 2) nextmask |= 2;
          else if(s[i] == '0' && b == 1) continue;
          else if(s[i] == '1' && b == 0) nextmask |= 2;
          FOR(c, 2){
          nextmask = (nextmask | 4) ^ 4;
            if(mask & 4) nextmask |= 4;
            else if(s[i] == '0' && c == 1) continue;
            else if(s[i] == '1' && c == 0) nextmask |= 4;

            int fs = a^b;
            int sc = a^c;
            int th = b^c;
            if(fs == sc && sc == th){
              // assert(fs == 0);
              add(next[nextmask][l][state], curval);
            }else{
              if(l == 0){
                add(next[nextmask][1][bb(fs, sc, th)], curval);
              }else if(l == 1){
                int nbb = bb(fs, sc, th);
                if(nbb == state) add(next[nextmask][1][state], curval);
                else add(next[nextmask][2][bez(nbb, state)], curval);
              }else if(l == 2){
                int nbb = bb(fs, sc, th);
                if(nbb == state) add(next[nextmask][3][0], curval);
                else add(next[nextmask][2][state], curval);
              }else{ // l == 3
                add(next[nextmask][3][state], curval);
              }
            }
          }
        }
      }
    }

    FOR(j, 1<<3) FOR(l, 4) FOR(xd, STATES) dp[j][l][xd] = next[j][l][xd], next[j][l][xd] = 0;
  }

  int ans = 0;
  FOR(j, 1<<3) add(ans, dp[j][3][0]);
  std::cout << ans << "\n";

  return 0;
}