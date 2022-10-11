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

int n, m, k, s;

pii q[100000 * 100];
int dist[100][100000];
int v[100000];
int seen[100000];
int ret[100000];

vector<int> edges[100000];

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  for(int i = 0; i < k; i++) {
    for(int j = 0; j < n; j++) {
      dist[i][j] = 1 << 25;
    }
  }
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
    v[i]--;
  }
  while(m-- > 0) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  int ql = 0;
  int qr = 0;
  for(int i = 0; i < n; i++) {
    q[qr++] = pii(v[i], i);
    dist[v[i]][i] = 0;
  }
  while(ql < qr) {
    pii curr = q[ql++];
    if(++seen[curr.second] <= s) {
      ret[curr.second] += dist[curr.first][curr.second];
    }
    else {
      continue;
    }
    for(int out: edges[curr.second]) {
      if(dist[curr.first][out] > dist[curr.first][curr.second] + 1) {
        dist[curr.first][out] = dist[curr.first][curr.second] + 1;
        q[qr++] = pii(curr.first, out);
      }
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%d", ret[i]);
    if(i == n-1) printf("\n");
    else printf(" ");
  }
  return 0;
}