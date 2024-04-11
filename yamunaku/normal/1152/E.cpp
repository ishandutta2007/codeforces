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
  int n;
  cin >> n;
  vector<int> b(n-1),c(n-1);
  for(int i=0;i<n-1;i++) cin >> b[i];
  for(int i=0;i<n-1;i++) cin >> c[i];
  map<int,list<pair<int,int>>> e;
  for(int i=0;i<n-1;i++){
    e[b[i]].push_back({c[i],i});
    e[c[i]].push_back({b[i],i});
    if(b[i]>c[i]){
      cout << -1 << endl;
      return 0;
    }
  }
  int s=e.begin()->first,co=0;
  for(auto &p:e){
    if(p.second.size()%2){
      s=p.first;
      co++;
      if(co>2){
        cout << -1 << endl;
        return 0;
      }
    }
  }

  vector<bool> usd(n-1,false);
  list<int> ans;
  ans.push_back(s);

  auto now=ans.begin();
  while(now!=ans.end()){
    if(e[*now].size()>0){
      auto last=now;
      last++;
      int pos=*now;
      while(e[pos].size()>0){
        auto itr=e[pos].begin();
        while(1){
          if(e[pos].size()==0) goto next;
          if(!usd[itr->second]) break;
          itr=e[pos].erase(itr);
        }
        int past=pos;
        pos=itr->first;
        ans.insert(last,pos);
        usd[itr->second]=true;
        e[past].erase(itr);
      }
      next:;
    }
    now++;
  }
  
  if(ans.size()<n){
    cout << -1 << endl;
    return 0;
  }
  for(auto &x:ans){
    cout << x << " ";
  }
  cout << endl;
  return 0;
}