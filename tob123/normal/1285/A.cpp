#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int N;
string S;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  cin >> S;
  int cntl=0, cntr=0;
  for(int i=0; i<N; i++){
    if(S[i] == 'L')
      cntl++;
    else
      cntr++;
  }
  cout << cntl+cntr+1 << endl;

  return 0;
}