#include <bits/stdc++.h>
using namespace std;

string s;
int n;

bool iden(string);
pair<int, int> dir(char, char);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> s;
  vector<int> dig;
  for (int i = 0; i <= 9; ++i) dig.push_back(i);
  do {
    string t = "";
    for (int i = 0; i < n; ++i) t += (char)(dig[s[i] - '0'] + '0');
    if (t == s) continue;
    if (iden(t)) return cout << "NO\n", 0;
  } while (next_permutation(dig.begin(), dig.end()));
  cout << "YES\n";
  return 0;
}

bool iden(string t) {
  for (int i = 0; i < t.length() - 1; ++i) {
    if (dir(t[i], t[i + 1]) != dir(s[i], s[i + 1])) return false;
  }
  return true;
}

pair<int, int> dir(char a, char b) {
  if (a == b) return make_pair(0, 0);
  if (a != '0' && b != '0') {
    int aa = a - '0', bb = b - '0';
    return make_pair((bb - 1) % 3 - (aa - 1) % 3, (bb - 1) / 3 - (aa - 1) / 3);
  }
  bool rev = false;
  pair<int, int> ret;
  if (a == '0') swap(a, b), rev = true;
  if (a == '1') ret = make_pair(1, 3);
  if (a == '2') ret = make_pair(0, 3);
  if (a == '3') ret = make_pair(-1, 3);
  if (a == '4') ret = make_pair(1, 2);
  if (a == '5') ret = make_pair(0, 2);
  if (a == '6') ret = make_pair(-1, 2);
  if (a == '7') ret = make_pair(1, 1);
  if (a == '8') ret = make_pair(0, 1);
  if (a == '9') ret = make_pair(-1, 1);
  if (rev) ret.first = -ret.first, ret.second = -ret.second;
  return ret;
}