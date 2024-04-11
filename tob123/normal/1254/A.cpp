#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef pair<int,int> pii;

const int n = 1e3+10;

int T;
char res[n][n];
bool A[n][n];
int cnt, R, C, K;

char toC(int x){
  if(x < 10)
    return '0'+x;
  if(x < 36)
    return 'a'+x-10;
  return 'A'+x-36;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  while(T--){
    cnt = 0;
    cin >> R >> C >> K;
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        char a;
        cin >> a;
        A[i][j] = a == 'R';
        if(A[i][j]){
          cnt++;
        }
      }
    }
    int perC = cnt/K;
    int perC2 = cnt/K + 1;
    int b = cnt - perC*K;
    int a = K - b;
    int curC = 0;
    int curCnt = 0;
    //cout << perC << " " << perC2 << " " << a << " " << b << "   " << cnt << endl;
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        if(A[i][j]){
          if((curCnt == perC && curC < a) || (curCnt == perC2 && curC >= a)){
            curCnt = 0;
            curC++;
          }
          curCnt++;
        }
        res[i][j] = toC(curC);
        //cout << curC << " ";
      }
      i++;
      if(i >= R)
        break;
      for(int j=C-1; j>=0; j--){
        if(A[i][j]){
          if((curCnt == perC && curC < a) || (curCnt == perC2 && curC >= a)){
            curCnt = 0;
            curC++;
          }
          curCnt++;
        }
        //cout << curC << " ";
        res[i][j] = toC(curC);
      }
    }
    for(int i=0; i<R; i++){
      for(int j=0; j<C; j++){
        cout << res[i][j];
      }
      cout << endl;
    }
  }


  return 0;
}