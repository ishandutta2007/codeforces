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
const int N=300005;
int n,a[N],ans[N][2];
void sol(vector<int>v,int b,int bs){
	if(SZ(v)<=1)return;
	if(b==-1)return;
	int tot=0,sum=0;
	rep(i,0,SZ(v)-1){
		if(v[i]>=bs+(1LL<<b))++tot;
		else sum+=tot;
	}
	ans[b][0]+=sum;
	tot=0,sum=0;
	rep(i,0,SZ(v)-1){
		if(v[i]<bs+(1LL<<b))++tot;
		else sum+=tot;
	}
	ans[b][1]+=sum;
	vector<int>L,R;
	rep(i,0,SZ(v)-1){
		if(v[i]<bs+(1LL<<b))L.PB(v[i]);
		else R.PB(v[i]);
	}
	sol(L,b-1,bs);
	sol(R,b-1,bs+(1LL<<b));
}
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	sol(vector<int>(a+1,a+1+n),30,0);
	int res=0,tot=0;
	rep(i,0,30){
		if(ans[i][0]>ans[i][1]){
			res^=1LL<<i;
			tot+=ans[i][1];
		}else{
			tot+=ans[i][0];
		}
	}
	pt(tot,' '),pt(res,'\n');
	return 0;
}