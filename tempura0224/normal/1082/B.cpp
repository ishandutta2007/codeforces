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
    int n;cin>>n;
    string s;cin>>s;
    vector<int> G,S;
    S.push_back(0);
    int pos=-1;
    rep(i,n){
      if(s[i]=='G'){
        if(pos==-1){
          G.push_back(1);
          pos=1;
        }
        else ++G.back();
      }
      else{
        if(pos==1){
          S.push_back(1);
          pos=-1;
        }
        else ++S.back();
      }
    }
    if(G.size()==0){
      cout<<0<<endl;
    }
    else if(G.size()==1){
      cout<<G[0]<<endl;
    }
    else if(G.size()==2){
      if(S[1]==1)cout<<G[0]+G[1]<<endl;
      else cout<<max(G[0],G[1])+1<<endl;
    }
    else {
      int ret=0;
      int m=G.size();
      rep(i,m)ret=max(ret,G[i]+1);
      rep(i,m-1){
        if(S[i+1]==1)ret=max(ret,G[i]+G[i+1]+1);
      }
      cout<<ret<<endl;
    }
    return 0;
}