#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T;
string S;
bool works[30];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> S;
    char lastC = 0;
    int cnt = 0;
    for(int i=0; i<26; i++){
      works[i] = false;
    }
    for(char c : S){
      if(c == lastC)
        cnt++;
      else{
        if(cnt%2){
          works[lastC-'a'] = true;
        }
        cnt = 1;
        lastC = c;
      }
    }
    if(cnt%2){
      works[lastC-'a'] = true;
    }
    for(int i=0; i<26; i++){
      if(works[i]){
        cout << (char)(i+'a');
      }
    }
    cout << "\n";
  }

  return 0;
}