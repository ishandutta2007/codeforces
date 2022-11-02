#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int totalG;
vector<int> cnt;
vector<bool> g;

int main(){
  cin >> N >> S;
  bool gold = true;
  g.push_back(true);
  cnt.push_back(0);
  for(char c : S){
    if(c == 'G'){
      totalG++;
      if(gold){
        cnt[cnt.size()-1]++;
      }
      else{
        cnt.push_back(1);
        gold = true;
        g.push_back(true);
      }
    }
    else{
      cnt.push_back(1);
      gold = false;
      g.push_back(false);
    }
  }
  g.push_back(false);
  cnt.push_back(0);
  g.push_back(true);
  cnt.push_back(0);
  int best = 0;
  for(int i=1; i<cnt.size(); i++){
    if(!g[i]){
      best = max(best, 1 + (g[i-1] ? cnt[i-1] : 0) + (g[i+1] ? cnt[i+1] : 0));
    }
  }
  best = min(best, totalG);
  cout << best << endl;

  return 0;
}