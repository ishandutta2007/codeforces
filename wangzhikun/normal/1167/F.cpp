#include <queue>
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#define set0(x) memset(x,0,sizeof(x))
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
template<typename T> void read(T &x){
	x = 0;char ch = getchar();int f = 1;
	while(!isdigit(ch)){if(ch == '-')f*=-1;ch=getchar();}
	while(isdigit(ch)){x = x*10+ch-48;ch=getchar();}x*=f;
}

int mod = 1000000007;
inline int mul(int x,int y){return 1ll*x*y%mod;}
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}

const int maxn = 500050;
int n,a[500050],b[500050];
struct fenwick_tree{
	int c[maxn];
	inline void tadd(int x, int y){
		while (x <= n){
			c[x] = add(c[x],y);
			x += x & -x;
		}
	}
	inline int sum(int x){
		int res = 0;
		while (x > 0){
			res = add(res,c[x]);
			x -= x & -x;
		}
		return res;
	}
}A, B, C, D;
int main() {
	set0(A.c);set0(B.c);set0(C.c);set0(D.c);
	read(n);
	for(int i=1;i<=n;i++){
		read(a[i]);
		b[i-1] = a[i];
	}
	//cout<<233<<endl;
	sort(b,b+n);
	for(int i=1;i<=n;i++){
		a[i] = lower_bound(b,b+n,a[i])-b+1;
	}
	for(int i=1;i<=n;i++){
		C.tadd(a[i],1);
		D.tadd(a[i],i);
	}
	//cout<<233<<endl;
	int ans = 0;
	for(int i=1;i<=n;i++){
		A.tadd(a[i],1);
		B.tadd(a[i],i);
		int cbs = B.sum(a[i]),cds = D.sum(a[i]);
		int cbl = mul(cbs,n-i+1);
		cbl = add(cbl,mul(i,sub(mul(n+1,C.sum(a[i])-A.sum(a[i])),sub(cds,cbs))));
		//cout<<cbl<<endl;
		ans = add(ans,mul(b[a[i]-1],cbl));
	}
	cout<<ans<<endl;
	return 0;
}