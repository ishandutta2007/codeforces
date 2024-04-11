#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define f first
#define s second
typedef long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;
const int MX = 1e6+5;

int main() {
  int n; cin >> n;
  int s[n];
  for(int i=0;i<n;i++)
    cin >> s[i];
  vector<int> pos[101];
  char ans[n];
  for(int i=0;i<n;i++)
    pos[s[i]].push_back(i);
  int a = 0, b = 0;
  for(int i=0;i<=100;i++) {
    if(pos[i].size()==1) {
      if(a<b) {
        ans[pos[i][0]] = 'a', ++a;
        for(int j=1;j<pos[i].size();j++)
          ans[pos[i][j]] = 'b';
      }
      else {
        ans[pos[i][0]] = 'b', ++b;
        for(int j=1;j<pos[i].size();j++) 
          ans[pos[i][j]] = 'a';
      }
    }
  }
  for(int i=0;i<=100;i++) {
    if(pos[i].size()==2) {
      ans[pos[i][0]] = 'a', ++a;
      ans[pos[i][1]] = 'b', ++b;
    }
    else if(pos[i].size()==3) {
      if(a==b) {
        for(int j=0;j<pos[i].size();j++)
          ans[pos[i][j]] = 'b';
      }
      else if(a<b) {
        ans[pos[i][0]] = 'a', ++a;
        for(int j=1;j<pos[i].size();j++)
          ans[pos[i][j]] = 'b';
      }
      else {
        ans[pos[i][0]] = 'b', ++b;
        for(int j=1;j<pos[i].size();j++) 
          ans[pos[i][j]] = 'a';
      }
    }
    else if(pos[i].size()>3) {
      if(a==b) {
        for(int j=0;j<pos[i].size();j++)
          ans[pos[i][j]] = 'b';
      }
      else if(a<b) {
        ans[pos[i][0]] = 'a', ++a;
        for(int j=1;j<pos[i].size();j++)
          ans[pos[i][j]] = 'b';
      }
      else {
        ans[pos[i][0]] = 'b', ++b;
        for(int j=1;j<pos[i].size();j++) 
          ans[pos[i][j]] = 'a';
      }
    }
  }
  if(a==b) {
    string ret = "";
    for(int i=0;i<n;i++) {
      if(ans[i]=='a') ret+='A';
      else ret+='B';
    }
    cout << "YES" << "\n";
    cout << ret;
  }
  else cout << "NO";
}