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
  int n,m;
  cin >> n >> m;
  vector<vector<int>> sr(m);
  vector<int> s(n),r(n),k(m,0),no(m,0);
  for(int i=0;i<n;i++){
    cin >> s[i] >> r[i];
    s[i]--;
    k[s[i]]++;
  }
  list<pair<int,int>> miru;
  for(int i=0;i<m;i++){
    miru.push_back({i,k[i]});
    if(k[i]>0) sr[i]=vector<int>(k[i]);
  }
  for(int i=0;i<n;i++){
    sr[s[i]][no[s[i]]]=r[i];
    no[s[i]]++;
  }
  for(int i=0;i<m;i++){
    sort(all(sr[i]),greater<int>());
    // for(auto it:sr[i]) cout << it << " ";
    // cout << endl;
  }
  int ans=0;
  int total=0;
  vector<int> t(m,0);
  for(int i=1;i<=n;i++){
    for(auto itr=miru.begin();itr!=miru.end();){
      if(itr->second<i){
        total-=t[itr->first];
        auto itr2=itr;
        itr++;
        miru.erase(itr2);
        continue;
      }
      // cout << i SP itr->first << endl;
      if(t[itr->first]+sr[itr->first][i-1]<0){
        total-=t[itr->first];
        auto itr2=itr;
        itr++;
        miru.erase(itr2);
        continue;
      }
      t[itr->first]+=sr[itr->first][i-1];
      total+=sr[itr->first][i-1];
      itr++;
    }
    ans=max(ans,total);
    // cout << total << endl;
  }
  cout << ans << endl;
  return 0;
}