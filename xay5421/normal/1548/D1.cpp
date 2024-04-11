// author: xay5421
// created: Sun Aug  1 23:22:40 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=6006;
int n,x[N],y[N],cnt[N][2];
bitset<N>g[N],h[N];
LL bk[2][2][2][2][2];
int calc(int x,int y){
	return __gcd(x,y)>>1&1;
}
int main(){
	memset(bk,-1,sizeof(bk));
	rd(n);
	rep(i,1,n){
		rd(x[i]),rd(y[i]);
	}
	rep(i,1,n)rep(j,i+1,n){
		int t=g[i][j]=g[j][i]=calc(abs(x[i]-x[j]),abs(y[i]-y[j]));
		h[i][j]=h[j][i]=t^1;
		++cnt[i][t],++cnt[j][t];
	}
	LL w0=0,w1=0;
	rep(i,1,n)rep(j,i+1,n)if(g[i][j]){
		LL *cur=bk[x[i]/2&1][y[i]/2&1][x[j]/2&1][y[j]/2&1];
		LL t0,t1;
		if(cur[0]!=-1){
			//assert(cur[0]==(h[i]&h[j]).count());
			//assert(cur[1]==(g[i]&g[j]).count());
			t0=cur[0];
			t1=cur[1];
		}
		else{
			cur[0]=t0=(h[i]&h[j]).count();
			cur[1]=t1=(g[i]&g[j]).count();
		}
		w0+=t0;
		w1+=t1;
	}
	printf("%lld\n",1LL*n*(n-1)*(n-2)/6-(w0+w1/3));
	return 0;
}