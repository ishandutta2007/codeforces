#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

vi euler(const vii & edges, int n) {
  vector < vector<int> > gr (n);
  vector < vector<int> > gre (n);
  for (int i = 0; i < edges.size(); ++i) {
    int a = edges[i].first, b = edges[i].second;
    gr[a].push_back(b);
    gr[b].push_back(a);
    gre[a].push_back(i);
    gre[b].push_back(i);
  }
  for (int i = 0; i < n; ++i) if (gr[i].size() % 2) return vi();
  vi res;
  vi used(edges.size());
  vi it(n);
  int first = 0;
  while (first + 1 < n && gr[first].empty()) ++first;
  stack<int> st;
  st.push (first);
  while (!st.empty())
  {
    int v = st.top();
    for (; it[v] < gr[v].size(); ++it[v])
      if (used[gre[v][it[v]]] == 0)
        break;
    if (it[v] == gr[v].size())
    {
      res.push_back (v);
      st.pop();
    }
    else
    {
      used[gre[v][it[v]]] = 1;
      st.push (gr[v][it[v]]);
    }
  }
  return res;
}

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vii v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i].first >> v[i].second;
  }
  for (int b = 20; b >= 0; --b) {
    int m = 1 << b;
    vii e;
    for (int i = 0; i < n; ++i) {
      e.emplace_back(v[i].first % m, v[i].second % m);
    }
    vi x = euler(e, m);
//    cerr << b << ' ' << x.size() << endl;
    if (x.size() != e.size() + 1) continue;
    map<pii, vi> w;
    for (int i = 0; i < n; ++i) {
      pii p = e[i];
      if (p.first > p.second) swap(p.first, p.second);
//      cerr << p.first << ' ' << p.second << endl;
      w[p].push_back(i);
    }
    cout << b << '\n';
    for (int i = 0; i + 1 < x.size(); ++i) {
//      cerr << x[i] << ' ' << x[i + 1] << endl;
      pii p(x[i], x[i + 1]);
      if (p.first > p.second) swap(p.first, p.second);
      assert(!w[p].empty());
      int j = w[p].back();
      w[p].pop_back();
      if (x[i] == e[j].first) {
        cout << 2 * j + 1 << ' ' << 2 * j + 2 << ' ';
      } else {
        cout << 2 * j + 2 << ' ' << 2 * j + 1 << ' ';
      }
    }
    cout << '\n';
    return 0;
  }
  return 0;
}