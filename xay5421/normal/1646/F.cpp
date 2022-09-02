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
const int N=105;
int n;
pair<int,int>a[N][N];
int mod(int x){
	x%=n;
	if(x<=0)x+=n;
	return x;
}
int main(){
	rd(n);
	int sum=0;
	rep(i,1,n)rep(j,1,n)rd(a[i][j].first),a[i][j].second=(a[i][j].first-i+n)%n,sum+=a[i][j].second;
	int turn=(n*n*(n-1)-sum)/n;
	while(turn--){
		static int sum[N];
		fill(sum+1,sum+n+1,0);
		rep(i,1,n){
			rep(j,1,n)sum[i]+=a[i][j].second;
		}
		int i=min_element(sum+1,sum+n+1)-sum;
		int x=1;
		rep(j,2,n)if(a[i][j].second<a[i][x].second)x=j;
		a[i][x].second+=n;
	}
	vector<vector<int> >ans;
	while(1){
		static int pos[N];
		fill(pos+1,pos+n+1,-1);
		rep(i,1,n){
			int mx=0;
			rep(j,1,n)if(a[i][j].second>mx){
				mx=a[i][j].second;
				pos[i]=j;
			}
			//assert(pos[i]!=-1);
		}
		if(pos[1]==-1)break;
		ans.pb({});
		rep(i,1,n)ans.back().pb(a[i][pos[i]].first),--a[i][pos[i]].second;
		auto old=a[n][pos[n]];
		per(i,n-1,1)a[i+1][pos[i+1]]=a[i][pos[i]];
		a[1][pos[1]]=old;
	}
	printf("%d\n",SZ(ans));
	each(v,ans){
		each(x,v)printf("%d ",x);
		puts("");
	}
	return 0;
}