#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;
void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> in(m);
  vector<int> freq(n);
  vector<int> numMult(n);
  for(int i=0;i<m;i++) {
    int k; cin >> k;
    in[i].resize(k);
    for(auto &a : in[i]) cin >> a, --a, ++freq[a];
    if(k == 1) {
      for(auto &a : in[i]) ++numMult[a];
    }
  }
  bool work = true;
  for(int i=0;i<n;i++) {
    if(numMult[i] > (m+1)/2) {
      work = false;
    }
  }
  if(!work) {
    cout << "NO" << "\n";
    return;
  }
  bool found = false;
  vector<int> ans;
  for(int i=0;i<n;i++) { //make this max
    if(freq[i] < (m+1)/2) continue;
    found = true;
    ans.assign(m, -1);
    int soFar = 0;
    for(int j=0;j<m;j++) {
      if(in[j].size() == 1 && in[j][0] == i)
        ans[j] = i, ++soFar;
    }
    for(int j=0;j<m;j++) {
      if(in[j].size() == 1 || soFar >= (m+1)/2) continue;
      bool inside = false;
      for(int x : in[j])
        if(x == i) inside = true;
      if(inside && soFar+1 <=(m+1)/2) {
        ans[j] = i;
        ++soFar;
      }
    }
    for(int j=0;j<m;j++) {
      if(ans[j] != -1) continue;
      for(int x : in[j]) {
        if(x != i) {
          ans[j] = x;
          break;
        }
      }
    }
    break;
  }
  if(found) {
    cout << "YES" << "\n";
    for(auto &it : ans) cout << it+1 << " ";
    cout << "\n";
    return;
  }
  for(int i=0;i<m;i++) {
    ans.push_back(in[i][0]);
  }
  cout << "YES" << "\n";
    for(auto &it : ans) cout << it+1 << " ";
    cout << "\n";
  //print
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; cin >> t;
  while(t--) solve();
}