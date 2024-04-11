#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<bitset>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
   int n,m;
   cin>>n>>m;
   int a[n],b[m];
   int ret=0;
   rep(i,n){
	   cin>>a[i];
	   ret^=a[i];
   }
   rep(i,m){
	   cin>>b[i];
	   ret^=b[i];
   }
   if(ret){
	   cout<<"NO"<<endl;
	   return 0;
   }
   cout<<"YES"<<endl;
   rep(i,n-1){
	   rep(j,m-1)cout<<"0 ";
	   cout<<a[i]<<endl;
   }
   rep(i,m-1)cout<<b[i]<<" ";
   rep(i,n-1)b[m-1]^=a[i];
   cout<<b[m-1]<<endl;
   return 0;
}