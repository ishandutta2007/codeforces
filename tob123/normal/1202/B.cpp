#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const ll INF = 1e9;

string s;
ll ins[10][10];

void fw(){
  for(int k=0; k<10; k++){
    for(int i=0; i<10; i++){
      for(int j=0; j<10; j++){
        ins[i][j] = min(ins[i][j], ins[i][k] + ins[k][j]);
      }
    }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s;
  for(int i=0; i<10; i++){
    for(int j=0; j<10; j++){
      for(int k=0; k<10; k++){
        for(int l=0; l<10; l++){
          ins[k][l] = 2*INF;
        }
      }
      for(int k=0; k<10; k++){
        ins[k][(k+j)%10] = min(ins[k][(k+j)%10], 1ll);
        ins[k][(k+i)%10] = min(ins[k][(k+i)%10], 1ll);
      }
      fw();
      ll res = 0;
      for(int i=0; i<sz(s)-1; i++){
        res += ins[s[i]-'0'][s[i+1]-'0'] - 1;
      }
      if(res >= INF){
        res = -1;
      }
      cout << res << " ";
    }
    cout << "\n";
  }

  return 0;
}