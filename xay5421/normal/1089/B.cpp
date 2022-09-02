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
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
const int N=305;
int T,n,m;
char s[N];
bool pd[N];
vector<int>b[N];
int rk;
void push(vector<int>v){
	rep(i,0,SZ(v)-1)if(v[i]){
		if(!pd[i]){
			pd[i]=1;
			b[i]=v;
			++rk;
			return;
		}
		const int I=mu(v[i],po(b[i][i],P-2));
		rep(j,0,SZ(v)-1){
			usu(v[j],mu(b[i][j],I));
		}
	}
}
int main(){
	rd(T);
	while(T--){
		rd(n),rd(m);
		const int sz=n+n+m;
		vector<vector<int> >f(sz,vector<int>(sz));
		auto link=[&](int u,int v){
			int x=rng()%(P-1)+1;
			f[u][v]=x,f[v][u]=su(0,x);
		};
		rep(i,0,n-1){
			scanf("%s",s);
			link(i,i+n);
			rep(j,0,m-1){
				if(s[j]=='1'){
					link(i,j+n+n);
					link(i+n,j+n+n);
				}
			}
		}
		memset(pd,0,sizeof(pd));
		rk=0;
		rep(i,0,sz-1){
			push(f[i]);
		}
		printf("%d\n",rk/2-n);
	}
	return 0;
}