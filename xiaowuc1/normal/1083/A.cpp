#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 300005;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;

ll ret;
vector<pii> edges[MAX_N]; // <loc, wei>
pill bestDP[MAX_N]; // <loc, wei>
pill secondBestDP[MAX_N];
ll inc[MAX_N];
int n;

vector<int> order;
bool seen[MAX_N];

void bfs(int curr) {
  memset(seen, 0, sizeof(seen));
  seen[curr] = true;
  order.push_back(curr);
  for(int i = 0; i < order.size(); i++) {
    for(pii out: edges[order[i]]) {
      if(!seen[out.first]) {
        seen[out.first] = true;
        order.push_back(out.first);
      }
    }
  }
}

void solve() {
  cin >> n;
  ret = 0;
  for(int i = 1; i <= n; i++) {
    cin >> inc[i];
    ret = max(ret, (ll)inc[i]);
  }
  for(int a = 1; a < n; a++) {
    int x, y, z;
    cin >> x >> y >> z;
    edges[x].push_back({y, z});
    edges[y].push_back({x, z});
  }
  bfs(1);
  ll ret = 0;
  vector<int> orderR;
  for(int i = 0; i < order.size(); i++) {
    orderR.push_back(order[i]);
  }
  reverse(orderR.begin(), orderR.end());
  while(true) {
    bool upd = false;
    for(int i: order) {
      ret = max(ret, bestDP[i].second + inc[i]);
      for(pii out: edges[i]) {
        ll now;
        if(out.first == bestDP[i].first) {
          now = secondBestDP[i].second;
        }
        else {
          now = bestDP[i].second;
        }
        if(now + inc[i] - out.second > bestDP[out.first].second) {
          if(i == bestDP[out.first].first) {
            bestDP[out.first] = {i, now + inc[i] - out.second};
          }
          else {
            secondBestDP[out.first] = bestDP[out.first];
            bestDP[out.first] = {i, now + inc[i] - out.second};
          }
          upd = true;
        }
        else if(i != bestDP[out.first].first && now + inc[i] - out.second > secondBestDP[out.first].second) {
          secondBestDP[out.first] = {i, now + inc[i] - out.second};
          upd = true;
        }
      }
    }
    for(int i: orderR) {
      ret = max(ret, bestDP[i].second + inc[i]);
      for(pii out: edges[i]) {
        ll now;
        if(out.first == bestDP[i].first) {
          now = secondBestDP[i].second;
        }
        else {
          now = bestDP[i].second;
        }
        if(now + inc[i] - out.second > bestDP[out.first].second) {
          if(i == bestDP[out.first].first) {
            bestDP[out.first] = {i, now + inc[i] - out.second};
          }
          else {
            secondBestDP[out.first] = bestDP[out.first];
            bestDP[out.first] = {i, now + inc[i] - out.second};
          }
          upd = true;
        }
        else if(i != bestDP[out.first].first && now + inc[i] - out.second > secondBestDP[out.first].second) {
          secondBestDP[out.first] = {i, now + inc[i] - out.second};
          upd = true;
        }
      }
    }
    if(!upd) break;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}