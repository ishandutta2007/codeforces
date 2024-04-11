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

using namespace std;

typedef long long ll;

ll nwd(ll a, ll b) {
  //cout<<"jestem nwd "<<a<<" "<<b<<endl;
  if (b > a) {
    return nwd(b, a);
  }
  if (b == 0) {
    return a;
  }
  return nwd(b, a%b);
}

const int N = 100005;

ll a[N];
ll b[N];
bool sito[N];
ll pow(ll a, ll b, ll p) {
  ll act = 1;
  ll act_pow = a;
  while (b) {
    if (b & 1) {
      act *= act_pow;
      act %= p;
    }
    act_pow *= act_pow;
    act_pow %= p;
    b /= 2;
  }
  return act;
}

int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  ll n, m, p;
  cin>>n>>m>>p;
  for (int i = 1; i <= n; i++) {
    cin>>a[i];
  }
  ll d = p - 1;
  for (int i = 1; i <= m; i++) {
    cin>>b[i];
    d = nwd(d, b[i]);
  }
  vector<ll> dz;
  for (int i = 1; i * i <= p - 1; i++) {
    if ((p - 1) % i == 0) {
      dz.PB(i);
      //is_ord.PB(0);
    }
  }
  int tmp_s = dz.size();
  for (int i = tmp_s - 1; i >= 0; i--) {
    if (dz[i] * dz[i] < p - 1) {
      dz.PB((p - 1) / dz[i]);
      //is_ord.PB(0);
    }
  }
  vector<ll> lp;
  vector<ll> lpd;
  map<ll, bool> is_ord;
  for (ll i = 2; i * i <= p - 1; i++) {
    if (sito[i] == 0) {
      lp.PB(i);
      for (ll j = 2; i * i * j * j <= p - 1; j++) {
        sito[i * j] = 1;
      }
    }
  }
  ll tmp = p - 1;
  //vector<ll> is_ord;
  for (int i = 0; i < lp.size(); i++) {
    if ((p - 1) % lp[i] == 0) {
      lpd.PB(lp[i]);
    }
    while (tmp % (lp[i]) == 0) {
      tmp /= lp[i];
    }
  }
  
  if (tmp > 1) {
    lpd.PB(tmp);
  }
  ll wyn = 0;
  bool is_zero = 0;
  /* for (int i = 0; i < lpd.size(); i++) {
    cout<<lpd[i]<<" ";
  }
  cout<<endl; */
  for (int i = 1; i <= n; i++) {
    if (a[i] % p ==  0) {
      is_zero = true;
      wyn = 1;
      continue;
    }
    ll ord = p - 1;
    for (int j = 0; j < lpd.size(); j++) {
      while (ord % lpd[j] == 0 && pow(a[i], ord / lpd[j], p) == 1) {
        ord /= lpd[j];
      }
    }
    //cout<<a[i]<<" ma mod "<<p<<" rzad rowny "<<ord<<endl;
    is_ord[nwd(p - 1, (((p - 1) * d) / ord) % (p - 1))] = 1;
    //cout<<"i bierzemy "<<nwd(p - 1, (((p - 1) * d) / ord) % (p - 1))<<endl;
  }
  
  //ll free = p - 1;
  vector<bool> important;
  vector<ll> how_many;
  for (int i = 0; i < dz.size(); i++) {
    important.PB(false);
    //parity.PB(how_many);
    how_many.PB(0);
  }
  for (int i = 0; i < dz.size(); i++) {
    if (is_ord[dz[i]] && !important[i]) {
      for (int j = i; j < dz.size(); j++) {
        if (dz[j] % dz[i] == 0) {
          important[j] = true;
        }
      }
    }
    if (important[i]) {
      wyn += (1 - how_many[i]) * (p - 1) / dz[i];
      //cout<<dz[i]<<" "<<1 - how_many[i]<<endl;
    
      ll add = 1 - how_many[i];
      how_many[i] = 1;
      for (int j = i + 1; j < dz.size(); j++) {
        //wyn -= how_many[i] * (p - 1) / dz[i];
        if (dz[j] % dz[i] == 0) {
          how_many[j] += add;
        }
      }
    }
  }
  cout<<wyn<<endl;
        
        
  
  // nie zapomnij o ll
  return 0;
}