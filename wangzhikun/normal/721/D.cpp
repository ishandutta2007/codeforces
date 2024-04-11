#include <set>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define debug(x) cerr<<#x<<'='<<x<<endl
#define set0(x) memset(x,0,sizeof(x))
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

ll n,k,x,v,ans[200020];
struct V{
	ll id,val;
	V(ll a,ll b):id(a),val(b){}
	bool operator > (const V &rhs) const{
		return abs(val)>abs(rhs.val);
	}
};
priority_queue< V,vector<V>,greater<V> > Q;
int main() {
	read(n);read(k);read(x);
	int cnt = 0;
	for(int i=1;i<=n;i++){
		read(v);
		if(v<0)cnt^=1;
		Q.push(V(i,v));
	}
	for(int i=0;i<k;i++){
		V cc = Q.top();Q.pop();
		if(cc.val == 0){
			if(cnt == 0)cc.val-=x;
			else cc.val+=x;
			cnt = 1;
			Q.push(cc);
			continue;
		}
		if(cnt == 0){
			if(cc.val<0){
				cc.val+=x;
				if(cc.val>=0)cnt^=1;
			}else{
				cc.val-=x;
				if(cc.val<0)cnt^=1;
			}
			
		}else{
			if(cc.val<0){
				cc.val-=x;
			}else{
				cc.val+=x;
			}
		}
		Q.push(cc);
	}
	while(!Q.empty()){
		V cc = Q.top();Q.pop();
		ans[cc.id] = cc.val;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i];
		if(i!=n)cout<<' ';
	}
	cout<<endl;
	return 0;
}