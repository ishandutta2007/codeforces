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
int T,n,a[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		rep(i,1,n-1){
			a[i]=a[i+1]-a[i];
		}
		--n;
		sort(a+1,a+n+1);
		vector<pair<int,int> >all;
		for(int i=1,j;i<=n;i=j){
			j=i+1;
			while(j<=n&&a[i]==a[j]){
				++j;
			}
			all.eb(a[i],j-i);
		}
		while(1){
			if(SZ(all)==1&&all[0].second==1)break;
			vector<pair<int,int> >new_all;
			sort(all.begin(),all.end());
			rep(i,0,SZ(all)-1){
				if(all[i].second>1){
					new_all.eb(0,all[i].second-1);
				}
				if(i+1<SZ(all)){
					new_all.eb(all[i+1].first-all[i].first,1);
				}
			}
			sort(new_all.begin(),new_all.end());
			all.clear();
			for(int i=0,j;i<SZ(new_all);i=j){
				j=i+1;
				while(j<SZ(new_all)&&new_all[i].first==new_all[j].first)++j;
				int cnt=0;
				rep(k,i,j-1)cnt+=new_all[k].second;
				all.eb(new_all[i].first,cnt);
			}
		}
		printf("%d\n",all[0].first);
	}
	return 0;
}