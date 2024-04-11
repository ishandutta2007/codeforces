#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int R, C;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> R >> C;
  if(R == C && R == 1){
    cout << 0 << endl;
  }
  else if(R <= C){
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        cout << (i+1)*(R+j+1) << " ";
      }
      cout << endl;
    }
  }
  else{
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        cout << (j+1)*(C+i+1) << " ";
      }
      cout << endl;
    }
  }

  return 0;
}