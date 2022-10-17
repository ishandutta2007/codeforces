// author: xay5421
// created: Sun Feb 28 22:08:21 2021
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
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
int Q,a[31],b[31];
int sol(int u,int v){
	if(u>v)return 0;
	if(u==v)return 1;
	int s1=0,s2=0;
	rep(i,0,30)a[i]=u&1,s1+=u&1,u>>=1;
	rep(i,0,30)b[i]=v&1,s2+=v&1,v>>=1;
	if(s1<s2)return 0;
	int j=30;
	per(i,30,0){
		if(b[i]){
			while(j>=0&&(j>i||!a[j]))--j;
			if(j<0)return 0;
			--j;
		}
	}
	return 1;
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(Q);
	while(Q--){
		int u,v;
		rd(u),rd(v);
		puts(sol(u,v)?"YES":"NO");
	}
	return 0;
}