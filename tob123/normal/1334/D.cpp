#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

ll T, N, L, R;
vector<int> res;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N >> L >> R;
    res.resize(R-L+1);
    if(R == N*(N-1)+1){
      res[R-L] = 1;
      R--;
    }
    ll off = -L;
    ll sti = 0;
    for(int i=1; i<N; i++){
      ll nxt = sti+2*(N-i);
      if(nxt >= L && nxt <= R){
        res[nxt+off] = N;
      }
      if(L < nxt){
        if(L == sti){
          res[sti+off] = N;
          L++;
          if(R < L)
            break;
        }
        for(L; L<min(nxt,R+1); L++){
          if(L%2)
            res[L+off] = i;
          else
            res[L+off] = (L-sti)/2+i;
        }
        if(R < L)
          break;
      }
      sti = nxt;
    }
    for(int x : res){
      cout << x << " ";
    }
    cout << endl;
  }
}