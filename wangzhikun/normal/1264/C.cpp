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
#define mid ((l+r)/2)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();ll f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int pow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(pow(a,b/2))) : sq(pow(a,b/2)));}

struct mdat{
	int C,x,y;
}Tmd[800080],e;

int prob[200020],inv100;
mdat muld(mdat a,mdat b){
	mdat ret;
	ret.C = add(a.C,mul(a.y,b.C));
	ret.x = add(a.x,mul(a.y,b.x));
	ret.y = mul(a.y,b.y);
	return ret;
}
void build(int id,int l,int r){
	if(l == r){
		Tmd[id].C = 1;
		Tmd[id].x = sub(1,mul(prob[l],inv100));
		Tmd[id].y = mul(prob[l],inv100);
		return;
	}
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	Tmd[id] = muld(Tmd[id*2],Tmd[id*2+1]);
}
mdat qmdat(int id,int l,int r,int ql,int qr){
	if(r <=qr && l>=ql){
		return Tmd[id];
	}
	mdat ans = e;
	
	if(ql<=mid){
		ans = muld(ans,qmdat(id*2,l,mid,ql,qr));
	}
	if(qr>mid){
		ans = muld(ans,qmdat(id*2+1,mid+1,r,ql,qr));
	}
	return ans;
}

int n,q;
int calcreq(int l,int r){
	mdat cd = qmdat(1,1,n,l,r);
	return mul(cd.C,pow(sub(1,cd.x),mod-2));
}
int main() {
	inv100 = pow(100,mod-2);
	e.C = 0;
	e.x = 0;
	e.y = 1;
	read(n);read(q);
	for(int i=1;i<=n;i++){
		read(prob[i]);
	}
	build(1,1,n);
	
	set<int> cp;
	set<int>::iterator it;
	cp.insert(1);
	cp.insert(n+1);
	int ans = calcreq(1,n),id;
	while(q--){
		cin>>id;
		if(cp.count(id)){
			int cr,cl;
			it = cp.lower_bound(id);
			it++;
			cr = *it;
			it--;
			it--;
			cl = *it;
			ans = sub(ans,calcreq(id,cr-1));
			ans = sub(ans,calcreq(cl,id-1));
			ans = add(ans,calcreq(cl,cr-1));
			cp.erase(id);
		}else{
			int cr,cl;
			it = cp.lower_bound(id);
			cr = *it;
			it--;
			cl = *it;
			ans = sub(ans,calcreq(cl,cr-1));
			ans = add(ans,calcreq(id,cr-1));
			ans = add(ans,calcreq(cl,id-1));
			cp.insert(id);
		}
		cout<<ans<<'\n';
	}
	return 0;
}