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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

ll solve(ll n,ll q){
	if(q%2==1)return (q+1)/2;
	else {
		ll m = (n+1)/2;
		if(n%2==0){
			q/=2;
			return m + solve(m,q);
		}
		else {
			q/=2;
			q -= 1;
			if(q==0)q += m-1;
			return m + solve(m-1,q);
		}
	}
}

int main(){
	ll n;
	cin>>n;
	int q;
	cin>>q;
	rep(i,q){
		ll x;cin>>x;
		cout<<solve(n,x)<<endl;
	}
	return 0;
}