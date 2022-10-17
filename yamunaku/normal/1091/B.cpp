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
  vector<pair<int,int>> p(n);
  map<pair<int,int>,int> mp;
  vector<bool> used(n);
  for(int i=0;i<n;i++){
    cin >> p[i].first >> p[i].second;
  }
  int a,b;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    mp[{a,b}]=i;
  }
  pair<int,int> np;
  for(auto it:mp){
    for(int i=0;i<n;i++) used[i]=false;
    used[it.second]=true;
    np={p[0].first+it.first.first,p[0].second+it.first.second};
    for(int i=1;i<n;i++){
      auto itr=mp.find({np.first-p[i].first,np.second-p[i].second});
      if(itr==mp.end()) goto next;
      if(used[itr->second]) goto next;
      used[itr->second]=true;
    }
    cout << np.first SP np.second << endl;
    return 0;
    next:
    continue;
  }
  return 0;
}