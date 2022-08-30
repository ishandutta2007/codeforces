#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <utility>
#define MP make_pair
#define PB push_back

typedef long long ll;

using namespace std;

const int N = 22;
const int INF = 1001 * 1001 * 1001;
int pick[N];
int team[N];
int bits[(1 << 21) + 5];
int dp[(1 << 21) + 5];
int s[5 * N];
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  int n;
  cin>>n;
  for (int i = 1; i <= n; i++) {
    cin>>s[i];
  }
  sort(s + 1, s + 1 + n, greater<int>());
  int m;
  cin>>m;
  for (int i = 1; i <= m; i++) {
    char c;
    cin>>c;
    pick[i] = (c == 'p');
    cin>>team[i];
    //cout<<s[i]<<" ";
  }
  //cout<<endl;
  bits[1] = 1;
  for (int i = 1; i <= (1 << 19); i++) {
    bits[2 * i] = bits[i];
    bits[2 * i + 1] = bits[i] + 1;
    /* if (i <= 8) {
      cout<<i<<" "<<bits[i]<<endl;
    } */
  }
  dp[0] = 0;
  for (int i = 1; i < (1 << m); i++) {
    int ruch = m - bits[i] + 1;
    int pos = 0;
    if (team[ruch] == 1) {
      dp[i] = -INF;
    } else {
      dp[i] = INF;
    }
    for (int pot = 1; pot <= i; pot *= 2) {
      pos++;
      if (pot & i) {
        if (team[ruch] == 1) {
          dp[i] = max(dp[i], dp[i - pot] + s[pos] * pick[ruch]);
        } else {
          dp[i] = min(dp[i], dp[i - pot] - s[pos] * pick[ruch]);
        }
        //cout<<s[pos]<<" ";
      }
    }
    //cout<<endl<<i<<" "<<dp[i]<<endl;
  }
  cout<<dp[(1 << m) - 1]<<endl;
  return 0;
}