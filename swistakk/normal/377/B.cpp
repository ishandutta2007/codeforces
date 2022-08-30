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
const int N = 1001 * 1001;
pair<ll, int> a[N];
ll b[N], c[N];
pair<pair<ll, ll>, int> stud[N];
int act_skoj[N];
int res_skoj[N];
int wol[N];
int main()
{
  // nie zapomnij o ll
  ios_base::sync_with_stdio(0);
  ll s, n, m;
  cin>>n>>m>>s;
  for (int i = 1; i <= m; i++) {
    int tmp;
    cin>>tmp;
    a[i] = MP(tmp, i);
  }
  for (int i = 1; i <= n; i++) {
    cin>>b[i];
  }
  for (int i = 1; i <= n; i++) {
    cin>>c[i];
    stud[i] = MP(MP(b[i], c[i]), i);
  }
  
  sort(a + 1, a + 1 + m);
  sort(stud + 1, stud + 1 + n);
  /* if (a[m].first > stud[n].first.first) {
    cout<<"NO\n";
    return 0;
  } */
  bool ok = false;
  int kl = 1, kp = m, aktc;
  while (kl <= kp) {
    aktc = (kl + kp) / 2;
    /* for (int i = 1; i <= n; i++) {
      wol[i] = aktc;
    } */
    set<pair<int, int> > secik;
    int act_stud = n + 1;
    ll passes = 0;
    int credits = 0;
    int lolol = 0;
    for (int i = m; i >= 1; i--) {
      while (act_stud > 1 && stud[act_stud - 1].first.first >= a[i].first) {
        act_stud--;
        secik.insert(MP(stud[act_stud].first.second, stud[act_stud].second));
      }
      if (credits) {
        credits--;
        act_skoj[a[i].second] = lolol;
        continue;
      }
      pair<int, int> rob;
      if (secik.empty()) {
        passes = s + 1;
        goto A;
      }
      rob = *secik.begin();
      passes += rob.first;
      credits = aktc - 1;
      secik.erase(secik.begin());
      lolol = rob.second;
      act_skoj[a[i].second] = rob.second;
    }
    A: ;
    //cout<<aktc<<" "<<passes<<endl;
    if (passes <= s) {
      ok = true;
      kp = aktc - 1;
      for (int i = 1; i <= m; i++) {
        res_skoj[i] = act_skoj[i];
      }
    } else {
      kl = aktc + 1;
    }
  }
  if (!ok) {
    cout<<"NO\n";
    return 0;
  }
  cout<<"YES\n";
  for (int i = 1; i <= m; i++) {
    cout<<res_skoj[i]<<" ";
  }
  cout<<endl;
    
    
    
    
    
    
    
    
  // nie zapomnij o ll
  return 0;
}