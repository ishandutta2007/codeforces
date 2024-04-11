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
const int N=400005;
int T,n,m,sum[N];
char s[N];
int main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		scanf("%s",s+1);
		rep(i,1,n)s[i+n]=s[i];
		rep(i,1,n*2)sum[i]=sum[i-1]+(s[i]=='1');
		// sum[n]/n=x/m
		if(1LL*sum[n]*m%n!=0){
			puts("-1");
			continue;
		}
		int x=1LL*sum[n]*m/n;
		bool f=0;
		rep(i,1,n)if(sum[i+m-1]-sum[i-1]==x){
			// l=i,r=i+m-1
			if(i+m-1<=n){
				printf("1\n%d %d\n",i,i+m-1);
			}else{
				printf("2\n%d %d\n%d %d\n",1,i+m-1-n,i,n);
			}
			f=1;
			break;
		}
		assert(f);
	}
	return 0;
}