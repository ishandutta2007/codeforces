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
int T;
vector<int>num;
vector<pair<int,int> >ans;
void sol(int n,int dt){ // dt,2dt,3dt,...,ndt
	if(n<=2){
		rep(i,1,n)num.pb(dt*i);
		return;
	}
	int x=1;
	while(x<n)x<<=1;
	if(x==n){
		num.pb(n*dt);
		--n;
	}
	x>>=1;
	num.pb(x*dt);
	rep(i,x+1,n){
		num.pb(x*2*dt);
		ans.eb(i*dt,(x*2-i)*dt);
	}
	sol(x*2-n-1,dt);
	sol(n-x,dt*2);
}
int main(){
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(n<=2){puts("-1");continue;}
		num.clear();
		ans.clear();
		sol(n,1);
		sort(num.begin(),num.end());
		int goal=1;
		while(goal<n)goal<<=1;
		bool flg=0;
		rep(i,0,SZ(num)-2)if(num[i]==num[i+1]){
			assert(num[i]<goal);
			ans.eb(num[i],num[i]);
			num[i+1]*=2;
			num.erase(num.begin()+i);
			flg=1;
			break;
		}
		assert(flg);
		each(x,num){
			while(x<goal){
				ans.eb(0,x);
				ans.eb(x,x);
				x<<=1;
			}
		}
		ans.eb(0,goal);
		printf("%d\n",SZ(ans));
		each(x,ans)printf("%d %d\n",get<0>(x),get<1>(x));
	}
	return 0;
}