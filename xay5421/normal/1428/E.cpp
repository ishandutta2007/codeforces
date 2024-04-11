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
int n,K,a[N],b[N];
bool chk(int mid){
	int tot=0;
	rep(i,1,n){
		tot+=(a[i]+mid-1)/mid;
	}
	return tot<=K;
}
int sqr(int x){return x*x;}
int fun(int i,int w){
	int t=a[i]-w*(a[i]/w);
	return sqr(a[i]/w)*(w-t)+sqr(a[i]/w+1)*t;
}
priority_queue<pair<int,int> >Q;
signed main(){
	rd(n),rd(K);
	int res=0;
	rep(i,1,n){
		rd(a[i]);
		Q.emplace(fun(i,1)-fun(i,2),i);
		res+=a[i]*a[i];
		b[i]=1;
		--K;
	}
	while(K--){
		auto it=Q.top();
		Q.pop();
		res-=it.fi;
		++b[it.se];
		Q.emplace(fun(it.se,b[it.se])-fun(it.se,b[it.se]+1),it.se);
	}
	pt(res,'\n');
	return 0;
}