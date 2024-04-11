#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
string S;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> S;
    string newS = "";
    int ep=0, op=0;
    for(int i=0; i<sz(S); i++){
      while(ep < sz(S) && (S[ep]-'0')%2 == 1){
        ep++;
      }
      while(op < sz(S) && (S[op]-'0')%2 == 0){
        op++;
      }
      if(op == sz(S)){
        newS.push_back(S[ep]);
        ep++;
      }
      else if(ep == sz(S)){
        newS.push_back(S[op]);
        op++;
      }
      else{
        if(S[ep] < S[op]){
          newS.push_back(S[ep]);
          ep++;
        }
        else{
          newS.push_back(S[op]);
          op++;
        }
      }
    }
    cout << newS << "\n";
  }

  return 0;
}