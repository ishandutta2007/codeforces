#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void inject(set<string>& s) {
  string ss;
  cin >> ss;
  s.insert(ss);
}

void dump(set<string>& s) {
  cout << *s.begin() << " " << *s.rbegin() << "\n";
}

void solve() {
  set<string> s;
  inject(s);
  inject(s);
  int n;
  cin >> n;
  while(n--) {
    dump(s);
    string a, b;
    cin >> a >> b;
    s.erase(a);
    s.insert(b);
  }
  dump(s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}