#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N;
vector<int> P;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    P.resize(N);
    for(int i=0; i<N; i++){
      cin >> P[i];
    }
    sort(P.rbegin(), P.rend());
    int g, s, b;
    for(g=1; g<N; g++){
      if(P[g] != P[0])
        break;
    }
    for(s=2*g+1; s<N; s++){
      if(P[s] != P[2*g])
        break;
    }
    for(b=N/2; b>=0; b--){
      if(P[b] != P[N/2])
        break;
    }
    b++;
    if(b <= s || (b-s)<=g){
      g = b = s = 0;
    }
    else{
      b -= s;
      s -= g;
    }
    cout << g << " " << s << " " << b << "\n";
  }

  return 0;
}