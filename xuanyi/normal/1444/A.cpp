#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int T,p,q;
signed main(){
	rd(T);
	while(T--){
		rd(p),rd(q);
		vector<pair<int,int> >d;
		for(int i=2;i*i<=q;++i){
			int cnt=0;
			while(q%i==0){
				q/=i;
				++cnt;
			}
			if(cnt){
				d.EB(i,cnt);
			}
		}
		if(q>1){
			d.EB(q,1);
		}
		int ans=1;
		for(auto x:d){
			int tot=0;
			int t=p;
			while(t%x.X==0)t/=x.X,++tot;
			rep(i,1,min(tot,x.Y-1))t*=x.X;
			ans=max(ans,t);
		}
		pt(ans,'\n');
	}
	return 0;
}