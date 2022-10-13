#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
using ll = long long;
const int MX = 2e5+5;
bool isPrime[MX];
vector<int> primes;
ll mod = 1e9 + 7;
ll segSmall[2*MX][90];
void updSmall(int i, int p, int v) {
  segSmall[i+=MX][p] = v;
  while(i>1) {
    i/=2;
    segSmall[i][p] = max(segSmall[2*i][p], segSmall[2*i+1][p]);
  }
}
ll querySmall(int l, int r, int p) { //[l, r)
  l+=MX, r+=MX;
  ll ret = 1;
  while(l<r) {
    if(l%2) ret = max(ret, segSmall[l++][p]);
    if(r%2) ret = max(ret, segSmall[--r][p]);
    l/=2, r/=2;
  }
  return ret; //need to take power of this
}
vector<pair<int, ll>> segLarge[2 * MX]; //stores {lst, num} -> convert to pref later
vector<int> lst(MX);
void put(int i, ll v, int last) {
  pair<int, ll> curr = {last , v};
  segLarge[i+=MX].push_back(curr);
  while(i>1) {
    i/=2;
    segLarge[i].push_back(curr);
  }
}
int n;
ll queryLarge(int l, int r) { //[l, r)
  l+=MX, r+=MX;
  ll ret = 1LL;
  pair<int, ll> query = {l-MX, -1e15};
  while(l<r) {
    if(l%2) {
      auto it = lower_bound(segLarge[l].begin(), segLarge[l].end(), query);
      if(it != segLarge[l].begin()) {
        --it;
        ret *= (*it).s;
        ret %= mod;
      }
      ++l;
    }
    if(r%2) {
      --r;
      auto it = lower_bound(segLarge[r].begin(), segLarge[r].end(), query);
      if(it != segLarge[r].begin()) {
        --it;
        ret *= (*it).s;
        ret %= mod;
      }
    }
    l/=2, r/=2;
  }
  return ret;
}
ll lastAns = 0LL;
int cutoff = sqrt(MX); 
ll getAns(int l, int r) {
  ll ans = 1LL;
  for(int i=0;i<primes.size();i++) {
    if(primes[i] > cutoff) break;
    ans *= querySmall(l, r, i);
    ans %= mod;
  }
  ans *= queryLarge(l, r);
  ans %= mod;
  return ans;
}
int idx[MX];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  //add ios base
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  memset(isPrime, 1, sizeof(isPrime));
  for(int i=2;i<MX;i++) {
    if(isPrime[i]) {
      idx[i] = primes.size();
      primes.push_back(i);
      if(i >= (MX+i-1)/i) continue;
      for(int j=i*i;j<MX;j+=i) {
        isPrime[j] = false;
      }
    }
  }
  //init segSmall and segLarge
  fill(lst.begin(), lst.end(), -1);
  for(int i=0;i<2*MX;i++) {
    for(int j=0;j<90;j++) {
      segSmall[i][j] = 1;
    }
  }
  for(int i=0;i<n;i++) {
    for(int j=2;j<=sqrt(a[i]);j++) {
      if(a[i]%j==0) {
        int x = 1;
        while(a[i]%j==0) {
          a[i]/=j;
          x*=j;
        }
        if(j > cutoff) {
          put(i, x, lst[j]);
        }
        else {
          updSmall(i, idx[j], x);
        }
        lst[j] = i;
      }
    }
    if(a[i]>1) {
      if(a[i] > cutoff) {
        put(i, a[i], lst[a[i]]);
      }
      else {
        updSmall(i, idx[a[i]], a[i]);
      }
      lst[a[i]] = i;
    }
  }
  for(int i=0;i<2*MX;i++) {
    sort(segLarge[i].begin(), segLarge[i].end());
    ll p = 1LL;
    for(int j=0;j<segLarge[i].size();j++) {
      p*=segLarge[i][j].s;
      p%=mod;
      segLarge[i][j].s = p;
    }
  }
  int q; cin >> q;
  while(q--) {
    int x, y; cin >> x >> y;
    ll l = ((ll)lastAns + x)%n + 1, r = ((ll)lastAns + y)%n + 1;
    if(l > r) swap(l, r);
    --l;
    //[l, r)
    ll a = getAns(l, r);
    if(a<0) a+=mod;
    cout << a << "\n";
    lastAns = a%n;
  }
}