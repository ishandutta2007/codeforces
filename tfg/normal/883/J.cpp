#include <bits/stdc++.h>
#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define dbg(x) cerr << ">>>>> " << x << endl;
#define _ << " , " << 

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2e5 + 20;

ll bit[ms];
int a[ms], b[ms];
int ma[ms];
map<int, int> mp;

void add(int p, ll val) {
  while(p < ms) {
    bit[p] += val;
    p += p & -p;
  }
}

ll sum(int p) {
  ll ans = 0;
  while (p > 0) {
    ans += bit[p];
    p -= p & -p;
  }
  return ans;
}

map<int, int> din;

int main() {
  int n, m;
  cin >> n >> m;
  fr(i, 0, n) {
    cin >> a[i];
    add(i + 1, a[i]);
    din[i + 1] = a[i];
    mp[a[i]];
  }
  fr(i, 0, m) {
    cin >> b[i];
    mp[b[i]];
  }
  int aux = 0;
  for (auto &it : mp) {
    it.second = aux++;
  }
  fr(i, 0, n) {
    ma[mp[a[i]]] = i + 1;
  }
  for (int i = aux - 2; i > -1; i--) {
    ma[i] = max(ma[i], ma[i+1]);
  }
  fr(i, 0, m) {
    b[i] = ma[mp[b[i]]];
  }
  priority_queue<ii, vector<ii>, greater<ii>> hp;
  fr(i, 0, m) {
    int p;
    cin >> p;
    hp.push(ii(p, b[i]));
  }
  int ans = 0;
  while(!hp.empty()) {
    ii tp = hp.top();
    hp.pop();
    if (sum(tp.second) < tp.first)
      continue;
    auto it = din.upper_bound(tp.second);
    if (it == din.begin())
      continue;
    it--;
    while(tp.first) {
      int a = min(tp.first, it->second);
      tp.first -= a;
      it->second -= a;
      add(it->first, -a);
      auto it2 = it;
      it--;
      if (it2->second == 0) {
        din.erase(it2);
      }
    }
    ans++;
  }
  cout << ans << endl;
}