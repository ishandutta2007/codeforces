#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int RAGETREESZ = 100050;
ll ragetreemin[4 * RAGETREESZ];
ll ragetreelazy[4 * RAGETREESZ];

void pushdown(int idx, int l, int r) {
  if(ragetreelazy[idx]) {
    ragetreelazy[2*idx] += ragetreelazy[idx];
    ragetreelazy[2*idx+1] += ragetreelazy[idx];
    ragetreelazy[idx] = 0;
  }
}
void pullup(int idx, int l, int r) {
  ragetreemin[idx] = min(
    ragetreemin[2*idx] + ragetreelazy[2*idx],
    ragetreemin[2*idx+1] + ragetreelazy[2*idx+1]
  );
}

void ragetreeinc(int idx, int l, int r, int lhs, int rhs, ll val) {
  if(l >= lhs && r <= rhs) {
    ragetreelazy[idx] += val;
    return;
  }
  pushdown(idx, l, r);
  int m = (l+r)/2;
  if(m >= lhs) ragetreeinc(2*idx, l, m, lhs, rhs, val);
  if(m+1 <= rhs) ragetreeinc(2*idx+1, m+1, r, lhs, rhs, val);
  pullup(idx, l, r);
}
void ragetreeinc(int lhs, int rhs, ll val) {
  ragetreeinc(1, 0, RAGETREESZ-1, lhs, rhs, val);
}
ll ragetreequery(int idx, int l, int r, int lhs, int rhs) {
  if(l >= lhs && r <= rhs) return ragetreemin[idx] + ragetreelazy[idx];
  pushdown(idx, l, r);
  ll ans = 1LL << 60;
  int m = (l+r)/2;
  if(m >= lhs) ans = min(ans, ragetreequery(2*idx, l, m, lhs, rhs));
  if(m+1 <= rhs) ans = min(ans, ragetreequery(2*idx+1, m+1, r, lhs, rhs));
  pullup(idx, l, r);
  return ans;
}
ll ragetreequery(int lhs, int rhs) {
  return ragetreequery(1, 0, RAGETREESZ-1, lhs, rhs);
}

int rval[100005];
bool piisort(pii a, pii b) {
  // <weight penalty, idx>
  if(a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}

int lval[100005];
bool exact[100005];
void solve() {
  int n, inc;
  cin >> n >> inc;
  ragetreeinc(0, n, inc);
  for(int i = 1; i <= n; i++) {
    cin >> lval[i];
  }
  for(int i = 1; i <= n; i++) {
    cin >> rval[i];
  }
  ll ret = 0;
  vector<pii> all;
  for(int i = 1; i <= n; i++) {
    if(lval[i] % 100 == 0) continue; // lol
    int need = 100 - (lval[i] % 100);
    ret += need * rval[i];
    ragetreeinc(i, n, need);
    all.push_back({need*rval[i], i});
  }
  sort(all.begin(), all.end(), piisort);
  for(pii out: all) {
    ll amt = ragetreequery(out.second, n);
    if(amt >= 100) {
      exact[out.second] = true;
      ragetreeinc(out.second, n, -100);
      ret -= out.first;
    }
  }
  cout << ret << endl;
  for(int i = 1; i <= n; i++) {
    if(lval[i] % 100 == 0) {
      cout << lval[i]/100 << " 0\n";
    }
    else if(exact[i]) {
      cout << lval[i]/100 << " " << lval[i]%100 << "\n";
    }
    else {
      int amt = (lval[i]+99)/100;
      cout << amt << " 0\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}