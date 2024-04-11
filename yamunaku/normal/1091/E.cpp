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
  vector<LL> a(n),r(n+1),b(n);
  LL total=0;
  for(int i=0;i<n;i++) scanf("%lld",&a[i]);
  sort(all(a),greater<LL>());
  for(int i=0;i<n;i++) b[i]=a[n-i-1],total+=b[i];
  r[0]=0;
  for(int i=1;i<=n;i++){
    r[i]=r[i-1]+a[i-1];
  }
  LL k=n;
  stack<pair<LL,int>> st;
  pair<LL,int> p;
  int pos;
  LL sg;
  bool okflag=false;
  for(int i=n-1;i>=0;i--,k--){
    pos=n-1-distance(b.begin(),lower_bound(all(b),k));
    if(pos<i){
      sg=r[n]-r[i];
    }else{
      sg=r[n]-r[pos+1]+(pos-i+1)*k;
    }
    p={k*(k-1)+sg-r[i],i};
    // cout << k*(k-1)+sg-r[i] << " ";
    if(st.empty()){
      st.push(p);
    }else if(p<st.top()){
      st.push(p);
    }
  }
  // cout << endl;
  vector<LL> left(n);
  vector<bool> ok(n,false);
  k=1;
  for(int i=0;i<n;i++,k++){
    pos=n-1-distance(b.begin(),lower_bound(all(b),k));
    if(pos<i){
      sg=r[n]-r[i+1];
    }else{
      sg=r[n]-r[pos+1]+(pos-i)*k;
    }
    left[i]=r[i+1]-k*(k-1)-sg;
    // cout << left[i] << " ";
    if(k>=left[i]) ok[i]=true;
    if(i>0) ok[i]=ok[i]&ok[i-1];
  }
  // cout << endl;
  // cout << r[3] SP (k-1)*(k-2) SP sg << endl;
  int now=0;
  LL ld=-INF;
  set<LL> ans;
  for(int x=n-n%2+total%2;x>=0;x-=2){
    while(now<n){
      if(x>a[now]) break;
      now++;
    }
    while(!st.empty()){
      if(now<=st.top().second) break;
      st.pop();
    }
    // cout << x SP st.top().first << endl;
    if(now==0){
      if(x<=st.top().first){
        ans.insert(x);
        okflag=true;
      }
    }else{
      if(st.empty()){
        ld=max(ld,left[now-1]);
        if(ok[now-1]&&ld<=x){
          ans.insert(x);
          okflag=true;
        }
      }else{
        ld=max(ld,left[now-1]);
        if(ok[now-1]&&ld<=x&&x<=st.top().first){
          ans.insert(x);
          okflag=true;
        }
      }
    }
  }
  if(ans.empty()){
    cout << -1 << endl;
    return 0;
  }
  for(auto it:ans){
    printf("%lld ",it);
  }
  printf("\n");
  return 0;
}