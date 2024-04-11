#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL n;
  cin >> n;
  vector<LL> l(n),r(n),x(5*n);
  for(int i=0;i<n;i++){
    cin >> l[i] >> r[i];
    x[5*i]=l[i]-1;
    x[5*i+1]=l[i];
    x[5*i+2]=l[i]+1;
    x[5*i+3]=r[i];
    x[5*i+4]=r[i]+1;
  }
  sort(x.begin(),x.end());
  x.erase(unique(x.begin(),x.end()),x.end());
  map<LL,LL> zip;
  vector<LL> unzip(x.size());
  for(int i=0;i<x.size();i++){
    zip[x[i]]=i;
    unzip[i]=x[i];
    // cout << i << ":" << x[i] << endl;
  }
  vector<LL> c(x.size(),0);
  for(int i=0;i<n;i++){
    c[zip[l[i]]]++;
    if(zip[r[i]]<x.size()-1){
      c[zip[r[i]]+1]--;
    }
    //cout << zip[l[i]] << "," << zip[r[i]] << endl;
  }
  // for(int i=0;i<x.size();i++){
  //   cout << c[i] << " ";
  // }
  // cout << endl;
  for(int i=1;i<x.size();i++){
    c[i]=c[i]+c[i-1];
  }
  // for(int i=0;i<x.size();i++){
  //   cout << c[i] << " ";
  // }
  // cout << endl;
  vector<LL> ans(n+1,0);
  for(int i=0;i<x.size()-1;i++){
    ans[c[i]]+=unzip[i+1]-unzip[i];
  }
  ans[c[x.size()-1]]++;
  for(int i=1;i<n;i++){
    cout << ans[i] << " ";
  }
  cout << ans[n] << endl;

  return 0;
}