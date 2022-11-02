#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int n = 1e6+10;

int nxt[2][20][n];
int cnt[2][n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N;
  string S;
  cin >> N >> S;
  for(int i=0; i<2; i++){
    for(int j=0; j<20; j++){
      for(int k=0; k<n; k++){
        nxt[i][j][k] = -1;
      }
    }
  }
  for(int i=0; i<N; i++){
    cnt[0][i+1] = cnt[0][i];
    cnt[1][i+1] = cnt[1][i];
    if(S[i] != '?'){
      nxt[S[i]-'0'][0][i] = i;
      cnt[S[i]-'0'][i+1]++;
    }
  }
  for(int a=0; a<2; a++){
    for(int i=1; i<20; i++){
      for(int j=0; j<N; j++){
        nxt[a][i][j] = nxt[a][i-1][j];
        if(j < N-(1<<(i-1)) && nxt[a][i-1][j+(1<<(i-1))] != -1)
          nxt[a][i][j] = nxt[a][i-1][j+(1<<(i-1))];
      }
    }
  }
  /*
  for(int i=0; i<2; i++){
    for(int j=0; j<4; j++){
      for(int k=0; k<N; k++)
        cout << nxt[i][j][k] << " ";
      cout << endl;
    }
    cout << endl;
  }
  */
  for(int l=1; l<=N; l++){
    //cout << "start len " << l << endl;
    int ind = 0;
    int res = 0;
    int st = (int) log2(l);
    while(ind < N-l+1){
      //cout << "ind: " << ind << endl;
      int sum0 = cnt[0][ind+l]-cnt[0][ind];
      int sum1 = cnt[1][ind+l]-cnt[1][ind];
      if(sum0 == 0 || sum1 == 0){
        //cout << "++" << endl;
        res++;
        ind += l;
      }
      else{
        int n0 = nxt[0][st][ind];
        int n1 = nxt[1][st][ind];
        //cout << "ns: " << n0 << " " << n1 << endl;
        int jmp = n0 != -1 && n1 != -1 ? min(n0,n1) : max(n0,n1);
        if(jmp != -1)
          ind = jmp+1;
        else{
          ind += 1<<st;
        }
      }
    }
    cout << res << " ";
    //cout << endl;
  }
  cout << endl;
}