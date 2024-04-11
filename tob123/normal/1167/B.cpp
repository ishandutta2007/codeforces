#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

vector<int> x = {4, 8, 15, 16, 23, 42};

int main(){
  vector<int> S(6);
  vector<pair<int,int>> P(6);
  vector<int> res(6);
  for(int b=0; b<6; b+=3){
    for(int a=0; a<2; a++){
      cout << "? " << b+a+1 << " " << b+a+2 << endl;
      cin >> S[b+a];
      for(int i=0; i<x.size(); i++){
        for(int j=i+1; j<x.size(); j++){
          if(x[i] * x[j] == S[b+a])
            P[b+a] = make_pair(x[i], x[j]);
        }
      }
      if(P[b].first == P[b+1].first){
        res[b+0] = P[b+0].second;
        res[b+1] = P[b+0].first;
        res[b+2] = P[b+1].second;
      }
      if(P[b].second == P[b+1].first){
        res[b+0] = P[b+0].first;
        res[b+1] = P[b+0].second;
        res[b+2] = P[b+1].second;
      }
      if(P[b].second == P[b+1].second){
        res[b+0] = P[b+0].first;
        res[b+1] = P[b+0].second;
        res[b+2] = P[b+1].first;
      }
      if(P[b].first == P[b+1].second){
        res[b+0] = P[b+0].second;
        res[b+1] = P[b+0].first;
        res[b+2] = P[b+1].first;
      }
    }
  }
  cout << "!";
  for(int i=0; i<6; i++){
    cout << " " << res[i];
  }
  cout << endl;

  return 0;
}