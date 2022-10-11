#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);
*/
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppiipii;
typedef pair<int, ppiipii> pippiipii;
typedef pair<int, pii> pipii;
typedef pair<pii, int> ppiii;
typedef pair<int, ppiii> pippiii;
typedef pair<int, ll> pill;
typedef pair<int, double> pid;
// note to self, the below two triggers someone
typedef pair<ll, ll> pll;
typedef pair<ll, int> plli;
typedef long double ld;

int g[4][50];
int r, c;

vector<pipii> ret;

int main() {
  r = 4;
  scanf("%d", &c);
  int k;
  scanf("%d", &k);
  int left = k;
  for(int i = 0; i < r; i++) {
    for(int j = 0; j < c; j++) {
      scanf("%d", &g[i][j]);
    }
  }
  for(int j = 0; j < c; j++) {
    if(g[0][j] && g[0][j] == g[1][j]) {
      ret.push_back(pipii(g[1][j], pii(1, j+1)));
      g[1][j] = 0;
      left--;
    }
    if(g[2][j] && g[2][j] == g[3][j]) {
      ret.push_back(pipii(g[2][j], pii(4, j+1)));
      g[2][j] = 0;
      left--;
    }
  }
  if(left == 2*c) {
    printf("-1\n");
    return 0;
  }
  while(left) {
    for(int i = 2; i <= 2; i++) {
      for(int j = 0; j < c; j++) {
        if(g[i][j] == 0) {
          int pi, pj;
          if(i == 1 && j == 0) {
            pi = 2;
            pj = 0;
          }
          else if(i == 2 && j == c-1) {
            pi = 1;
            pj = c-1;
          }
          else if(i == 1) {
            pi = 1;
            pj = j-1;
          }
          else {
            pi = 2;
            pj = j+1;
          }
          if(g[pi][pj]) {
            g[i][j] = g[pi][pj];
            g[pi][pj] = 0;
            ret.push_back(pipii(g[i][j], pii(i+1, j+1)));
            if(g[i][j] == g[i+1][j]) {
              ret.push_back(pipii(g[i][j], pii(4, j+1)));
              g[i][j] = 0;
              left--;
            }
          }
        }
      }
    }
    for(int i = 1; i <= 1; i++) {
      for(int j = c-1; j >= 0; j--) {
        if(g[i][j] == 0) {
          int pi, pj;
          if(i == 1 && j == 0) {
            pi = 2;
            pj = 0;
          }
          else if(i == 2 && j == c-1) {
            pi = 1;
            pj = c-1;
          }
          else if(i == 1) {
            pi = 1;
            pj = j-1;
          }
          else {
            pi = 2;
            pj = j+1;
          }
          if(g[pi][pj]) {
            g[i][j] = g[pi][pj];
            g[pi][pj] = 0;
            ret.push_back(pipii(g[i][j], pii(i+1, j+1)));
            if(g[i][j] == g[i-1][j]) {
              ret.push_back(pipii(g[i][j], pii(1, j+1)));
              g[i][j] = 0;
              left--;
            }
          }
        }
      }
    }
  }
  printf("%d\n", ret.size());
  for(pipii out: ret) {
    printf("%d %d %d\n", out.first, out.second.first, out.second.second);
  }
}