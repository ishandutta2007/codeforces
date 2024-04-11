#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

string S;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> S;
  vector<vector<int>> res;
  for(int i=0; i<sz(S); i++){
    vector<int> cur;
    int l=0, r=sz(S)-1;
    while(l < r){
      while(l < r && S[l] != '(') l++;
      while(l < r && S[r] != ')') r--;
      if(S[l] == '(' && S[r] == ')'){
        S[l] = '.';
        S[r] = '.';
        cur.push_back(l+1);
        cur.push_back(r+1);
      }
    }
    if(sz(cur))
      res.push_back(cur);
    else
      break;
  }
  cout << sz(res) << endl;
  for(auto v : res){
    cout << sz(v) << endl;
    sort(v.begin(), v.end());
    for(int x : v){
      cout << x << " ";
    }
    cout << endl;
  }

  return 0;
}