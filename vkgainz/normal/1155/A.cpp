#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int n; cin >> n;
  string s; cin >> s;
  int seen[26];
  memset(seen, -1, sizeof(seen));
  pair<int, int> ans = {-1, -1};
  for(int i=n-1;i>=0;i--) {
    seen[s[i]-'a'] = i;
    for(int j=0;j<s[i]-'a';j++) {
      if(seen[j] != -1)
        ans = {i, seen[j]};
    }
  }
  if(ans.f == -1) cout << "NO" << "\n";
  else {
    cout << "YES" << "\n";
    cout << ans.f+1 << " " << ans.s+1 << "\n";
  }
}