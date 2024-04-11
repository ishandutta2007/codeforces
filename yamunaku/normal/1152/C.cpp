#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define SP <<" "<<
#define MOD 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000

typedef long long LL;
typedef long double LD;

int main(){
  LL a,b;
  cin >> a >> b;
  LL k=abs(b-a);
  if(k==0){
    cout << 0 << endl;
    return 0;
  }
  vector<pair<LL,int>> p;
  for(LL i=2;i*i<=k;i++){
    if(k%i==0){
      int c=0;
      while(k%i==0){
        c++;
        k/=i;
      }
      p.push_back({i,c});
    }
  }
  if(k>1){
    p.push_back({k,1});
  }
  set<LL> st;
  st.insert(1);
  for(int i=0;i<p.size();i++){
    queue<LL> q;
    for(auto &x:st){
      LL tmp=x;
      for(int j=1;j<=p[i].second;j++){
        tmp*=p[i].first;
        q.push(tmp);
      }
    }
    while(!q.empty()){
      st.insert(q.front());
      q.pop();
    }
  }
  LL miv=LINF;
  int ans=0;
  for(auto &x:st){
    if(a%x==b%x){
      LL tmp,ta;
      if(a%x==0){
        tmp=a/x*b;
        ta=0;
      }else{
        tmp=(a/x+1)*(b/x+1)*x;
        ta=x-a%x;
      }
      if(miv>tmp){
        miv=tmp;
        ans=ta;
      }
    }
  }
  cout << ans << endl;
  return 0;
}