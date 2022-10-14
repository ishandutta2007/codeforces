// Author : WangZhikun
// Date   : 2018.09.16

#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
template<typename T> void read(T &x){
	x = 0;ll f = 1;char ch = getchar();
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch = getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch = getchar();}x*=f;
}
ll n,m,d,a,ans[200010];
set<pair<ll,ll>> ct;
set<pair<ll,ll>>::iterator it;
int main(){
	read(n);read(m);read(d);
	for(int i=0;i<n;i++){
		read(a);
		ct.insert(make_pair(a, i));
	}
	ll rrr = 0;
	while(!ct.empty()){
		ll cc = 0;
		rrr+=1;
		while(1){
			it = ct.lower_bound(make_pair(cc, -1));
			if(it == ct.end())break;
			pair<ll,ll> c = *it;
			ct.erase(c);
			ans[c.second] = rrr;
			cc = c.first+d+1;
			//cout<<c.first<<endl;
		}
	}
	cout<<rrr<<endl;
	for(int i=0;i<n;i++){
		cout<<ans[i]<<' ';
	}
	cout<<endl;
	return 0;
}