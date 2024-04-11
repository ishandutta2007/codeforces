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
const int N=100005;
int m,n,a[N],b[N],fa[N],num[N];
vector<tuple<int,int,int> >c;
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
signed main(){
	rep(i,1,N-1)fa[i]=i;
	rd(m),rd(n);
	rep(i,1,m){
		rd(a[i]);
	}
	rep(i,1,n){
		rd(b[i]);
	}
	int all=0;
	rep(i,1,m){
		int s;rd(s);
		rep(j,1,s){
			int x;rd(x);
			c.emplace_back(a[i]+b[x],i,x);
			all+=a[i]+b[x];
		}
	}
	sort(c.rbegin(),c.rend());
	int res=all;
	for(auto x:c){
		int k1,k2,k3;
		tie(k1,k2,k3)=x;
		if(!num[k2]){
			res-=k1;
			num[k2]=fd(k3);
		}else if(fd(num[k2])!=fd(k3)){
			res-=k1;
			fa[fd(num[k2])]=fd(k3);
		}
	}
	pt(res,'\n');
	return 0;
}