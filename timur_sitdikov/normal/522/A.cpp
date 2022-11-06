
#include <iostream>
#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 234;
map<string, int> mp;
vector<int> g[maxn];

int dfs(int v) {
 int ret = 0;
 for (int i = 0, sz = g[v].size(); i < sz; ++i) {
  int to = g[v][i];
  ret = max(ret, dfs(to));
 }
 return ret + 1;
}

int main () {

 int n;
 cin >> n;
 string s[3];
 int sz = 0;
 string polycarp = "polycarp";
 mp[polycarp] = sz++;
 for (int i = 0; i < n; ++i) {
  cin >> ws >> s[0] >> ws >> s[1] >> ws >> s[2];
  for (int j = 0; j < s[0].size(); ++j) {
   s[0][j] = tolower(s[0][j]);
  }
  for (int j = 0; j < s[2].size(); ++j) {
   s[2][j] = tolower(s[2][j]);
  }
  mp[s[0]] = sz++; 
  int a, b;
  a = mp[s[0]];
  b = mp[s[2]]; 
  g[b].push_back(a);
 } 
 int answer = dfs(0);
 cout << answer;
 return 0;
}