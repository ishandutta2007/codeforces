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
#define f first
#define s second
typedef vector<int> vi;
// END NO SAD

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void usacoio(string s) {
  freopen((s+".in").c_str(), "r", stdin);
  freopen((s+".out").c_str(), "w", stdout);
}

bool on[1005];
int n, want;
bool done() {
  int have = 0;
  for(int i = 1; i <= n; i++) {
    have += on[i];
  }
  return have == want;
}
void turnoff(int k, int lastsize) {
  for(int a = 0; a < lastsize; a++) {
    int flip = k + a;
    while(flip > n) flip -= n;
    on[flip] = false;
  }
}

int get(int sizegroup) {
	vector<bool> can(n);
	for(int i = 0; i < sz(can); i++) {
		if(i % sizegroup == sizegroup-1) continue;
		can[i] = true;
	}
	can[sz(can)-1] = false;
	int amt = 0;
	for(bool out: can) amt += out;
	return amt - (sizegroup-1);
}

void solve() {
  cin >> n;
	want = 0;
  int sizegroup = n-1;
	for(int cand = n-1; cand > 0; cand--) {
		int gain = get(cand);
		if(gain > want) {
			sizegroup = cand;
      want = gain;
		}
	}
  while(!done()) {
    vector<int> turnon;
    for(int i = 1; i <= n && sz(turnon) < sizegroup; i++) {
      if(i%sizegroup == 0) continue;
      if(on[i]) continue;
      turnon.push_back(i);
      on[i] = true;
    }
    cout << sz(turnon);
    for(int out: turnon) cout << " " << out;
    cout << endl;
    int off;
    cin >> off;
    turnoff(off, sz(turnon));
  }
  cout << 0 << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}