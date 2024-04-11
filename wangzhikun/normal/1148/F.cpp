#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int n;
vector<pii> V[65];

int main() {
	read(n);
	ll csu = 0;
	for(int i=0;i<n;i++){
		ll val,msk;
		read(val);read(msk);
		V[__builtin_ctzll(msk)].push_back(make_pair(val,msk));
		csu+=val;
	}
	ll ans = 0;
	for(int i=62;i>=0;i--){
		ll cu = 0;
		for(auto ct:V[i]){
			if(__builtin_popcountll(ans&ct.second)%2 == 1){
				cu-=ct.first;
			}else{
				cu+=ct.first;
			}
		}
		if(cu>0 && csu>0 || cu<0 && csu<0){
			ans|=(1ll<<i);
		}
	}
	cout<<ans<<endl;
	return 0;
}