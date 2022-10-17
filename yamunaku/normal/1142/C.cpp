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
  map<int,int> mp;
  int x,y;
  for(int i=0;i<n;i++){
    cin >> x >> y;
    auto itr=mp.find(x);
    if(itr==mp.end()) mp[x]=y;
    else itr->second=max(itr->second,y);
  }
  n=mp.size();
  vector<pair<LD,LD>> v(n);
  int now=0;
  for(auto &e:mp) v[now]=e,now++;
  stack<pair<int,pair<LD,LD>>> st;
  for(int i=1;i<n;i++){
    LD x=v[i].first,y=v[i].second;
    // cout << x SP y << endl;
    while(!st.empty()){
      LD b=st.top().second.first,c=st.top().second.second;
      if(x*x+b*x+c<=y) st.pop();
      else break;
    }
    int id;
    if(st.empty()) id=0;
    else id=st.top().first;
    LD b,c;
    b=(v[i].second-v[id].second)/(v[i].first-v[id].first)-(v[i].first+v[id].first);
    c=v[i].second-v[i].first*v[i].first-b*v[i].first;
    st.push({i,{b,c}});
    // cout << i SP b SP c << endl;
  }
  cout << st.size() << endl;
  return 0;
}