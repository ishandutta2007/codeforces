#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define abs(a) max((a),-(a))
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define repe(i,n) rep(i,(n)+1)
#define per(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define pere(i,n) rep(i,(n)+1)
#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define RET return 0
#define MOD 1000000007
#define INF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool ok=false;
  for(int i=0;i<n-1;i++){
    if(!ok&&s[i]>s[i+1]){
      ok=true;
    }else{
      printf("%c",s[i]);
    }
  }
  if(ok) printf("%c",s[n-1]);
  printf("\n");
  return 0;
}