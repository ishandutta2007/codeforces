#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 300;

int N;
int F[n], T[n], B[n];
vector<int> to[n];
bool vis[n];
bool doTests[n];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(int i=0; i<N; i++){
    int b;
    for(int j=0; j<3; j++){
      cin >> b;
      F[i] *= 2;
      F[i] += b;
    }
  }
  for(int i=0; i<N; i++){
    int b;
    for(int j=0; j<3; j++){
      cin >> b;
      T[i] *= 2;
      T[i] += b;
    }
  }
  vis[0] = true;
  B[0] = F[0];
  for(int x=0; x<10; x++){
  for(int i=0; i<N; i++){
    if(vis[i])
      continue;
    for(int j=0; j<N; j++){
      if(vis[j] && B[j] == F[i]){
        vis[i] = true;
        to[j].push_back(i);
        doTests[i] = true;
        B[i] = F[i] & T[i];
        goto END;
      }
    }
    for(int j=0; j<N; j++){
      for(int k=j+1; k<N; k++){
        if(vis[j] && vis[k] && (B[j]|B[k]) == F[i]){
          vis[i] = true;
          to[j].push_back(i);
          to[k].push_back(i);
          doTests[i] = false;
          B[i] = F[i];
          goto END;
        }
      }
    }
    END: ;
  }
  }
  bool res = true;
  int cnt = 0;
  for(int i=0; i<N; i++){
    res &= vis[i];
    cnt += sz(to[i]);
  }
  if(res){
    cout << "Possible\n";
    for(int i=0; i<N; i++){
      cout << doTests[i] << " ";
    }
    cout << endl;
    cout << cnt << endl;
    for(int i=0; i<N; i++){
      for(int x : to[i]){
        cout << i+1 << " " << x+1 << "\n";
      }
    }
  }
  else{
    cout << "Impossible\n";
  }

  return 0;
}