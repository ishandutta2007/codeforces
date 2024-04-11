#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvint;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back
#define mp make_pair

ll mod=1000000007;
std::vector<pair<int,int>> ab;
vi lr;
int n,c;
int childl[200], childr[200], par[200];

bool go(int curn, int maxn){
    if(curn>=maxn){
        return true;
    }
    vb razr(maxn+1, true);
    for(int i=0; i<c; i++) {
        int a=ab[i].first;
        int b=ab[i].second;
        if(a<curn) continue;
        if(a>maxn) continue;
        if ((a==curn)&&(lr[i]==1)) {
            for(int j=b; j<=maxn; j++) razr[j]=false;
        }
        else {
            for(int j=a; j<b; j++) razr[j]=false;
        }
    }
    for(int i=curn; i<=maxn; i++) {
        if(razr[i]){
            bool b=go(curn+1, i);
            if(curn+1<=i) {
                childl[curn]=curn+1;
                par[curn+1]=curn;
            }
            b=b&&go(i+1, maxn);
            if(i+1<=maxn) {
                childr[curn]=i+1;
                par[i+1]=curn;
            }
            return b;
        }
    }
    return false;
}

int main()
{
/*#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif*/
  
  int m,k,p,t,q,x,y;
  string s;
 
  cin>>n>>c;
  for(int i=0; i<c; i++){
      cin>>x>>y>>s;
      if(x>=y){
          cout<<"IMPOSSIBLE";
          return 0;
      }
      ab.pb(mp(x,y));
      if(s=="LEFT") lr.pb(-1);
      else lr.pb(1);
  }
  for(int i=0;i<n; i++){
      childl[i]=0;
      childr[i]=0;
      par[i]=0;
  }
  if(!go(1,n)){
      cout<<"IMPOSSIBLE";
      return 0;
  }
  vb pr(n+1, false);
  int cur=1;
  //while(childl[cur]!=0) cur=childl[cur];
  int num=0;
  while(num<n){
      if ((childl[cur]!=0) && (!pr[childl[cur]])) {
          cur=childl[cur];
          continue;
      }
      if(!pr[cur]) {
          cout<<cur<<" ";
          pr[cur]=true;
          num++;
      }
      if((childr[cur]!=0) && (!pr[childr[cur]])) {
          cur=childr[cur];
          continue;
      }
      cur=par[cur];
  }
  //cout<<n;
  //cout<<s;



//cout<<go(40,822);
  return 0;
}