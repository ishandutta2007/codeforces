#include <bits/stdc++.h>
using namespace std;

int N;
int a[100002];

int main(){
  ios_base::sync_with_stdio(false);
  cin >> N;
  for(int i=0; i<N; i++){
    cin >> a[i];
  }
  int res=0;
  for(int i=0; i<N; i++){
    res = max(res, min(a[i]-1, 1000000-a[i]));
  }
  cout << res << endl;

  return 0;
}