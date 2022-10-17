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
     
    signed main() {
      ios_base::sync_with_stdio(0);
      cin.tie(0); 
      cout.tie(0);
      int T;
      cin >> T;
      while (T--) {
        int n;
        cin >> n;
        vector<int> cid = {1};
        auto ask = [](vector<int> a, vector<int> b) {
          cout << "? " << SZ(a) << ' ' << SZ(b) << endl;
          for (auto it : a) {
            cout << it << ' ';
          }
          cout << endl;
          for (auto it : b) {
            cout << it << ' ';
          }
          cout << endl;
          int rez;
          cin >> rez;
          return rez;
        };  
     
        auto guess = [](vector<int> ans) {
          cout << "! " << SZ(ans) << ' ';
          for (auto it : ans) {
            cout << it << ' ';
          }
          cout << endl;
        };
        int pos_second = 0;
        for (int i = 2; i <= n; i++) {
          int rez = ask(cid, {i});
          cid.pb(i);
          if (rez != 0) {
            pos_second = i;
            break;
          }
        }
        assert(pos_second != 0);
        vector<int> ans;
        for (int i = pos_second + 1; i <= n; i++) {
          if (ask({pos_second}, {i}) == 0) {
            ans.pb(i);
          }
        }
        int l = 1, r = pos_second;
        while (r - l > 1) {
          int mid = (l + r) / 2;
          vector<int> kek;
          for (int i = mid; i < pos_second; i++) {
            kek.pb(i);
          }
          if (ask(kek, {pos_second}) != 0) {
            l = mid;
          }
          else {
            r = mid;
          }
        }
        for (int i = 1; i < pos_second; i++) {
          if (i != l) {
            ans.pb(i);
          }
        }
        guess(ans);
      }
    }