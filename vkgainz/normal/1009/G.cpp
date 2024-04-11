#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MX = 2e5+5;
int num[1<<6], cnt[6];
void upd(int val, int v) {
  for(int i=0;i<1<<6;i++) {
    if((i&val)==val) num[i]+=v;
  }
}
bool work() {
  for(int i=0;i<1<<6;i++) {
    int sum = 0;
    for(int j=0;j<i;j++) {
      if(i&(1<<j)) sum+=cnt[j];
    }
    if(sum<num[i]) return false;
  }
  return true;
}
int main() {
  string s; cin >> s;
  int m; cin >> m;
  int pos[s.length()];
  for(int i=0;i<s.length();i++)
    cnt[s[i]-'a']++;
  for(int i=0;i<s.length();i++)
    pos[i] = 63;
  for(int i=0;i<m;i++) {
    int p; string t;
    cin >> p >> t;
    --p;
    int bit = 0;
    for(int j=0;j<t.length();j++) {
      bit+=(1<<(t[j]-'a'));
    }
    pos[p] = bit;
  }
  for(int i=0;i<s.length();i++) {
    //cout << pos[i] << " ";
    upd(pos[i], 1);
  }
  string ans = "";
  string ref = "abcdef";
  for(int i=0;i<s.length();i++) {
    upd(pos[i], -1);
    for(int j=0;j<6;j++) {
      if((pos[i]&(1<<j))==0) continue;
      --cnt[j];
      if(work()) {
        ans+=ref[j];
        break;
      }
      ++cnt[j];
    }
  }
  //cout << ans << "\n";
  if(ans.length()<s.length())
    cout << "Impossible" << "\n";
  else
    cout << ans;
}