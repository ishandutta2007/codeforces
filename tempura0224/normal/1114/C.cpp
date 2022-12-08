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
	ll n,b;
	cin>>n>>b;
	vector<pair<ll,ll>> d;
	for(int i=2;i<=1000000;++i){
		if(b%i==0){
			int c=0;
			while(b%i==0){
				b/=i;
				++c;
			}
			d.push_back({i,c});
		}
	}
	if(b>1)d.push_back({b,1});
	ll cnt=longinf;
	for(auto e:d){
		ll p=e.first;
		ll tmp=n,ret=0;
		while(tmp){
			ret+=tmp/p;
			tmp/=p;
		}
		cnt=min(cnt,ret/e.second);
	}
	cout<<cnt<<endl;
	return 0;
}