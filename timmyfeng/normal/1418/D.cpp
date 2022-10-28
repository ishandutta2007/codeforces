#include <bits/stdc++.h>
using namespace std;

map<int, int> piles;
multiset<int> gaps;

void add(int x) {
  if (piles.count(x) == 0) {
    auto it = piles.insert({x, 0}).first;
    auto prv = it;
    auto nxt = it;
    if (prv != piles.begin()) {
      --prv;
      gaps.insert(it->first - prv->first);
    }
    if (nxt != --piles.end()) {
      ++nxt;
      gaps.insert(nxt->first - it->first);
    }
    if (prv->first < it->first && it->first < nxt->first) {
      gaps.erase(gaps.find(nxt->first - prv->first));
    }
  }
  ++piles[x];
}

void remove(int x) {
  --piles[x];
  if (piles[x] == 0) {
    auto it = piles.find(x);
    auto prv = it;
    auto nxt = it;
    if (prv != piles.begin()) {
      --prv;
      gaps.erase(gaps.find(it->first - prv->first));
    }
    if (nxt != --piles.end()) {
      ++nxt;
      gaps.erase(gaps.find(nxt->first - it->first));
    }
    if (prv->first < it->first && it->first < nxt->first) {
      gaps.insert(nxt->first - prv->first);
    }
    piles.erase(it);
  }
}

void print() {
  if (piles.size() <= 2u) {
    cout << 0 << "\n";
  } else {
    cout << (--piles.end())->first - piles.begin()->first - *(--gaps.end()) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    add(a);
  }
  print();

  while (q--) {
    int type, a;
    cin >> type >> a;
    if (type == 0) {
      remove(a);
    } else {
      add(a);
    }
    print();
  }
}