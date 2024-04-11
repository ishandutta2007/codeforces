#include <vector>
#include <map>
#include <set>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cmath>
//#include "../myutil.hpp"

typedef long long ll;
using namespace std;
const int INF = 1 << 30;
const double EPS = 1e-8;
int n;
int cur;
multiset<string> sts;

struct Result{
  bool win;
  int f;
  int s;
};

bool operator<(const Result& l, const Result& r){
  if(l.win != r.win) return r.win;
  if(l.f != r.f) return l.f < r.f;
  return l.s > r.s;
}

ostream& operator<<(ostream& stm, const Result& r){
  return stm << r.win << " " << r.f << " " << r.s << endl;
}

map<string, Result> memo;

int p(const string& n){
  int res = 0;
  char mc = 'a';
  for(size_t i = 0; i < n.size(); ++i){
    mc = max(mc, n[i]);
    res += n[i] - 'a' + 1;
  }
  return res * (mc - 'a' + 1) + sts.count(n);
}

Result rec(string& cur){
  if(memo.find(cur) != memo.end()){
    return memo[cur];
  }
  Result con = {false, 0, INF};
  bool found = false;
  for(char c = 'a'; c <= 'z'; ++c){
    string next = cur + c;
    if(sts.find(next) != sts.end()){
      found = true;
      Result cr = rec(next);
      cr.win = !cr.win;
      swap(cr.f, cr.s);
      cr.f += p(next);
      con = max(con, cr);
    }
    next = c + cur;
    if(sts.find(next) != sts.end()){
      found = true;
      Result cr = rec(next);
      cr.win = !cr.win;
      swap(cr.f, cr.s);
      cr.f += p(next);
      con = max(con, cr);
    }
  }
  if(!found){
    Result r = {false, 0, 0};
    //    cout << cur << endl << r;
    memo[cur] = r;
    return r;
  }
  memo[cur] = con;
  return con;
}

int main(){
  cin >> n;
  for(int i = 0; i < n; ++i){
    cur = i;
    string str;
    cin >> str;
    set<string> sset;
    for(size_t j = 0; j < str.size(); ++j){
      for(size_t k = j+1; k <= str.size(); ++k){
    string sub(str.begin() + j, str.begin() + k);
    sset.insert(sub);
      }
    }
    sts.insert(sset.begin(), sset.end());
  }
  string start = "";
  Result res = rec(start);
  cout << (res.win ? "First" : "Second") << endl;
  cout << res.f << " " << res.s << endl;
  return 0;
}