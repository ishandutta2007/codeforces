#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair
ll mod=1000000007;

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif

  int n,k,m;
  cin>>k>>n>>m;
  vi a(k);
  vi tip(n+1);
  vi ch(n+1);
  vector<vector<pair<int, int>>> plus(k);
  vector<vector<pair<int, int>>> mult(k);
  vector<pair<int,int>> bestset(k);
  for(int i=0; i<k; i++) bestset[i] = mp(0,0);
  for(int i=0; i<k; i++) cin>>a[i];
  vector<pair<double, int>> oper;
  for(int i=1; i<=n; i++) {
      int t, p, b;
      cin>>t>>p>>b;
      p--;
      tip[i] = t;
      ch[i] = p;
      if (t == 1) {
          if (b > bestset[p].first) bestset[p] = mp(b, i);
      }
      else if (t == 2) {
          plus[p].pb(mp(b, i));
      }
      else if (t == 3) {
          mult[p].pb(mp(b, i));
          oper.pb(mp((double) b, i));
      }
  }
  
  for(int i=0; i<k; i++) {
      if(bestset[i].first > a[i]) plus[i].pb(mp(bestset[i].first - a[i], bestset[i].second));
      sort(all(plus[i]));
      reverse(all(plus[i]));
      ll cura = a[i];
      for(int k=0; k<plus[i].size(); k++) {
          double preva = cura;
          cura += plus[i][k].first;
          oper.pb(mp(((double) cura)/preva, plus[i][k].second));
      }
  }
  sort(all(oper));
  reverse(all(oper));
  int useful = oper.size();
  vb setterused(k, false);
  cout<<min(useful, m) <<endl;

  for(int i=0; i<min(useful, m); i++) {
      int ind = oper[i].second;
      if(tip[ind]==1) cout<<ind<<" ";
  }
  for(int i=0; i<min(useful, m); i++) {
      int ind = oper[i].second;
      if(tip[ind]==2) cout<<ind<<" ";
  }
  for(int i=0; i<min(useful, m); i++) {
      int ind = oper[i].second;
      if(tip[ind]==3) cout<<ind<<" ";
  }

}