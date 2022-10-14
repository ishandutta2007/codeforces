#include <queue>
#include <cstdio>
#include <bitset>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define debug(x) //cerr<<#x<<'='<<x<<endl
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define mid ((l+r)/2)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}
int mod = 1000000007;
inline int sq(int x){return 1ll*x*x%mod;}
inline int sub(int a,int b){return a<b?a-b+mod:a-b;}
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int qpow(int a,int b){if(b == 0)return 1;return b&1?mul(sq(qpow(a,b/2)),a):sq(qpow(a,b/2));}
inline int inv(int a){return qpow(a,mod-2);}
const int N = 400040;
int prod[4*N],lazy[4*N] = {0},n,q,pr[310] = {0},a[N],qinv[310];
bitset<64> pri[4*N],lzpri[4*N],bel[310],apri[N];
void pushd(int p,int l,int r){
	lazy[p*2]=mul(lazy[p],lazy[p*2]);
	lazy[p*2+1]=mul(lazy[p],lazy[p*2+1]);
	prod[p]=mul(prod[p],qpow(lazy[p],r-l+1));
	lazy[p] = 1;
	lzpri[p*2]|=lzpri[p];
	lzpri[p*2+1]|=lzpri[p];
	pri[p]|=lzpri[p];
	lzpri[p].reset();
}
void build_tree(int p,int l,int r){
	
	if(l == r){
		pri[p] = apri[l];
		prod[p] = a[l];
		lazy[p] = 1;
		lzpri[p].reset();
		return;
	}
	build_tree(p*2,l,mid);
	build_tree(p*2+1,mid+1,r);
	prod[p] = mul(prod[p*2],prod[p*2+1]);
	lazy[p] = 1;
	pri[p] = pri[p*2]|pri[p*2+1];
	lzpri[p].reset();
}
int query(int p,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr){
		debug(prod[p]);debug(lazy[p]);
		return mul(prod[p],qpow(lazy[p],r-l+1));
	}
	pushd(p,l,r);
	if(qr<=mid)return query(p*2,l,mid,ql,qr);
	if(ql>mid) return query(p*2+1,mid+1,r,ql,qr);
	return mul(query(p*2,l,mid,ql,qr),query(p*2+1,mid+1,r,ql,qr));
}
bitset<64> queryb(int p,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr)return pri[p]|lzpri[p];
	pushd(p,l,r);
	if(qr<=mid)return queryb(p*2,l,mid,ql,qr);
	if(ql>mid) return queryb(p*2+1,mid+1,r,ql,qr);
	return queryb(p*2,l,mid,ql,qr)|queryb(p*2+1,mid+1,r,ql,qr);
}
void gmul(int p,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr){
		debug(qpow(v,r-l+1));debug(lazy[p]);
		lazy[p] = mul(lazy[p],v);
		lzpri[p]|=bel[v];
		return;
	}
	pushd(p,l,r);
	if(qr<=mid){
		gmul(p*2,l,mid,ql,qr,v);
	}else{
		if(ql>mid){
			gmul(p*2+1,mid+1,r,ql,qr,v);
		}else{
			gmul(p*2,l,mid,ql,qr,v);
			gmul(p*2+1,mid+1,r,ql,qr,v);
		}
	}
	prod[p] = mul(mul(prod[p*2],qpow(lazy[p*2],mid-l+1)),mul(prod[p*2+1],qpow(lazy[p*2+1],r-mid)));
	pri[p] = pri[p*2]|lzpri[p*2]|pri[p*2+1]|lzpri[p*2+1];
}
int main() {
	read(n);read(q);
	vector<int> all_pris;
	for(int i=2;i<=300;i++){
		qinv[i] = inv(i);
		if(!pr[i]){
			all_pris.push_back(i);
			bel[i].set(all_pris.size()-1);
			for(int j=i+i;j<=300;j+=i){
				bel[j].set(all_pris.size()-1);
				pr[j] = 1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		read(a[i]);
		apri[i] = bel[a[i]];
	}
	build_tree(1,1,n);
	char op0[10];
	for(int i=0;i<q;i++){
		cin>>op0;
		if(op0[0] == 'M'){
			int l,r,v;
			read(l);read(r);read(v);
			gmul(1,1,n,l,r,v);
		}else{
			int l,r;
			read(l);read(r);
			int cv = query(1,1,n,l,r);
			debug(cv);
			bitset<64> cc = queryb(1,1,n,l,r);
			for(int i=0;i<=63;i++){
				if(cc[i]){
					debug(i);
					cv = mul(cv,mul(all_pris[i]-1,qinv[all_pris[i]]));
				}
			}
			cout<<cv<<endl;
		}
	}
	return 0;
}