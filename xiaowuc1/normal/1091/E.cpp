#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

ll pref[500005];
int numDegLE[500005];

int constraintDP[500005];

void solve() {
  int n;
  cin >> n;
  vector<int> d;
  d.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> d[i];
    numDegLE[d[i]]++;
  }
  for(int i = 1; i <= n; i++) {
    numDegLE[i] += numDegLE[i-1];
  }
  sort(d.begin(), d.end());
  reverse(d.begin(), d.end());
  for(int i = 0; i < n; i++) {
    pref[i+1] = pref[i] + d[i];
  }
  set<int> ret;
  ll prefNow = 0;
  int lhs = 0;
  int constraints = 0;
  for(int degconstraint = n; degconstraint >= 0; degconstraint--) {
    if(degconstraint%2 != pref[n]%2) continue;
    // add constraint
    // printf("consider constraint %d\n", degconstraint);
    constraints++;
    // d_1 >= ... >= d_k
    // sum of d_1 through d_k <= k(k-1) + ,for i>k, min(d_i, k)
    // must check
    while(lhs < d.size() && d[lhs] >= degconstraint) {
      prefNow += d[lhs++];
    }
    // after this point, lhs is equal to one-indexed element not considered, so k
    ll lhsSum = prefNow;
    ll rhsSum = lhs*(lhs-1LL);
    // consider d[lhs] through d[n-1]
    {
      // how many are not min-capped?
      int numnotmincap = numDegLE[lhs+1];
      // cannot use more than lhs
      numnotmincap = min(numnotmincap, n - lhs);
      rhsSum += pref[n] - pref[n-numnotmincap];
      // capped are all remainder
      int capped = n - lhs - numnotmincap;
      rhsSum += capped * (ll)(lhs+1);
    }
    // if we insert >= degconstraint, what values are valid?
    // recall that we add one vertex to lhs, so k*(k+1)
    // lhssum + inc <= rhssum
    // printf("orig sums %d %lld %lld\n", lhs, lhsSum, rhsSum);
    // printf("augment sums %d %lld %lld\n", lhs, lhsSum, rhsSum + 2*lhs);
    ll maxInc = min((ll)n, rhsSum + 2*lhs - lhsSum);
    if(maxInc >= degconstraint) {
      // printf("add a %d %d\n", degconstraint, (int)maxInc);
      constraintDP[degconstraint]++;
      // exclude after maxInc
      constraintDP[maxInc+1]--;
    }
    rhsSum = lhs*(lhs-1LL);
    {
      // how many are not min-capped?
      int numnotmincap = numDegLE[lhs];
      // cannot use more than lhs
      numnotmincap = min(numnotmincap, n - lhs);
      rhsSum += pref[n] - pref[n-numnotmincap];
      // capped are all remainder
      int capped = n - lhs - numnotmincap;
      rhsSum += capped * (ll)(lhs);
    }
    // if we insert < degconstraint, what values are valid?
    // lhssum <= rhssum + inc
    // case a: [0, k]
    ll minInc = max(0LL, lhsSum - rhsSum);
    if(minInc <= min(degconstraint-1, lhs)) {
      // printf("add b %d %d\n", (int)minInc, min(degconstraint-1, lhs));
      constraintDP[minInc]++;
      constraintDP[min(degconstraint-1, lhs)+1]--;
    }
    // case b: [k+1, degconstraint-1]
    if(lhs+1 <= degconstraint-1 && lhsSum <= rhsSum + lhs) {
      // printf("add c %d %d\n", lhs+1, degconstraint-1);
      constraintDP[lhs+1]++;
      constraintDP[degconstraint]--;
    }
  }
  for(int i = 1; i <= n; i++) {
    constraintDP[i] += constraintDP[i-1];
  }
  for(int i = 0; i <= n; i++) {
    // printf("%d: %d %d\n", i, constraintDP[i], constraints);
    if(constraintDP[i] == constraints && i%2 == pref[n]%2) {
      ret.insert(i);
    }
  }
  if(ret.empty()) ret.insert(-1);
  for(int out: ret) cout << out << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}