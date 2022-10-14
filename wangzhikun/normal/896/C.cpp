#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
 
int mod = 998244353;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int sq(int x){return 1ll*x*x%mod;}
int mpow(int a,int b){return b == 0 ? 1 : ( b&1 ? mul(a,sq(mpow(a,b/2))) : sq(mpow(a,b/2)));}
 
int n,m,seed,vmax;
int rnd(){
	int ret = seed;
	seed = (1ll*seed * 7 + 13) % 1000000007;
	return ret;
}
 
struct In{
	int l,r;
	ll val;
	bool operator < (const In &rhs) const{
		return val<rhs.val;
	}
};
 
int main() {
	read(n);read(m);read(seed);read(vmax);
	//cout<<n<<' '<<m<<' '<<seed<<' '<<vmax<<endl;
	vector<In> V;
	for(int i=1;i<=n;i++){
		V.push_back((In){i,i,rnd()%vmax+1});
	}
	for(int i=1;i<=m;i++){
		int op = rnd()%4+1;
		int l = rnd()%n+1;
		int r = rnd()%n+1;
		//cout<<op<<' '<<l<<' '<<r<<endl;
		if(l>r)swap(l,r);
		if(op == 1){
			int x = rnd()%vmax+1;
			vector<In> nV;
			for(auto ech:V){
				if(ech.r<l || ech.l>r)nV.push_back(ech);
				else{
					if(l<=ech.l && ech.r<=r)
						nV.push_back((In){ech.l,ech.r,ech.val+x});
					else{
						if(ech.l<=l && ech.r<=r){
							nV.push_back((In){ech.l,l-1,ech.val});
							nV.push_back((In){l,ech.r,ech.val+x});
						}else{
							if(l<=ech.l && r<=ech.r){
								nV.push_back((In){ech.l,r,ech.val+x});
								nV.push_back((In){r+1,ech.r,ech.val});
							}else{
								nV.push_back((In){ech.l,l-1,ech.val});
								nV.push_back((In){l,r,ech.val+x});
								nV.push_back((In){r+1,ech.r,ech.val});
							}
						}
					}
				}
			}
			V = nV;
		}
		if(op == 2){
			int x = rnd()%vmax+1;
			vector<In> nV;
			for(auto ech:V){
				if(ech.l<l)nV.push_back((In){ech.l,min(ech.r,l-1),ech.val});
			}
			nV.push_back((In){l,r,x});
			for(auto ech:V){
				if(ech.r>r)nV.push_back((In){max(r+1,ech.l),ech.r,ech.val});
			}
			V = nV;
		}
		if(op == 3){
			int x = rnd()%(r-l+1)+1;
			vector<In> nV;
			for(auto ech:V){
				if(ech.r<l || ech.l>r)continue;
				nV.push_back((In){max(l,ech.l),min(r,ech.r),ech.val});
			}
			sort(nV.begin(),nV.end());
			for(auto ct:nV){
				if(x<=ct.r-ct.l+1){
					cout<<ct.val<<"\n";
					break;
				}
				x-=(ct.r-ct.l+1);
			}
		}
		if(op == 4){
			int x = rnd()%vmax+1;
			int y = rnd()%vmax+1;
			mod = y;
			
			vector<In> nV;
			for(auto ech:V){
				if(ech.r<l || ech.l>r)continue;
				nV.push_back((In){max(l,ech.l),min(r,ech.r),ech.val});
			}
			ll ans = 0;
			for(auto ct:nV){
				ans = (ans+1ll*(ct.r-ct.l+1)*mpow(ct.val%y,x)%y)%y;
			}
			cout<<ans%y<<"\n";
		}
	}
	return 0;
}