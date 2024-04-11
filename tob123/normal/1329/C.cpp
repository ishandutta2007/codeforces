#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = (1<<22) + 10;

int T;
ll H, G;
int A[n];
int cnt[n];
int pos[n];

void p(int* x){
  for(int i=1; i<(1<<H); i++){
    cout << x[i] << " ";
  }
  cout << endl << endl;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  vector<int> R;
  while(T--){
    cin >> H >> G;
    for(int i=1; i<(1<<H); i++){
      cin >> A[i];
    }
    for(int i=1<<H; i<(1<<(H+1)); i++)
      A[i] = 0;
    for(int i=1<<G; i<1<<H; i++){
      cnt[i] = 1;
    }
    for(int i=(1<<(H-1))-1; i>=1; i--){
      cnt[i] += cnt[2*i] + cnt[2*i+1];
    }
    R.clear();
    //for(int i=0; i<(1<<H)-(1<<G); i++){
    while(cnt[1]){
      int st = 1;
      int cur = 1;
      while(true){
        int nxt = 1;
        if(A[2*cur] == 0 && A[2*cur+1] == 0){
          break;
        }
        else if(A[2*cur] > A[2*cur+1]){
          nxt = 0;
        }
        if(cnt[2*cur+nxt]){
          cur = 2*cur+nxt;
        }
        else{
          st = 2*cur+1-nxt;
          cur = 2*cur+1-nxt;
        }
      }
      R.push_back(st);
      int x = cur;
      while(x > st){
        pos[x/2] = A[x];
        x /= 2;
      }
      A[cur] = 0;
      while(cur >= 1){
        if(pos[cur]){
          A[cur] = pos[cur];
          pos[cur] = 0;
        }
        cnt[cur]--;
        cur /= 2;
      }
      //p(cnt);
      //p(A);
    }
    ll sum = 0;
    for(int i=1; i<1<<G; i++){
      sum += A[i];
    }
    cout << sum << "\n";
    for(int x : R){
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}