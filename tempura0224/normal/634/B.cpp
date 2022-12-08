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

int main(){
	ll s,x;
	cin>>s>>x;
	if(s<x){
		cout<<0<<endl;return 0;
	}
	ll ret = s-x;
	if(ret%2){
		cout<<0<<endl;
		return 0;
	}
	ret/=2;
	if(ret&x){
		cout<<0<<endl;
		return 0;
	}
	ll ans = 1;
	rep(i,50){
		if(x&(1ll<<i))ans<<=1;
	}
	if(s==x)ans-=2;
	cout<<ans<<endl;
	return 0;
	
}