#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
typedef long double ld;
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
const int MX = 3e5 + 5;
#define MAXN 200005
#define MAXE 400010
#define  INF (1<<29)

int main() {
  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    string s; cin >> s;
    int numTot = 0;
    vector<ll> open(n+1);
    vector<int> pref(n+1);
    ll ans = 1e18;
    for(int i=1;i<=n;i++) {
      open[i] = open[i-1];
      pref[i] = pref[i-1] + (s[i-1] == '*');
      if(s[i-1] != '*') open[i] += i;
      if(s[i-1] == '*') ++numTot;
    }
    if(numTot == 0) {
      cout << 0 << "\n";
      continue;
    }
    for(int st=1;st<=n-numTot+1;st++) {
      int en = st + numTot - 1;// [st..en]
      int numLeft = pref[st-1];
      int numRight = pref[n] - pref[en];
      ll sumLeft = (st*1LL*(st-1))/2 -open[st-1];
      ll sumRight = (n-en)*1LL*(en+1+n)/2 - (open[n] - open[en]);
      int lo = st, hi = en;
      for(int j=0;j<30;j++) {
        int mid = (lo+hi)/2;
        int numOpen = mid - st + 1 - (pref[mid] - pref[st-1]);
        if(numOpen < numLeft) {
          lo = mid + 1;
        }
        else hi = mid;
      }
      ans = min(ans, open[lo] - open[st-1] - sumLeft + sumRight - open[en] + open[lo]);
    }
    cout << ans << "\n";
  }
}