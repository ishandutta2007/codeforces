#include <bits/stdc++.h>
using namespace std;

int N;
int maxH, maxW;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    char c;
    int a, b;
    cin >> c >> a >> b;
    if(a > b)
      swap(a, b);
    if(c == '+'){
      maxH = max(maxH, b);
      maxW = max(maxW, a);
    }
    else{
      if(maxH <= b && maxW <= a){
        cout << "YES\n";
      }
      else{
        cout << "NO\n";
      }
    }
  }

  return 0;
}