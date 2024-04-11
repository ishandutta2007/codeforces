#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

struct vo{
  int id;
  int c;
  bool operator<(const struct vo &right) const{
    return c<right.c;
  }
};

int main(){
  int n,m;
  cin >> n >> m;
  vector<struct vo> v(n);
  vector<int> par(m,0);
  vector<vector<struct vo>> pv(m,vector<struct vo>(n));
  int p,c;
  for(int i=0;i<n;i++){
    cin >> p >> c;
    if(p==1) par[0]++;
    else{
      p--;
      pv[p][par[p]]={i-par[0],c};
      v[i-par[0]]={i-par[0],c};
      par[p]++;
    }
  }
  sort(v.begin(),v.begin()+n-par[0]);
  for(int i=1;i<m;i++){
    sort(pv[i].begin(),pv[i].begin()+par[i]);
  }
  // for(int i=0;i<n-par[0];i++){
  //   cout << v[i].id << " " << v[i].c << endl;
  // }
  LL ans=1000000000000000,tmp,count;
  for(int i=max(par[0],1);i<=n;i++){
    // cout << "---------------" << i << endl;
    tmp=count=0;
    vector<bool> used(n-par[0],false);
    for(int j=1;j<m;j++){
      // cout << "    " << j+1 << endl;
      for(int k=0;k<par[j]-i+1;k++){
        tmp+=pv[j][k].c;
        used[pv[j][k].id]=true;
        count++;
        // cout << "        " << pv[j][k].c <<endl;
      }
    }
    for(int k=0;par[0]+count<i&&k<n-par[0];k++){
      if(used[v[k].id]) continue;
      else{
        tmp+=v[k].c;
        used[v[k].id]=true;
        count++;
      }
    }
    // cout << tmp << endl;
    if(par[0]+count>=i) ans=min(ans,tmp);
  }
  cout << ans << endl;
  return 0;
}