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
	int d,n,m;
	cin>>d>>n>>m;
	multiset<pair<ll,ll>> event;
	rep(i,m){
		int x,y;
		cin>>x>>y;
		event.emplace(x,y);
		event.emplace(x+n,-y-1);
	}
	event.emplace(n,-1);
	ll cur = 0;
	multiset<ll> st;
	st.emplace(0);
	ll ans = 0;
	for(auto p : event){
		if(cur>=d)break;
		if(min(p.first,(ll)d)!=cur&&st.empty()){
			cout<<-1<<endl;
			return 0;
		}
		ans += *st.begin()*(min(p.first,(ll)d)-cur);
		cur = p.first;
		if(p.second>=0)st.emplace(p.second);
		else {
			auto itr = st.lower_bound(-p.second-1);
			st.erase(itr);
		}
	}
	if(cur>=d)cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}