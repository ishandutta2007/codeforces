#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

ll lhs[300005];
ll rhs[300005];

vector<int> edges[300005];
ll ret[300005];

int n;
int m;

void init() {
  // (penalty, index)
  vector<pii> v;
  ll totalLHS = 0;
  ll totalRHS = 0;
  int totalLeft = n;
  for(int i = 0; i < n; i++) {
    int pen = abs(lhs[i] - rhs[i]);
    v.push_back({pen, i});
    totalLHS += lhs[i];
    totalRHS += rhs[i];
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  ll lhsContrib = 0;
  int lhsTerm = 0;
  ll rhsContrib = 0;
  int rhsTerm = 0;
  for(auto out: v) {
    int currP = out.first;
    int currIdx = out.second;
    totalLHS -= lhs[currIdx];
    totalRHS -= rhs[currIdx];
    totalLeft--;
    if(lhs[currIdx] < rhs[currIdx]) {
      ret[currIdx] += totalLeft * lhs[currIdx] + totalRHS;
      // we need to pick rhs for the lhs contributions
      ret[currIdx] += lhsContrib + lhsTerm * rhs[currIdx];
      // we get to pick lhs irrespective of the rhs
      ret[currIdx] += rhsContrib + rhsTerm * lhs[currIdx];
      // contribute!
      lhsContrib += lhs[currIdx];
      lhsTerm++;
    }
    else {
      ret[currIdx] += totalLeft * rhs[currIdx] + totalLHS;
      // we need to pick lhs for the rhs contributions
      ret[currIdx] += rhsContrib + rhsTerm * lhs[currIdx];
      // we get to pick rhs irrespective of the lhs
      ret[currIdx] += lhsContrib + lhsTerm * rhs[currIdx];
      // contribute!
      rhsContrib += rhs[currIdx];
      rhsTerm++;
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++) {
    scanf("%lld%lld", &lhs[i], &rhs[i]);
  }
  while(m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--;
    b--;
    if(a < b) edges[a].push_back(b);
    else edges[b].push_back(a);
  }
  init();
  for(int i = 0; i < n; i++) {
    for(int out: edges[i]) {
      ll score = min(lhs[i] + rhs[out], lhs[out] + rhs[i]);
      ret[i] -= score;
      ret[out] -= score;
    }
  }
  for(int i = 0; i < n; i++) {
    printf("%lld ", ret[i]);
  }
  printf("\n");
}