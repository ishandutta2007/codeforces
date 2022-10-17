#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
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
int n;
vector<pair<int,int> >ans;
signed main(){
	rd(n);
	int lim=1;
	while(lim<n)lim<<=1;
	lim/=2;
	for(int i=1;i<lim;i<<=1){
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				int k1=j+k,k2=i+j+k;
				if(k1<n&&k2<n){
					ans.emplace_back(k1+1,k2+1);
				}
			}
		}
	}
	for(int i=1;i<lim;i<<=1){
		for(int j=0;j<lim;j+=i<<1){
			for(int k=0;k<i;++k){
				int k1=j+k,k2=i+j+k;
				if(k1<n&&k2<n){
					ans.emplace_back(n-k1,n-k2);
				}
			}
		}
	}
	pt(SZ(ans),'\n');
	for(auto x:ans){
		pt(x.fi,' ');
		pt(x.se,'\n');
	}
	return 0;
}