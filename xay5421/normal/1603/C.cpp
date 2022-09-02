// author: xay5421
// created: Sat Oct 30 23:04:02 2021
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
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
const int N=100005;
int T,n,a[N],top,sum2;
struct node{
	int x,y; // x  y 
	int L(){
		return x/y;
	}
	int R(){
		return (x+y-1)/y;
	}
}st[N];
void change(int i,int k){ // change to ceil(x/y)<=k
	usu(sum2,mu(i,st[i].y));
	st[i].y=(st[i].x+k-1)/k;
	uad(sum2,mu(i,st[i].y));
}
mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
int brand(){return rng()&0X7FFFFFFF;}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		//n=100000;
		//rep(i,1,n)a[i]=rng()%100000+1;
		int ans=0;
		sum2=0;
		rep(i,1,n){
			int cur=a[i];
			per(j,i-1,1){
				bool flg=0;
				if(cur<st[j].R()){
					change(j,cur);
					flg=1;
					cur=st[j].L();
				}else break;
			}
			st[i]=(node){a[i],1};
			//uad(ans,su(mu(i+1,sum1),sum2));
			uad(ans,sum2);
		}
		printf("%d\n",ans);
	}
	return 0;
}