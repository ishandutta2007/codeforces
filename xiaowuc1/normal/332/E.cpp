#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

// BEGIN NO SAD
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;

string message;
string goal;
int keylength;
string selection[2000];
string ret;

string want[2000];
void check(int numones) {
  for(int i = 0; i < numones; i++) want[i] = "";
  for(int i = 0; i < sz(goal); i++) want[i%numones] += goal[i];
  string cand = "";
  int used = 0;
  for(int i = keylength-1; used < numones && i >= 0; i--) {
    if(selection[i] == want[numones-used-1]) {
      used++;
      cand += "1";
    }
    else {
      cand += "0";
    }
  }
  if(used == numones) {
    while(sz(cand) < keylength) cand += "0";
    reverse(all(cand));
    if(sz(ret) == 0 || cand < ret) ret = cand;
  }
}

void solve() {
  getline(cin, message);
  getline(cin, goal);
  cin >> keylength;
  for(int i = 0; i < sz(message); i++) {
    selection[i%keylength] += message[i];
  }
  for(int i = 1; i <= keylength; i++) check(i);
  if(sz(ret) == 0) ret = "0";
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}