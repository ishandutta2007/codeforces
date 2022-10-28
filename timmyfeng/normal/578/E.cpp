#include <bits/stdc++.h>
using namespace std;

void print(vector<int> *v) {
  for (auto i : *v) {
    cout << i + 1 << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  vector<vector<int>*> l, r;
  for (int i = 0; i < n; ++i) {
    if (s[i] == 'L') {
      if (r.empty()) {
        l.push_back(new vector<int>(1, i));
      } else {
        vector<int> *v = r.back();
        r.pop_back();
        v->push_back(i);
        l.push_back(v);
      }
    } else {
      if (l.empty()) {
        r.push_back(new vector<int>(1, i));
      } else {
        vector<int> *v = l.back();
        l.pop_back();
        v->push_back(i);
        r.push_back(v);
      }
    }
  }

  vector<vector<int>*> ll, rl, rr, lr;
  for (auto i : l) {
    (s[i->front()] == s[i->back()] ? ll : rl).push_back(i);
  }
  for (auto i : r) {
    (s[i->front()] == s[i->back()] ? rr : lr).push_back(i);
  }

  while (!lr.empty() && !rl.empty()) {
    vector<int> *u = rl.back(), *v = lr.back();
    rl.pop_back(), lr.pop_back();

    if (u->back() > v->back()) {
      v->push_back(u->back());
      u->pop_back();
    } else {
      u->push_back(v->back());
      v->pop_back();
    }

    rr.push_back(u);
    ll.push_back(v);
  }

  cout << ll.size() + rr.size() + lr.size() + rl.size() - 1 << "\n";
  if (ll.size() < rr.size()) {
    for (auto i : rl) {
      print(i);
    }
    for (int i = 0; i < (int) ll.size(); ++i) {
      print(rr[i]), print(ll[i]);
    }
    print(rr.back());
    for (auto i : lr) {
      print(i);
    }
  } else if (ll.size() == rr.size()) {
    for (auto i : lr) {
      print(i);
    }
    if (!ll.empty()) {
      print(ll[0]);
    }
    for (auto i : rl) {
      print(i);
    }
    if (!rr.empty()) {
      print(rr[0]);
    }
    for (int i = 1; i < (int) ll.size(); ++i) {
      print(ll[i]), print(rr[i]);
    }
  } else {
    for (auto i : lr) {
      print(i);
    }
    for (int i = 0; i < (int) rr.size(); ++i) {
      print(ll[i]), print(rr[i]);
    }
    print(ll.back());
    for (auto i : rl) {
      print(i);
    }
  }

  cout << "\n";
}