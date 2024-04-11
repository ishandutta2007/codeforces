#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,m;
    cin>>n>>m;
    vector<ll> v[m];
    rep(i,n){
      int x,y;
      cin>>x>>y;
      v[--x].push_back(y);
    }
    rep(i,m)sort(v[i].begin(),v[i].end());
    rep(i,m)reverse(v[i].begin(),v[i].end());
    int cnt[m];
    rep(i,m){
      cnt[i]=v[i].size();
      rep(j,cnt[i]-1){
        v[i][j+1]+=v[i][j];
      }
    }
    ll ret=0;
    set<int> st;
    rep(i,m)st.insert(i);
    rep(i,n){
      ll res=0;
      vector<int> used;
      for(auto j:st){
        if(cnt[j]<i+1)used.push_back(j);
        else if(v[j][i]>0)res+=v[j][i];
      }
      for(auto j:used){
        st.erase(j);
      }
      ret=max(ret,res);
    }
    cout<<ret<<endl;
    return 0;
}