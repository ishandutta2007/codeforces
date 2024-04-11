#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  set<string> ret;
  ret.insert("Power");
  ret.insert("Time");
  ret.insert("Space");
  ret.insert("Soul");
  ret.insert("Reality");
  ret.insert("Mind");
  int n;
  cin >> n;
  while(n--) {
    string s;
    cin >> s;
    if(s == "purple") ret.erase("Power");
    if(s == "green") ret.erase("Time");
    if(s == "blue") ret.erase("Space");
    if(s == "orange") ret.erase("Soul");
    if(s == "red") ret.erase("Reality");
    if(s == "yellow") ret.erase("Mind");
  }
  cout << ret.size() << endl; 
  for(string out: ret) cout << out << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}