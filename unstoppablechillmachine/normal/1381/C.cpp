#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll    

const int N = 1e5 + 10;
int cnt[N], a[N], ans[N];
vector<int> have[N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, x, y;
    cin >> n >> x >> y;
    for (int i = 1; i <= n + 1; i++) {
      cnt[i] = 0;
      have[i] = {};
      ans[i] = 0;
    }
    set<pair<int, int>> st;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      cnt[a[i]]++;
      have[a[i]].pb(i);
    }
    int kek_id = 0;
    for (int i = 1; i <= n + 1; i++) {
      if (cnt[i] > 0) st.insert({cnt[i], i});
      else kek_id = i;
    }
    for (int i = 1; i <= x; i++) {
      int cur_color = (--st.end())->S;
      st.erase(--st.end());
      ans[have[cur_color].back()] = cur_color;
      have[cur_color].pop_back();
      cnt[cur_color]--;
      if (cnt[cur_color] > 0) st.insert({cnt[cur_color], cur_color});
    }
    y -= x;
    while (y >= 2 && SZ(st) >= 2) {
      if (y == 3 && SZ(st) >= 3) {
        int cur_color1 = (--st.end())->S, cur_color2 = (----st.end())->S, 
        cur_color3 = (------st.end())->S;
        st.erase({cnt[cur_color1], cur_color1});
        st.erase({cnt[cur_color2], cur_color2});
        st.erase({cnt[cur_color3], cur_color3});
        ans[have[cur_color2].back()] = cur_color1;
        ans[have[cur_color1].back()] = cur_color3;
        ans[have[cur_color3].back()] = cur_color2;
        have[cur_color1].pop_back();
        have[cur_color2].pop_back();
        have[cur_color3].pop_back();
        cnt[cur_color2]--;
        cnt[cur_color1]--;
        cnt[cur_color3]--;
        if (cnt[cur_color1] > 0) {
          st.insert({cnt[cur_color1], cur_color1});
        }
        if (cnt[cur_color2] > 0) {
          st.insert({cnt[cur_color2], cur_color2});
        }
        if (cnt[cur_color3] > 0) {
          st.insert({cnt[cur_color3], cur_color3});
        }
        y -= 3;
        continue;
      }
      int cur_color1 = (--st.end())->S, cur_color2 = (----st.end())->S;
      st.erase({cnt[cur_color1], cur_color1});
      st.erase({cnt[cur_color2], cur_color2});
      ans[have[cur_color2].back()] = cur_color1;
      ans[have[cur_color1].back()] = cur_color2;
      have[cur_color1].pop_back();
      have[cur_color2].pop_back();
      cnt[cur_color2]--;
      cnt[cur_color1]--;
      if (cnt[cur_color1] > 0) {
        st.insert({cnt[cur_color1], cur_color1});
      }
      if (cnt[cur_color2] > 0) {
        st.insert({cnt[cur_color2], cur_color2});
      }
      y -= 2;
    }
    if (y > 0 && SZ(st) == 1) {
      cout << "NO\n";
      continue;
    }
    if (y == 1) {
      int cur_color1 = (--st.end())->S, cur_color2 = (----st.end())->S;
      ans[have[cur_color1].back()] = cur_color2;
    }
    for (int i = 1; i <= n; i++) {
      if (ans[i] == 0) {
        ans[i] = kek_id;
      }
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }  
}