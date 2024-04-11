#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define endl '\n'

const ll ms = 1e5+5;

ll n;
vector<ll> vec(ms), ans(ms);

vector<ll> freq(ms);
ll id = 0;
ll solve(ll k){
  ll res = 1;
  id++;

  ll count = 0;

  for(int i = 1 ; i <= n ; i++){
    if(freq[vec[i]] != id){
      freq[vec[i]] = id;
      count++;
    }

    if(count > k){
      res++;
      id++;
      count = 0;
      i--;
    }
  }

  return res;
}

void busca(ll l, ll r, ll rl, ll rr){
  if(rl == rr || l == r){
    for(int i = l ; i <= r ; i++) ans[i] = rl;
    return;
  }
  ll m = (l+r+1)/2;
  ll s1 = solve(m);
  busca(l, m-1, rl, s1);
  busca(m, r, s1, rr);
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);

  cin >> n;

  for(int i = 1 ; i <= n ; i++) cin >> vec[i];
  
  ans[1] = solve(1);
  ans[n] = 1;

  busca(1, n, ans[1], ans[n]);
  
  for(int i = 1 ; i <= n ; i++) cout << ans[i] << " ";
  cout << endl;

  return 0;
}