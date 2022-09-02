#include<bits/stdc++.h>
#define D(...) fprintf(stderr,__VA_ARGS__)
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define fi first
#define se second
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;typedef vector<int>VI;typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=1000005;
int n,r1,r2,r3,r4,d,a[N],f[N],suf[N];
void umin(int&x,int y){if(y<x)x=y;}
signed main(){
	memset(f,63,sizeof(f));
	rd(n),rd(r1),rd(r2),rd(r3);
	r4=min({r1,r2,r3});
	rd(d);
	rep(i,1,n)rd(a[i]);
	f[0]=0;
	auto getw1=[&](int i){
		return a[i]*r1+r3;
//		return min(r3,a[i]*r1)+r3;
	};
	auto getw2=[&](int i){
		return min(getw1(i),min(a[i]*r1+r1+r1,r2+r1));
//		return min(min(r3,a[i]*r1)+min(r4*2,r3),r2+r4);
	};
	rep(i,1,n){
		umin(f[i],f[i-1]+getw1(i));
		umin(f[i],f[i-1]+getw2(i)+d*2);
		if(i>1){
			umin(f[i],f[i-2]+getw2(i-1)+getw2(i)+d*2);
		}
		if(i>2){
			umin(f[i],f[i-3]+getw2(i-2)+getw2(i-1)+getw2(i)+d*4);
		}
	}
	int ans=1e18;
	per(i,n,1){
		if(i<n){
			suf[i]=suf[i+1]+getw2(i);
		}else{
			suf[i]=min({
				getw1(i),
				getw2(i)+d*2
			});
		}
	}
	rep(i,0,n-2){
		ans=min(ans,f[i]+suf[i+1]+d*(n-i-1));
	}
	ans=min({ans,f[n]});
	ans+=(n-1)*d;
	pt(ans,'\n');
	return 0;
}