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
const int N=2005;
int T,n,a[N][N];
bool ban[N];
vector<pair<int,int> >ans;
void solve(vector<int>&v){
	ans.eb(v[0],v.back());
	rep(j,1,SZ(v)-2){
		if(j==1)ans.eb(v[j],v.back());else ans.eb(v[0],v[j]);
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n){
			rep(j,i,n){
				int c;
				while(!isdigit(c=getchar()));
				a[i][j]=c-'0';
			}
		}
		ans.clear();
		vector<pair<int,int> >st;
		per(i,n,1){
			vector<int>v={i};
			st.eb(i,i);
			per(j,SZ(st)-2,0){
				bool flg=0;
				rep(k,st[j].first,st[j].second){
					if(a[i][k]){
						v.pb(k);
						solve(v);
						v={i};
						st.resize(j+1);
						st[j].first=i;
						flg=1;
						break;
					}
				}
				if(!flg){
					v.pb(st[j].second);
				}
			}
		}
		each(x,ans)printf("%d %d\n",x.first,x.second);
		puts("");
	}
	return 0;
}