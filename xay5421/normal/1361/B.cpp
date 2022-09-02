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
const int N=1000005,P=1e9+7;
int T;
int n,p,a[N];
int fpow(int k1,int k2){
	int k3=1;for(;k2;k2>>=1,k1=1LL*k1*k1%P)if(k2&1)k3=1LL*k3*k1%P;return k3;
}
signed main(){
	rd(T);
	while(T--){
		rd(n),rd(p);
		rep(i,1,n)rd(a[i]);
		if(p==1){
			pt(n&1,'\n');
			continue;
		}
		sort(a+1,a+1+n,[&](int x,int y){return x>y;});
		int k1=0;
		int ans=0;bool gg=0;
		rep(i,1,n){
			if(i>1&&!gg){
				if(k1!=0)
					per(j,a[i-1],a[i]+1){
						if(k1>1e18/p){
							gg=1;
							break;
						}
						k1*=p;
					}
			}
			if(k1||gg){
				--k1;
				(ans-=fpow(p,a[i]))%=P;
			}else{
				++k1;
				(ans+=fpow(p,a[i]));
			}
		}
		pt((ans+P)%P,'\n');
	}
	return 0;
}