#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fst first
#define snd second
#define x first
#define y second
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << (x) << endl;
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

const int MN = 2e5 + 5;

int N;
int A[MN];

int solve(int s, int e, int bit) {
  if (bit < 0) return 0;

  int l = s, r = e, mid;
  int p = -1;
  while(l <= r) {
    mid = (l+r)/2;
    if(A[mid] & (1 << bit)) {
      p = mid;
      r = mid-1;
    }
    else l = mid+1;
  }
  if (p == -1 || p == s) {
    return solve(s, e, bit-1);
  }

  int n0 = p-s;
  int n1 = (e-p+1);
  int v1 = solve(s, p-1, bit-1) + (n1-1);
  int v2 = solve(p, e, bit-1) + (n0-1);
  return min(v1, v2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A, A+N);
  writeln(solve(0, N-1, 29));
  return 0;
}