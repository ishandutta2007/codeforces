#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 3e5+10;

int N;
string S;
int nxta[n], nxtb[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> S;
  nxta[N] = nxtb[N] = nxtb[N+1] = nxta[N+1] = N;
  ll res = 0;
  for(int i=N-1; i>=0; i--){
    if(S[i] == 'A'){
      nxta[i] = i;
      nxtb[i] = nxtb[i+1];
      if(nxta[i+1] != N){
        res += N-nxta[i+1];
        if(nxtb[i] != N && nxtb[i] > nxta[i+1]){
          res--;
        }
      }
    }
    else{
      nxtb[i] = i;
      nxta[i] = nxta[i+1];
      if(nxtb[i+1] != N){
        res += N-nxtb[i+1];
        if(nxta[i] != N && nxta[i] > nxtb[i+1]){
          res--;
        }
      }
    }
  }
  cout << res << endl;

  return 0;
}