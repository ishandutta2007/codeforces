// author: xay5421
// created: Sat Mar 13 18:46:17 2021
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
const int N=1505;
int n,m,a[N][N],b[N][N],id[N],pd[N];
void fun(int col){
	stable_sort(id+1,id+1+n,[&](int x,int y){return a[x][col]<a[y][col];});
}
vector<vector<int> >vs,nvs;
int cnt[N];
bool chk(int col){
	for(const auto&v:vs){
		int lst=0;
		for(int x:v){
			if(b[x][col]<lst)return 0;
			lst=b[x][col];
		}
	}
	return 1;
}
void sol(int now){
	nvs.clear();
	rep(i,1,m)cnt[i]=0;
	rep(i,0,SZ(vs)-1){
		for(int l=0,r;l<SZ(vs[i]);l=r){
			r=l+1;
			vector<int>v;
			while(r<SZ(vs[i])&&b[vs[i][l]][now]==b[vs[i][r]][now])++r;
			rep(j,l,r-1)v.push_back(vs[i][j]);
			nvs.push_back(v);
		}
	}
	vs=nvs;
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(m);
	rep(i,1,n){
		rep(j,1,m)rd(a[i][j]);
		id[i]=i;
	}
	rep(i,1,n)rep(j,1,m)rd(b[i][j]);
	vector<int>v(n);
	rep(i,0,n-1)v[i]=i+1;
	vs.push_back(v);
	vector<int>ans;
	while(1){
		for(auto it=vs.begin();it!=vs.end();){
			if(SZ(*it)==1)
				vs.erase(it);
			else ++it;
		}
		if(SZ(vs)==0)break;
		bool flg=0;
		rep(i,1,m){
			if(!pd[i]&&chk(i)){
				ans.push_back(i);
				sol(i);
				pd[i]=1;
				flg=1;
				break;
			}
		}
		if(!flg)break;
	}
	reverse(ans.begin(),ans.end());
	for(int x:ans)fun(x);
	rep(i,1,n){
		rep(j,1,m)if(a[id[i]][j]!=b[i][j])puts("-1"),exit(0);
	}
	pt(SZ(ans),'\n');
	for(int x:ans)pt(x,' ');
	return 0;
}