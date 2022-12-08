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
	int n;
	cin>>n;
	ll a[2][n];
	rep(i,2)rep(j,n)cin>>a[i][j];
	ll sum=0,l=0,r=0;
	rep(j,n){
		sum+=a[0][j]+a[1][j];
		l+=a[0][j]*(j+1);
		r+=a[0][j]*(2*n-j);
		r+=a[1][j]*(j+1);
		l+=a[1][j]*(2*n-j);
	}
	ll ans=0,pos=-sum;
	rep(i,n){
		if(i%2)ans=max(ans,pos+r);
		else ans=max(ans,pos+l);
		pos+=a[0][i]*((2*i+1)+(i%2));
		pos+=a[1][i]*((2*i+2)-(i%2));
		sum-=a[0][i]+a[1][i];
		l+=sum;
		r+=sum;
		l-=a[0][i]*(2*i+1);
		r-=a[0][i]*2*n;
		r-=a[1][i]*(2*i+1);
		l-=a[1][i]*2*n;
	}
	cout<<ans<<endl;
   return 0;
}