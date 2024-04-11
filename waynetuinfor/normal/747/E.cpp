#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <cstring>
using namespace std;

string s;
vector<string> cmd;
vector<int> G[1000005];
vector<int> level[1000005];
map<string, int> mp;
int m, Max;
int DFS(int);
stringstream ss;
int jizz(const string&);
void dfs(int, int);
bool v[1000005];

int main() {
  getline(cin, s);
  int st = 0;
  for (int i = 0; i < s.length(); ++i) if (s[i] == ',') cmd.push_back(s.substr(st, i - st)), st = i + 1;
  cmd.push_back(s.substr(st, s.length() - st));
  for (int i = 0; i < cmd.size(); i += 2) if (!v[i]) DFS(i), m += 2;
  memset(v, false, sizeof(v));
  for (int i = 0; i < cmd.size(); i += 2) if (!v[i]) dfs(i, 1);
  cout << Max << '\n';
  for (int i = 1; i <= Max; ++i) {
    for (int j : level[i]) cout << cmd[j] << ' ';
    cout << '\n';
  }
  return 0;
}

int DFS(int x) {
  v[x] = true;
  for (int i = 0; i < jizz(cmd[x + 1]); ++i) m += 2, G[x].push_back(DFS(m));
  return x;
}

int jizz(const string& n) {
  ss.clear(); ss.str("");
  ss << n;
  int ret;
  ss >> ret;
  return ret;
}

void dfs(int x, int dep) {
  v[x] = true;
  if (dep > Max) Max = dep;
  level[dep].push_back(x);
  for (int u : G[x]) if (!v[u]) dfs(u, dep + 1);
}