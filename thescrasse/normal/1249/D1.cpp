// 1249D2
// segmenti sovrapposti
// idee: greedy (rimuovo i segmenti che finiscono dopo), pq ordinata per estremo destro
// update con il delta

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, a, b, m, check1, c, dt[200010], ks, r1;
priority_queue<pair<long long, pair<long long, long long>>> pq;
vector<pair<long long, pair<long long, long long>>> sg;
vector<long long> res;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> k1;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    sg.push_back({a, {b, i + 1}});
    dt[a]++;
    dt[b + 1]--;
  }

  sort(sg.begin(), sg.end());

  ks = 0;
  k = 0;
  for (i = 1; i <= 200000; i++) {
    // cout << i << endl;
    while (ks < n) {
      if (sg[ks].first == i) {
        pq.push({sg[ks].second.first, {i, sg[ks].second.second}});
      } else {
        break;
      }
      ks++;
    }
    k += dt[i];
    // cout << k << endl;
    while (k > k1) {
      b = pq.top().first;
      r1 = pq.top().second.second;
      // cout << b << ' ' << r1 << endl;
      pq.pop();
      dt[b + 1]++;
      k--;
      res.push_back(r1);
    }
  }

  cout << res.size() << endl;
  for (i = 0; i < res.size(); i++) {
    cout << res[i] << ' ';
  }

  return 0;
}