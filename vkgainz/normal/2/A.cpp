#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
#define vi vector<int>
#define vvi vector<vector<int>>
#define pb push_back
#define mp make_pair
const int MX = 3e6+5;
int main() {
  int n; cin >> n;
  map<string, int> pt;
  map<string, int> en;
  vector<pair<string, int>> in(n);
  for(int i=0;i<n;i++) {
    string s; int x; cin >> s >> x;
    pt[s] += x;
    in[i].f = s, in[i].s = x;
  }
  string ans;
  int score =0 ;
  for(auto &it : pt) {
    if(it.s > score) {
      score= it.s;
    }
  }
  en = pt;
  pt.clear();
  for(int i=0;i<n;i++) {
    pt[in[i].f] += in[i].s;
    if(pt[in[i].f] >= score && en[in[i].f] == score) {
      ans = in[i].f;
      break;
    }
  }
  cout << ans << "\n";
}