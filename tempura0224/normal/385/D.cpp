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
#include<assert.h>
#include<numeric>
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
	int n;
	double l,r;
	cin>>n>>l>>r;
	int all = 1<<n;
	double x[n],y[n],d[n],pi=acos(-1);
	rep(i,n){
		cin>>x[i]>>y[i]>>d[i];
		d[i]=d[i]*pi/180;
	}
	double dp[all];
	rep(i,all)dp[i]=l;
	rep(mask,all){
		rep(i,n){
			if(((1<<i)&mask)==0)continue;
			double left =dp[mask^(1<<i)];
			double t=atan2(y[i],x[i]-left);
			double res = pi-t-d[i];
			if(res<=0)dp[mask]=r;
			else {
				double right = left + sqrt(y[i]*y[i]+(x[i]-left)*(x[i]-left))/sin(res)*sin(d[i]);
				right = min(r,right);
				dp[mask]=max(dp[mask],right);
			}
		}
	}
	cout<<fixed<<setprecision(10)<<dp[all-1]-l<<endl;
	return 0;
}