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
  int ku=0;
  for(int i=0;i<n;i++){
    if(s[i]=='G'){
      if(!ok){
        ku++;
        ok=true;
      }
    }else{
      ok=false;
    }
  }
  vector<int> aaa(3*n,0);
  int idx=0;
  int count=0;
  int now=1;
  for(int i=0;i<n;i++){
    if(s[i]=='G'){
      if(now){
        count++;
      }else{
        aaa[idx]=count;
        idx++;
        now=1;
        count=1;
      }
    }else{
      if(now){
        aaa[idx]=count;
        idx++;
        now=0;
        count=1;
      }else{
        count++;
      }
    }
  }
  aaa[idx]=count;
  idx++;
  int ans=0;
  // for(int i=0;i<idx;i++){
  //   cout << aaa[i] << " ";
  // }
  // cout << endl;
  if(ku==0){
    cout << 0 << endl;
  }else if(ku==1){
    for(int i=0;i<idx;i+=2){
      ans=max(ans,aaa[i]);
    }
    cout << ans << endl;
  }else if(ku==2){
    if(aaa[0]==0){
      if(aaa[3]==1){
        cout << aaa[2]+aaa[4] << endl;
      }else{
        cout << max(aaa[2],aaa[4])+1 << endl;
      }
    }else{
      if(aaa[1]==1){
        cout << aaa[0]+aaa[2] << endl;
      }else{
        cout << max(aaa[0],aaa[2])+1 << endl;
      }
    }
  }else{
    for(int i=0;i<idx;i+=2){
      ans=max(ans,aaa[i]+1);
    }
    for(int i=1;i<idx;i+=2){
      if(aaa[i]==1) ans=max(ans,aaa[i-1]+aaa[i+1]+1);
    }
    cout << ans << endl;
  }
  return 0;
}