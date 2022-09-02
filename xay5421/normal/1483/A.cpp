// author: xay5421
// created: Sun Mar 21 21:00:10 2021
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
const int N=100005;
int T,n,m,cnt[N];
vector<int>vec[N];
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m);
		rep(i,1,n)cnt[i]=0;
		rep(i,1,m){
			int k;
			rd(k);
			vector<int>v(k);
			rep(j,0,k-1)rd(v[j]),++cnt[v[j]];
			vec[i]=v;
		}
		int t=max_element(cnt+1,cnt+1+n)-cnt;
		if(cnt[t]<=(m+1)/2){
			puts("YES");
			rep(i,1,m)pt(*vec[i].begin(),' ');
			puts("");
		}else{
			vector<int>ans,tem;
			int tot=0;
			rep(i,1,m){
				int val=-1,hav=0;
				for(int x:vec[i])if(x!=t){val=x;break;}
				for(int x:vec[i])if(x==t){hav=1;break;}
				if(val!=-1){
					if(hav)tem.push_back(SZ(ans));
					ans.push_back(val);
				}
				else ans.push_back(t),++tot;
			}
			while(tot<(m+1)/2){
				++tot;
				ans[tem.back()]=t;
				tem.pop_back();
			}
			if(tot<=(m+1)/2){
				puts("YES");
				for(int x:ans)pt(x,' ');
				puts("");
			}else{
				puts("NO");
			}
		}
	}
	return 0;
}