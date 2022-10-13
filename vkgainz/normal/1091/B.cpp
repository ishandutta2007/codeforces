#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 1e5+5;

int main() {
  int n; cin >> n;
  vector<pair<int, int>> in(n);
  for(int i=0;i<n;i++) {
    int x, y; cin >> x >> y;
    in[i] = {x,y};
  }
  vector<pair<int, int>> get(n);
  set<pair<int, int>> s;
  for(int i=0;i<n;i++) {
    cin >> get[i].f >> get[i].s;
    s.insert(get[i]);
  }
  vector<pair<int, int>> add(n);
  for(int i=0;i<n;i++) {
    add[i] = {in[0].f-in[i].f, in[0].s-in[i].s};
  }
  int res = 0;
  for(int st=0;st<n;st++) {
    int num = 0;
    for(int i=0;i<n;i++) {
      if(s.count(make_pair(get[st].f+add[i].f, get[st].s+add[i].s)))
        ++num;
    }
    if(num==n)
      res = st;
  }
  cout << in[0].f+get[res].f << " " << in[0].s+get[res].s;
}