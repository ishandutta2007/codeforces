#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second

const int N = 3e5 + 10;
typedef long long ll;
int n, x1, x2;
int c[N];
vector <int> ans[4];

int find(vector <ll> &dmin, ll x) {
  int who = -1;
  for (int i = 0; i < dmin.size(); ++i) {
    if (dmin[i] >= x) {
      who = i;
      return who;
    }
  }
  return who;
}

vector <ll> go(vector < pair <int, int> > &v) {
  vector <ll> d;
  for (int i = 0; i < v.size(); ++i) {
    d.push_back(1ll * v[i].X * (i + 1));
  }
  return d;
}

vector <ll> gomin(vector <ll> &d) {
  vector <ll> dmin;
  if (d.empty()) return dmin;
  dmin.push_back(d[0]);
  for (int i = 1; i < d.size(); ++i) {
    dmin.push_back(max(dmin.back(), d[i]));
  }
  return dmin;
}

vector <int> get(vector < pair <int, int> > &v, int who) {
  vector <int> ret;
//    assert(who < v.size());
//    cout << who << endl;
  for (int i = 0; i <= who; ++i) {
    ret.push_back(v[i].Y);
  }
  return ret;
}

int main() {
  scanf("%d%d%d", &n, &x1, &x2);
  vector < pair <int, int> > v;
  for (int i = 0; i < n; ++i) {
    scanf("%d", c + i);
    v.emplace_back(c[i], i);
  }
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  
  for (int id = 1; id <= 2; ++id) {
    int x = id == 1 ? x1 : x2;
    int y = x1 + x2 - x;
//    cout << "???" << endl;
    auto d = go(v);
//    cout << "!!!" << endl;
    auto dmin = gomin(d);
//    cout << "+++" << endl;
//    for (auto &x : dmin)
//        cout << x << ' '; cout << endl;
    int who = find(dmin, x);
//    cout << "---" << endl;
    if (who != -1) {
//      cout << v.size() << ' ' << who << endl;
      vector < pair <int, int> > vtmp(v.begin() + who + 1, v.end());
      vector <ll> dtmp = go(vtmp);
      vector <ll> dmintmp = gomin(dtmp);
        
//        for (auto &x : dmintmp) cout << x << ' '; cout << endl;
      int who2 = find(dmintmp, y);
      if (who2 != -1) {
        ans[id] = get(v, who);
        ans[3 - id] = get(vtmp, who2);
      }
    }
//    for (auto x : ans[1]) printf("%d ", x+1);
//    puts("");
//    for (auto x : ans[2]) printf("%d ", x+1);
//   puts(""); 
  }

  if (!ans[1].empty() && !ans[2].empty()) {
    puts("Yes");
    sort(ans[1].begin(), ans[1].end());
    sort(ans[2].begin(), ans[2].end());
    printf("%u %u\n", ans[1].size(), ans[2].size());
    for (auto x : ans[1]) printf("%d ", x+1);
    puts("");
    for (auto x : ans[2]) printf("%d ", x+1);
    puts("");
  } else {
    puts("No");
  }


  return 0;
}