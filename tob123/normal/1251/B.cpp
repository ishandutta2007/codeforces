#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int Q, N;
string S[100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> Q;
  while(Q--){
    cin >> N;
    int cntO = 0;
    for(int i=0; i<N; i++){
      cin >> S[i];
      if(S[i].size()%2)
        cntO++;
    }
    int cnt1 = 0;
    int cnt0 = 0;
    for(int i=0; i<N; i++){
      for(char c : S[i]){
        if(c == '1')
          cnt1++;
        else
          cnt0++;
      }
    }
    cnt1 %= 2;
    cnt0 %= 2;
    int cntG = cnt0+cnt1;
    if(cntG > cntO){
      cout << N-1 << "\n";
    }
    else{
      cout << N << "\n";
    }
  }

  return 0;
}