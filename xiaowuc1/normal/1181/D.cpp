#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> query;
typedef vector<vector<ll>> matrix;

const int BIT_SZ = 500005;
int bit[BIT_SZ];
void upd(int idx) {
  idx+=2;
  while(idx < BIT_SZ) {
    bit[idx]++;
    idx += idx & -idx;
  }
}
int qry(int idx) {
  idx+=2;
  int ret = 0;
  while(idx) {
    ret += bit[idx];
    idx -= idx & -idx;
  }
  return ret;
}

int m, n; // cities are range [1, n]
int ret[500005];
int currTime = 0; // increase all with freq <= currTime
ll lhs = 0; // last one we incremented
ll currDay;
map<int, vector<int>> revMap;

bool advanceToEnd(ll goalDay) {
  // return true if currTime++
  // return false otherwise, and lhs is the answer
  int lhsQuery = qry(lhs);
  int inc = qry(n) - lhsQuery;
  if(currDay + inc < goalDay) {
    currDay += inc;
    if(revMap.count(++currTime)) {
      for(int out: revMap[currTime]) {
        upd(out);
      }
    }
    lhs = 0;
    return true;
  }
  int aa = lhs+1;
  int bb = n;
  while(aa != bb) {
    int mid = (aa+bb)/2;
    if(currDay + qry(mid) - lhsQuery < goalDay) {
      aa = mid+1;
    }
    else {
      bb = mid;
    }
  }
  lhs = aa;
  currDay = goalDay;
  return false;
}

void solve(vector<query>& queries, vector<int> freq) {
  for(int i = 1; i <= n; i++) {
    if(freq[i]) revMap[freq[i]].push_back(i);
  }
  vector<int> events;
  for(int i = 1; i <= n; i++) {
    if(freq[i]) events.push_back(freq[i]);
  }
  sort(events.begin(), events.end());
  reverse(events.begin(), events.end());
  for(query q: queries) {
    bool done = false;
    ll goalDay = q.first;
    if(currDay == goalDay) {
      ret[q.second] = lhs;
      continue;
    }
    while(qry(n) != n) {
      if(!advanceToEnd(goalDay)) {
        done = true;
        assert(currDay == goalDay);
        ret[q.second] = lhs;
        break;
      }
    }
    if(!done) {
      assert(qry(n) == n);
      ll id = goalDay - currDay + lhs;
      id %= n;
      if(id == 0) id = n;
      ret[q.second] = id;
      lhs = id;
      currDay = goalDay;
    }
  }
}

void solve() {
  int q;
  cin >> m >> n >> q;
  vector<int> freq;
  freq.resize(n+1);
  for(int i = 0; i < m; i++) {
    int t;
    cin >> t;
    freq[t]++;
  }
  for(int i = 1; i <= n; i++) {
    if(freq[i] == 0) upd(i);
  }
  vector<query> queries;
  queries.resize(q);
  for(int i = 0; i < q; i++) {
    cin >> queries[i].first;
    queries[i].second = i;
  }
  sort(queries.begin(), queries.end());
  currDay = m;
  solve(queries, freq);
  for(int i = 0; i < q; i++) cout << ret[i] << "\n";
}

void casesolve() {
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}