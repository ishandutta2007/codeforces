#include <bits/stdc++.h>

/*
unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
mt19937 g1.seed(seed1);

ios_base::sync_with_stdio(false);
cin.tie(NULL);
*/
using namespace std;

const double PI = 2 * acos(0);

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<int, ll> pill;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<vector<ll>> matrix;

void solveSmall(string s, vector<int>& ret);
void solveLarge(string s, vector<int>& ret);

void solveSmall(string s, vector<int>& ret) {
  if(s.length() == 1) {
    ret.push_back(0);
    return;
  }
  char lowest = s[0];
  for(int i = 1; i < s.length(); i++) {
    lowest = min(lowest, s[i]);
  }
  if(s[s.size()-1] == lowest) {
    ret.push_back(1);
    s = s.substr(0, s.size()-1);
    solveLarge(s, ret);
  }
  else {
    ret.push_back(0);
    s = s.substr(0, s.size()-1);
    solveSmall(s, ret);
  }
}

void solveLarge(string s, vector<int>& ret) {
  if(s.length() == 1) {
    ret.push_back(0);
    return;
  }
  char lowest = s[0];
  for(int i = 1; i < s.length(); i++) {
    lowest = max(lowest, s[i]);
  }
  if(s[s.size()-1] == lowest) {
    ret.push_back(1);
    s = s.substr(0, s.size()-1);
    solveSmall(s, ret);
  }
  else {
    ret.push_back(0);
    s = s.substr(0, s.size()-1);
    solveLarge(s, ret);
  }
}



int main() {
  string s;
  cin >> s;
  vector<int> ret;
  solveSmall(s, ret);
  reverse(ret.begin(), ret.end());
  for(int x: ret) {
    printf("%d ", x);
  }
  printf("\n");
}