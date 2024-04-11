#include<bits/stdc++.h>

using namespace std;

#define rg register
#define In inline
#define ll long long

const int N = 1e5;

namespace IO{
	In ll read(){
		ll s = 0,ww = 1;
		char ch = getchar();
		while(ch < '0' || ch > '9'){if(ch == '-')ww = -1;ch = getchar();}
		while('0' <= ch && ch <= '9'){s = 10 * s + ch - '0';ch = getchar();}
		return s * ww;
	}
	In void write(ll x){
		if(x < 0)putchar('-'),x = -x;
		if(x > 9)write(x / 10);
		putchar('0' + x % 10);
	}
};
using namespace IO;

struct BIT{
	int b[N+5];
	In int lowbit(int x){
		return x & -x;
	}
	In void ud(int x,int dx){
		for(rg int i = x;i <= N;i += lowbit(i))b[i] += dx;
	}
	In int query(int x){
		int rt = 0;
		for(rg int i = x;i;i -= lowbit(i))rt += b[i];
		return rt;
	}
}B;

int a[N+5],n,m;

int main(){
//	freopen("A.in","r",stdin);
//	freopen("A.out","W",stdout);
	n = read(),m = read();
	for(rg int i = 1;i <= n;i++){
		a[i] = read();
		if(a[i] == 1)B.ud(i,1);
	}
	for(rg int i = 1;i <= m;i++){
		int opt = read();
		if(opt == 1){
			int x = read();
			if(a[x] == 0)B.ud(x,1);else B.ud(x,-1);
			a[x] ^= 1;
		}
		else{
			int x = read();
			int k = B.query(n);
//cout<<"k="<<k<<endl;
			if(k >= x)puts("1");else puts("0");
		}
	}
	return 0;
}