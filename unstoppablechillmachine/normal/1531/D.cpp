#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int inf = 1e9 + 10;
  
struct node {
  int position_of_last_change, 
  position_of_last_lock,
  position_of_last_unlock,
  position_of_first_unlock,
  len;
  node() {}
  node(const string& cmd) : position_of_last_change(0), position_of_last_lock(inf), position_of_last_unlock(inf), position_of_first_unlock(inf), len(1) {
    if (cmd == "lock") {
      position_of_last_lock = 1;
    } else if (cmd == "unlock") {
      position_of_first_unlock = position_of_last_unlock = 1;
    } else {
      position_of_last_change = 1;
    }
  }
};

node merge(const node& lhs, const node& rhs) {
  node result;
  result.len = lhs.len + rhs.len;
  result.position_of_first_unlock = (lhs.position_of_first_unlock < inf ? lhs.position_of_first_unlock : rhs.position_of_first_unlock + lhs.len);
  result.position_of_last_unlock = (rhs.position_of_last_unlock < inf ? rhs.position_of_last_unlock + lhs.len : lhs.position_of_last_unlock);
  result.position_of_last_lock = (rhs.position_of_last_lock < inf ? rhs.position_of_last_lock + lhs.len : lhs.position_of_last_lock);
  if (!rhs.position_of_last_change) {
    result.position_of_last_change = lhs.position_of_last_change;
  } else {
    if (lhs.position_of_last_lock >= inf || (lhs.position_of_last_unlock < inf && lhs.position_of_last_lock < lhs.position_of_last_unlock) || 
       (rhs.position_of_first_unlock < inf && rhs.position_of_last_change > rhs.position_of_first_unlock)) {
      result.position_of_last_change = rhs.position_of_last_change + lhs.len;
    } else {
      result.position_of_last_change = lhs.position_of_last_change;
    }
  }
  return result;
}

const int maxn = 1e5 + 10;
node t[4 * maxn];
 
void build(int v, int l, int r, vector<string>& seq) {
  if (l == r) {
    t[v] = node(seq[l - 1]);
    //cout << v << endl;
    return;
  }
  int mid = (l + r) / 2;
  build(2 * v, l, mid, seq);
  build(2 * v + 1, mid + 1, r, seq);
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

void update(int v, int l, int r, int need, string& new_cmd) {
  if (l == r) {
    t[v] = node(new_cmd);
    return;
  }
  int mid = (l + r) / 2;
  if (need <= mid) {
    update(2 * v, l, mid, need, new_cmd);
  } else {
    update(2 * v + 1, mid + 1, r, need, new_cmd);
  }
  t[v] = merge(t[2 * v], t[2 * v + 1]);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n;
  cin >> n;
  vector<string> seq(n);
  for (auto& cmd : seq) {
    cin >> cmd;
  }
  build(1, 1, n, seq);
  cout << (t[1].position_of_last_change == 0 ? "blue" : seq[t[1].position_of_last_change - 1]) << '\n';
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int pos;
    string new_cmd;
    cin >> pos >> new_cmd;
    seq[pos - 1] = new_cmd;
    update(1, 1, n, pos, new_cmd);
    cout << (t[1].position_of_last_change == 0 ? "blue" : seq[t[1].position_of_last_change - 1]) << '\n';
  }
  return 0;
}