    #include <bits/stdc++.h>
    typedef long long ll;
    typedef long double ld;
    using namespace std;
    #define pb push_back
    #define all(x) (x).begin(), (x).end()
    #define SZ(x) (int)(x).size()
    #define int ll
    #define F first
    #define S second
     
    const int INF = 1e9 + 10;
     
    string solve(string s, char fl) {
      int l = 0, r = SZ(s) - 1;
      while (l < SZ(s) && s[l] != fl) {
        l++;
      }
      while (r >= 0 && s[r] != fl) {
        r--;
      }
      string ans;
      while (l < r) {
        ans.pb(s[l]);
        l++;
        r--;
        if (l >= r) {
          break;
        }
        if (r - l == 1) {
          if (s[l] == s[r]) {
            ans.pb(s[l]);
            l++;
            r--;
          }
          else {
            l++;
          }
        }
        else if (r - l == 2) {
          if (s[l] == s[r]) {
            ans.pb(s[l]);
            l++;
            r--;
          }
          else if (s[l] == s[r - 1]) {
            ans.pb(s[l]);
            l++;
            r -= 2;
          }
          else if (s[l + 1] == s[r]) {
            ans.pb(s[l + 1]);
            l += 2;
            r--;
          }
          else {
            l++;
            r--;
          }
        }
        else {
          if (s[l] == s[r]) {
            continue;
          }
          else if (s[l + 1] == s[r]) {
            l++;
          }
          else if (s[l] == s[r - 1]) {
            r--;
          }
          else {
            assert(s[l + 1] == s[r - 1]);
            l++;
            r--;
          }
        }
      }
      if (l == r) {
        string ans2 = ans;
        reverse(all(ans2));
        ans.pb(s[l]);
        ans += ans2;
        return ans;
      }
      else {
        string ans2 = ans;
        reverse(all(ans2));
        ans += ans2;
        return ans;
      }
    }
     
    signed main() {
      ios_base::sync_with_stdio(0);
      string s;
      cin >> s;
      string ans1 = solve(s, 'a'), ans2 = solve(s, 'b'), ans3 = solve(s, 'c');
      if (SZ(ans1) >= SZ(s) / 2) {
        cout << ans1 << '\n';
      }
      else if (SZ(ans2) >= SZ(s) / 2) {
        cout << ans2 << '\n';
      }
      else if (SZ(ans3) >= SZ(s) / 2) {
        cout << ans3 << '\n';
      }
      else {
        cout << "IMPOSSIBLE\n";
      }
    }