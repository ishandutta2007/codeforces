// author: xay5421
// created: Sun Feb 28 22:44:57 2021
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
const int N=200005;
int n,a[N];
bool vis[N];
signed main(){
	rd(n);
	rep(i,1,n)rd(a[i]);
	vector<vector<int> >cycs;
	rep(i,1,n)if(!vis[i]){
		vector<int>cyc;
		int j=i;
		while(!vis[j]){
			vis[j]=1;
			cyc.push_back(j);
			j=a[j];
		}
		if(SZ(cyc)>1){
			cycs.push_back(cyc);
		}
	}
	vector<pair<int,int> >ans;
	while(SZ(cycs)>1){
		vector<int>a=cycs.back(); cycs.pop_back();
		vector<int>b=cycs.back(); cycs.pop_back();
		ans.emplace_back(a.back(),b.back());
		rep(i,0,SZ(a)-2)ans.emplace_back(a[i],b.back());
		rep(i,0,SZ(b)-2)ans.emplace_back(a.back(),b[i]);
		ans.emplace_back(a.back(),b.back());
	}
	if(SZ(cycs)){
		vector<int>a=cycs.back(); cycs.pop_back();
		if(SZ(a)==2){
			int t=-1;
			rep(i,1,n)if(i!=a[0]&&i!=a[1]){
				t=i;
				break;
			}
			ans.emplace_back(t,a[0]);
			ans.emplace_back(t,a[1]);
			ans.emplace_back(t,a[0]);
		}else{
			ans.emplace_back(a[SZ(a)-2],a.back());
			ans.emplace_back(a[SZ(a)-3],a.back());
			rep(i,0,SZ(a)-3)ans.emplace_back(a[i],a[SZ(a)-2]);
			ans.emplace_back(a[SZ(a)-2],a.back());
		}
	}
	pt(SZ(ans),'\n');
	for(auto x:ans)pt(x.X,' '),pt(x.Y,'\n');
	return 0;
}