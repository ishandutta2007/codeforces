#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

int T, N, MM;
vector<int> A;
vector<pii> B, H;
map<int,int> M;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cin >> N;
    A.resize(N);
    int m = 0;
    for(int i=0; i<N; i++){
      cin >> A[i];
      m = max(m, A[i]);
    }
    cin >> MM;
    B.resize(MM);
    bool pos = false;
    for(int i=0; i<MM; i++){
      cin >> B[i].second;
      cin >> B[i].first;
      if(B[i].second >= m)
        pos = true;
    }
    sort(B.rbegin(), B.rend());
    M.clear();
    H.clear();
    H.push_back(B[0]);
    M[H[0].first] = H[0].second;
    int ind2 = 0;
    for(int i=1; i<MM; i++){
      if(B[i].first > H[ind2].first || B[i].second > H[ind2].second){
        H.push_back(B[i]);
        M[B[i].first] = B[i].second;
        ind2++;
      }
    }
    if(!pos){
      cout << -1 << "\n";
      continue;
    }
    int cnt = 0;
    int endur = 0, pw = 0;
    for(int ind=0; ind<N;){
      endur++;
      pw = max(pw, A[ind]);

      auto it = M.lower_bound(endur);
      /*
      if(it != M.end()){
        cout << endur << " " << pw << ": " << it->first << " " << it->second << endl;
      }
      else{
        cout << endur << " " << pw << ": -" << endl;
      }
      */
      if(it == M.end())
        pos = false;
      else if(it->second < pw)
        pos = false;
      else
        pos = true;
      
      if(pos){
        ind++;
      }
      else{
        cnt++;
        endur = 0;
        pw = 0;
      }
    }
    cnt++;
    cout << cnt << endl;
  }

  return 0;
}