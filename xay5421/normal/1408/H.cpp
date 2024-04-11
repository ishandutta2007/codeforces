#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define EB emplace_back
#define SZ(x) ((int)(x).size())
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005;
int T,n,a[N],le[N],ri[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		int all=count(a+1,a+1+n,0),mid=all/2,cur=0;
		rep(i,1,n){
			if(a[i]==0)++cur;
			else{
				if(cur<=mid){
					le[a[i]]=cur;
				}else{
					if(!ri[a[i]])ri[a[i]]=all-cur;
				}
			}
		}
		vector<pair<int,int> >f;
		rep(i,0,n)if(le[i]||ri[i])f.EB(le[i],ri[i]);
		sort(f.begin(),f.end());
		multiset<int>S;
		int ans=0;
		per(i,mid,1){
			while(SZ(f)&&f.back().fi>=i){
				S.insert(f.back().se);
				f.pop_back();
			}
			if(SZ(S)){
				++ans;
				S.erase(S.begin());
			}
		}
		while(SZ(f)){
			S.insert(f.back().se);
			f.pop_back();
		}
		per(i,mid,1){
			if(SZ(S)&&*--S.end()>=i){
				++ans;
				S.erase(--S.end());
			}
		}
		rep(i,0,n)le[i]=ri[i]=0;
		pt(min(ans,mid),'\n');
	}
	return 0;
}