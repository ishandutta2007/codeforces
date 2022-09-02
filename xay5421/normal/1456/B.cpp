// author: xay5421
// created: Sun Nov 29 15:26:31 2020
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
const int N=100005,INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,a[N],h[N],tt[N],s[N];
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]),s[i]=s[i-1]^a[i];
	rep(i,1,n){
		per(j,30,0)if(a[i]>>j&1){h[i]=j;break;}
		++tt[h[i]];
	}
	rep(i,0,30)if(tt[i]>=3)puts("1"),exit(0);
	int ans=INFLL;
	rep(i,1,n){
		per(j,i,1){
			rep(k,i+1,n){
				int s1=s[i]^s[j-1];
				int s2=s[k]^s[i];
				if(s1>s2){
					ans=min(ans,k-j-1);
				}
			}
		}
	}
	if(ans==INFLL)pt(-1,'\n');else pt(ans,'\n');
	return 0;
}