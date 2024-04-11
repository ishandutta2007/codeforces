#include <map>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll T,a,b,p,q,blc;
map<ll,ll> Mp;
map<ll,ll> :: iterator it;
void solve(){
	Mp.clear();
	blc = sqrt(b-a)+1;
	//cout<<blc<<endl;
	for(ll i=0;i<blc;i++){
		if(!Mp.count((i*p*2)%(q*2)))Mp[(i*p*2)%(q*2)] = i;
		//cout<<i<<' '<<(i*p*2)%(q*2)<<endl;
	}
	it = Mp.begin();
	Mp[it->first+q*2] = it->second;
	it = Mp.end();it--;
	Mp[it->first-q*2] = it->second;
	ll ans = -1,mi = 1e15;
	for(ll i=a;i<=b;i+=blc){
		ll cr = ((q-i*p*2)%(q*2)+q*2)%(q*2);
		//cout<<i<<' '<<cr<<endl;
		it = Mp.lower_bound(cr);
		if((abs(cr-it->first)<mi || (abs(cr-it->first)==mi && it->second+i<ans)) && (it->second+i <= b && it->second+i>=a)){
			mi = abs(cr-it->first);
			ans = it->second+i;
		}
		it--;
		if((abs(cr-it->first)<mi || (abs(cr-it->first)==mi && it->second+i<ans)) && (it->second+i <= b && it->second+i>=a)){
			mi = abs(cr-it->first);
			ans = it->second+i;
		}
		if(i+blc>b){
			it = Mp.end();
			while(1){
				it--;
				if((abs(cr-it->first)<mi || (abs(cr-it->first)==mi && it->second+i<ans)) && (it->second+i <= b && it->second+i>=a)){
					mi = abs(cr-it->first);
					ans = it->second+i;
				}
				if(it == Mp.begin())break;
			}
		}
	}
	cout<<ans<<endl;
}

int main(){
	cin>>T;
	while(T--){
		cin>>a>>b>>p>>q;
		if(p>q){
			p%=q;
		}
		solve();
	}
	return 0;
}