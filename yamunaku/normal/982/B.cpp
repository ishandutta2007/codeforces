#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct seat{
  int n;
  int w;
};

typedef struct seat se;

int main(){
  int n;
  cin >> n;
  priority_queue<se,vector<se>, function<bool(se,se)>> zero{
    [](se a,se b){ return a.w>b.w; }
  };
  priority_queue<se,vector<se>, function<bool(se,se)>> one{
    [](se a,se b){ return a.w<b.w; }
  };
  int w;
  for(int i=0;i<n;i++){
    cin >> w;
    zero.push({i,w});
  }
  string s;
  cin >> s;
  se now;
  for(int i=0;i<2*n;i++){
    if(s[i]=='0'){
      now = zero.top();
      zero.pop();
      one.push(now);
      cout << now.n+1;
    }else{
      cout << one.top().n+1;
      one.pop();
    }
    if(i<2*n-1) cout << " ";
    else cout << endl;
  }
  return 0;
}