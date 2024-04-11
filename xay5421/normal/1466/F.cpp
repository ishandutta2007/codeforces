// author: xay5421
// created: Wed Dec 30 23:15:42 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
//#define int long long
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
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=500005;
int n,m;
int b[N],go[N];
vector<int>p[N];
int fd(int k1){return go[k1]==k1?k1:go[k1]=fd(go[k1]);}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,m+1)go[i]=i;
	rep(i,1,n){
		int k;
		rd(k);
		rep(j,1,k){
			int x;
			rd(x);
			p[i].push_back(x);
		}
		if(k==2){
			if(p[i][0]>p[i][1])swap(p[i][0],p[i][1]);
		}
	}
	vector<int>ans;
	rep(i,1,n){
		while(1){
			p[i][0]=fd(p[i][0]);
			if(SZ(p[i])>1){
				p[i][1]=fd(p[i][1]);
				if(p[i][0]>p[i][1])swap(p[i][0],p[i][1]);
			}
			if(p[i][0]==m+1||(SZ(p[i])>1&&p[i][0]==p[i][1])){
				break;
			}
			if(!b[p[i][0]]){
				ans.push_back(i);
				b[p[i][0]]=i;
				if(SZ(p[i])>1){
					go[p[i][0]]=fd(p[i][1]);
				}else{
					go[p[i][0]]=m+1;
				}
				break;
			}else{
				p[i][0]=fd(p[i][0]);
			}
		}
	}
	pt(po(2,SZ(ans)),' '),pt(SZ(ans),'\n');
	for(const auto&x:ans)pt(x,' ');
	return 0;
}