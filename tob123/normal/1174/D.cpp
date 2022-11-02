#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;

int N, X;
int notP;

void gen(int x){
  if(x == -1)
    return;
  if(x == notP){
    gen(x-1);
    return;
  }
  gen(x-1);
  cout << (1<<x) << " ";
  gen(x-1);
}

int main(){
  cin >> N >> X;
  
  if(X == 0 || X >= (1<<N)){
    notP = -1;
    cout << (1<<N)-1 << endl;
  }
  else{
    for(int i=0; i<N; i++){
      if(X & (1<<i)){
        notP = i;
        break;
      }
    }
    cout << (1<<(N-1))-1 << endl;
  }
  gen(N-1);
  cout << endl;

  return 0;
}