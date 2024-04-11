//by xay5421 2449670833@qq.com
#include<set>
#include<map>
#include<cmath>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#define int long long
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
//#define debug(...) fprintf(stderr,__VA_ARGS__)
#define debug(...) ((void)0)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
typedef long long ll;typedef unsigned long long ull;typedef std::pair<int,int> pii;
template<typename T>void rd(T&x){int f=0,c;while((c=getchar())<48||57<c)f^=!(c^45);x=(c&15);while(47<(c=getchar())&&c<58)x=x*10+(c&15);if(f)x=-x;}
template<typename T>inline void pt(T x){if(x<0)x=-x,putchar('-');if(x>9)pt(x/10);putchar(x%10+48);}
template<typename T>inline void pt(T x,int c){pt(x),putchar(c);}
template<typename T>inline T max(const T&x,const T&y){return x<y?y:x;}
template<typename T>inline T min(const T&x,const T&y){return x<y?x:y;}

int T,l,r,A[35],B[35],f[35][2][2];

int dfs(int bit,int upa,int upb){
	if(bit<0)return 1;
	int&res=f[bit][upa][upb];
	if(res!=-1)return res;
	res=0;
	rep(i,0,upa?A[bit]:1)rep(j,0,upb?B[bit]:1){
		if(i!=1||j!=1){
			res+=dfs(bit-1,upa&(i==A[bit]),upb&(j==B[bit]));
		}
	}
	return res;
}

int solve(int a,int b){
	if(a<0||b<0)return 0; 
	memset(f,-1,sizeof(f));
	rep(i,0,30)A[i]=a>>i&1;
	rep(i,0,30)B[i]=b>>i&1;
	int ans=dfs(31,1,1);
	debug("%lld %lld:%lld\n",a,b,ans);
	return ans;
}

signed main(){
	rd(T);
	while(T--){
		rd(l),rd(r);
		pt(solve(r,r)-solve(l-1,r)*2+solve(l-1,l-1),'\n');
	}
	return 0;
}