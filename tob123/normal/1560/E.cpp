#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

string printS(string s){
  for(char& c : s)
    c += 'a';
  return s;
}

bool verify(string s, string t, vector<char> ord){
  int ind = 0;
  int cur = 0;
  while(sz(s) > 0){
    if(sz(t)-ind < sz(s))
      return false;
    for(int i=0; i<sz(s); i++){
      if(s[i] != t[ind+i])
        return false;
    }
    ind += sz(s);
    string newS;
    for(char c : s){
      if(c != ord[cur])
        newS.push_back(c);
    }
    swap(newS, s);
    cur++;
  }
  return ind == sz(t);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    string t;
    cin >> t;
    vector<int> cnt(26);
    vector<char> ord;
    for(int i=sz(t)-1; i>=0; i--){
      t[i] -= 'a';
      if(cnt[t[i]] == 0)
        ord.push_back(t[i]);
      cnt[t[i]]++;
    }
    reverse(ord.begin(), ord.end());
    int x = 0;
    for(int i=0; i<sz(ord); i++){
      x += cnt[ord[i]]/(i+1);
    }
    string s;
    for(int i=0; i<x; i++){
      s.push_back(t[i]);
    }
    if(verify(s, t, ord)){
      for(char& c : s)
        c += 'a';
      s.push_back(' ');
      for(char c : ord){
        c += 'a';
        s.push_back(c);
      }
      cout << s << "\n";
    }
    else
      cout << -1 << "\n";
  }
}