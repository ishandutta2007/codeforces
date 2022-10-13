#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
typedef gp_hash_table<int, null_type, hash<int>> ht;
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 2e5 + 5;
const int BLOCK_SZ = 300; 

int main() {
  int T; cin >> T;
  while(T--) {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    bool found = false;
    string ans = "";
    int freq[26];
    memset(freq, 0, sizeof(freq));
    pair<int, int> ret = {-1, 0};
    for(int i=0;i<n;i++) {
      //first i (1 indexed) char equal
      int temp[26];
      for(int j=0;j<26;j++) temp[j] = freq[j];
      for(int j=s[i]-'a'+1;j<26;j++) {
        ++temp[j];
        int numLeft = n-i-1;
        int sum = 0;
        for(int x=0;x<26;x++) {
          if(temp[x]%k==0) continue;
          sum += ((k - (temp[x] % k))%k);
        }
        if(sum <= numLeft && sum%k == numLeft%k) {
          found = true;
          if(i > ret.f) ret = {i, j};
          else if(i == ret.f) ret.s = min(ret.s, j);
        }
        --temp[j];
      }
      ++freq[s[i]-'a'];
    }
    int sum = 0;
    for(int x=0;x<26;x++) {
      if(freq[x]%k==0) continue;
      sum += (k - (freq[x] % k));
    }
    if(sum == 0) {
      found = true;
      ret = {n-1, s[n-1]-'a'};
    }
    if(!found|| (n%k>0)) {
      cout << -1 << "\n";
      continue;
    }
    //create string
    string r = "abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<26;i++) freq[i] = 0;
    for(int i=0;i<ret.f;i++) {
      ++freq[s[i]-'a'];
    }
    ans = s.substr(0, ret.f);
    ans += r[ret.s];
    ++freq[ret.s];
    sum = 0;
    for(int i=0;i<26;i++) {
      if(freq[i]%k==0) continue;
      sum += (k-(freq[i]%k));
    }
    int numLeft = n-1-ret.f;
    while(numLeft > 0) {
      if(sum < numLeft) ans += 'a';
      else {
        for(int i=0;i<26;i++) {
          if(freq[i]%k==0) continue;
          ans += r[i];
          ++freq[i];
          break;
        }
      }
      --numLeft;
    }
    cout << ans << "\n";
  }
}