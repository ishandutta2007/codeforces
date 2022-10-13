#include <bits/stdc++.h>
using namespace std;
const int sz = 1000;
unordered_map<bitset<sz>, int> leftIn, rightIn; //change to unordered or gt_hash_table
int query(bitset<sz> d) {
  int ans = 10000; 
  for(auto &it : leftIn) {
    bitset<sz> need = it.first ^ d;
    if(rightIn.find(need) != rightIn.end()) {
      ans = min(ans, it.second + rightIn[need]);
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s, d; cin >> n >> s >> d;
  vector<bitset<sz>> in(s);  
  for(int i=0;i<s;i++) {
    int c; cin >> c;
    string s = "";
    for(int i=0;i<sz;i++) s+="0";
    for(int j=0;j<c;j++) {
      int x; cin >> x;
      --x;
      s[x] = '1';
    }
    in[i] = bitset<sz>(s);
  }
  for(int msk=0;msk<1<<((s)/3);msk++) {
    bitset<sz> b;
    int cnt = __builtin_popcount(msk);
    for(int i=0;i<(s/3);i++) {
      if(msk&(1<<i)) b ^= in[i];
    }
    if(leftIn.find(b) != leftIn.end())
      leftIn[b] = min(leftIn[b], cnt);
    else
      leftIn[b] = cnt;
  }
  for(int msk=0;msk<(1<<(s-(s/3)));msk++) {
    bitset<sz> b;
    int cnt = __builtin_popcount(msk);
    for(int i=0;i<(s-(s/3));i++) {
      if(msk&(1<<i)) b ^= in[(i+(s/3))];
    }
    if(rightIn.find(b) != rightIn.end())
      rightIn[b] = min(rightIn[b], cnt);
    else
      rightIn[b] = cnt;
  }
  for(int i=0;i<d;i++) {
    int t; cin >> t;
    string s = "";
    for(int i=0;i<sz;i++) s+="0";
    for(int j=0;j<t;j++) {
      int x; cin >> x;
      --x;
      s[x] = '1';
    }
    int a = query(bitset<sz>(s));
    if(a == 10000) cout << -1 << "\n";
    else cout << a << "\n";
  }
}