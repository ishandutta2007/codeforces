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
const int N=1000005;
int n,m,a[100005],c[100005],p[N/10];
bool ban[N];
char s[100005];
int po(int k1,int k2,int mod){
	int k3=1;
	for(;k2;k2>>=1,k1=1LL*k1*k1%mod)if(k2&1)k3=1LL*k3*k1%mod;
	return k3;
}
void solve(int d){
	rep(i,0,d-1)c[i]=0;
	rep(i,0,n-1)c[i%d]+=a[i];
	for(int P=((m+d-1)/d+1)*d+1;P<N;P+=d)if(!ban[P]){
		const int g=3;
		int wn;
		if((wn=po(g,(P-1)/d,P))==1)continue;
		int w=1;
		rep(i,1,d-1){
			w=1LL*w*wn%P;
			int v=0;
			per(j,d-1,0)v=(1LL*v*w+c[j])%P;
			if(v==0&&w>1&&w<P-1){
				printf("%d %d\n",P,w);
				exit(0);
			}
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	ban[0]=ban[1]=1;
	rep(i,2,N-1){
		if(!ban[i]){
			p[++*p]=i;
		}
		for(int j=1;j<=*p&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			if(i%p[j]==0)break;
		}
	}
	rd(n),rd(m);
	scanf("%s",s);
	rep(i,0,n-1)a[i]=s[i];
	scanf("%s",s);
	rep(i,0,n-1)a[i]-=s[i];
	for(int d=2;;++d){
		solve(d);
	}
	return 0;
}