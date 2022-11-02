#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
VVI fd,p;
bool isp(){ 
  in n,k;
  cin>>n>>k;
  fd=VVI(3,VI(n+5,1));
  p=VVI(3,VI(n+5,0));
  string t;
  bool f=0;
  forn(i,3){
    cin>>t;
    forn(j,n)
      fd[i][j]=(t[j]=='.');
    if(t[0]=='s'){
      if(t[1]!='.')
	f=1;
      p[i][1]=1;
      p[i][0]=1;
      fd[i][0]=1;
    }
  }
  if(f)
    return 0;
  for(in c=1;c<n+1;c+=3){
    forn(j,3){
      if(!p[j][c])
	continue;
      for(in l=max(0LL,j-1);l<=min(2LL,j+1);++l){
	bool ok=1;
	for(in s=c;s<=c+3;++s)
	  ok&=fd[l][s];
	if(ok){
	  p[l][c+3]=1;
	  if(c+3>=n+1)
	    return 1;
	}
      }
    }
  }
  return 0;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in t;
  cin>>t;
  forn(z,t){
    if(isp())
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}