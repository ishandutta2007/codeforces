#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> k(n);
    vector<set<int>> a(n);
    for (int i = 1; i < n; i++) {
      cin >> k[i];
      for (int j = 0; j < k[i]; j++) {
        int x;
        cin >> x;
        --x;
        a[i].insert(x);
      }
    }
    auto Valid = [&](vector<int> perm) {
      if (perm.size() != n) {
        return false;
      }
      set<set<int>> st;
      for (int i = 0; i < n; i++) {
        set<int> curr;
        for (int j = i; j < n; j++) {
          curr.insert(perm[j]);
          st.insert(curr);
        }
      }
      for (int i = 1; i < n; i++) {
        if (st.find(a[i]) == st.end()) {
          return false;
        }
      }
      return true;
    };
    vector<int> ans;
    for (int x = 0; x < n; x++) {
      vector<int> ck(n);
      vector<set<int>> ca(n);
      for (int j = 1; j < n; j++) {
        ck[j] = k[j];
        for (int p : a[j]) {
          ca[j].insert(p);
        }
      }
      //cout << "pozz" << endl;
      for (int j = 1; j < n; j++) {
        if (ck[j] > 0 && ca[j].find(x) != ca[j].end()) {
          ck[j] -= 1;
          ca[j].erase(ca[j].find(x));
        }
      }
      vector<int> perm(1, x);
      for (int j = 1; j < n; j++) {
        int cnt = 0;
        for (int q = 0; q < n; q++) {
          if (ck[q] == 1) {
            cnt += 1;
          }
        }
        if (cnt != 1) {
          break;
        }
        for (int q = 1; q < n; q++) {
          //cout << "pozzzz" << endl;
          if (ck[q] == 1) {
            //assert(!ca[q].empty());
            int nx = *ca[q].begin();
            perm.push_back(nx);
            ca[q].erase(ca[q].begin());
            ck[q] -= 1;
            for (int l = 0; l < n; l++) {
              if (ck[l] > 0 && ca[l].find(nx) != ca[l].end()) {
                ck[l] -= 1;
                ca[l].erase(ca[l].find(nx));
              }
            }
            break;
          }
        }
      }
      /*if (n == 6 && x == 2) {
        cout << "omg\n";
        for (int qqq : perm) {
          cout << qqq + 1 << " ";
        }
        cout << Valid(perm) << '\n';
      }*/
      if (Valid(perm)) {
        ans = perm;
      }
    }
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] + 1 << " ";
    }
    cout << '\n';
  }
  return 0;
}