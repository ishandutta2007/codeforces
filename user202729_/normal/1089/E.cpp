/*input
4
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define row first 
#define col second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
// const int N =;

int n;
vector<pair<int,int> > c;

void insert(pair<int,int> a, pair<int,int> b){
  if (a.fi!=b.fi){
    if (a.fi<b.fi) loop(i,a.fi,b.fi) c.push_back({i,a.se});
    else rloop(i,a.fi,b.fi) c.push_back({i,a.se});
  }
  else{
    if (a.se<b.se) loop(i,a.se,b.se) c.push_back({a.fi,i});
    else rloop(i,a.se,b.se) c.push_back({a.fi,i});
  }
}

void buildC(){
    insert({1,1},{1,8});
    rloop(i,8,1){
      if (i%2==0) insert({2,i},{7,i});
      else insert({7,i},{2,i});
    }
    insert({8,1},{8,8});
}

bool inLastRow(pair<int,int> cell){
  return (cell.row==8);  
}

bool inLastCol(pair<int,int> cell){
  return (cell.col==8);  
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    buildC();
    assert(c.size()==64);
    
    auto f = c[n-2];
    
    vector<pair<int,int> > ans;
    loop(i,0,n-2) ans.push_back(c[i]);
    
    // print(f);
    if (inLastRow(f)){
      ans.push_back({8,f.col+1});
      ans.push_back({8,8});
    }
    else if (inLastCol(f)){
      if (f == make_pair(7LL,8LL)){
        ans.pop_back();
        ans.push_back({6,7});
        ans.push_back({8,7});
        ans.push_back({8,8});
      }
      else{
        ans.push_back({f.row+1,8});
        ans.push_back({8,8});
      }
      
    } else{
      ans.push_back({8,f.col});
      ans.push_back({8,8});
    }
    
    assert(ans.size()==n+1);
    for(auto it:ans){
      cout << char('a'+it.se-1) << it.fi << sp;
    }
}