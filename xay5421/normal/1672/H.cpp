#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=200005;
int n,Q,sum[2][N];
char s[N];
int main(){
	rd(n),rd(Q);
	scanf("%s",s+1);
	rep(i,2,n){
		sum[0][i]=sum[0][i-1]+(s[i]=='0'&&s[i-1]=='0');
		sum[1][i]=sum[1][i-1]+(s[i]=='1'&&s[i-1]=='1');
	}
	while(Q--){
		int l,r;
		rd(l),rd(r);
		printf("%d\n",max(sum[0][r]-sum[0][l],sum[1][r]-sum[1][l])+1);
	}
	return 0;
}