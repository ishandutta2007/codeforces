#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main() {
  int n; cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  int ans = 0;
	vector<pair<int, int>> in;
  for(int i=0;i<n;i++) {
    int len = 0;
    for(int j=i;j<n && a[j]==a[i];j++) {
      ++len;
      i = j;
    }
    in.push_back({a[i], len});
    ans+=max(len-2,0);
  }
  vector<bool> resolve(in.size(), false);
  if(in[resolve.size()-1].s > 1) resolve.back() = true;
  if(resolve.size() >=2 && in[resolve.size()-2].s > 1) resolve[resolve.size()-2] = true;
  for(int i=in.size()-3;i>=0;i--) {
    if(in[i].s == 1) {
      if(in[i+1].s == 1 && resolve[i+2] && in[i+2].f == in[i].f) {
        resolve[i] = true;
      }
    }
    else {
      if(in[i+1].s == 1 && resolve[i+2] && in[i+2].f == in[i].f) {
        ++ans;
      }
      resolve[i] = true;
    }
  }
  cout << n-ans << "\n";
}