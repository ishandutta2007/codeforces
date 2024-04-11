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
const int INF=0X3F3F3F3F;
const int maxQ=1000005,B=31;
ULL hs[maxQ],pw[maxQ];
ULL ghs(int l,int r){return hs[r]-hs[l-1]*pw[r-l+1];}
int Q,n;
char s[maxQ];
char opt[20];
template<int TT>
struct my_map{
	int lnk[TT],pp;
	ULL to[maxQ];
	int nxt[maxQ],val[maxQ];
	int&operator[](ULL x){
		int x_=x%TT;
		for(int i=lnk[x_];i;i=nxt[i]){
			if(to[i]==x)return val[i];
		}
		to[++pp]=x,nxt[pp]=lnk[x_],val[pp]=0,lnk[x_]=pp;
		return val[pp];
	}
};
my_map<19260817>mp;
struct seg{
	int a,k,sz; //  a k sz
};
basic_string<seg>_G[maxQ],_iG[maxQ];
basic_string<seg>G;
int ans[maxQ];
int qs[maxQ];
void gen(basic_string<seg>*_G){
	basic_string<seg>G;
	basic_string<seg>G1,G2;
	rep(i,1,n){ // G[0].k: undefined >n
		G1.clear(),G2.clear();
		for(auto&x:G)if(x.a>1&&s[x.a-1]==s[i])G1.pb((seg){x.a-1,x.k,x.sz});
		int pos=-INF;
		for(auto&x:G1){
			if(x.a-pos!=x.k){
				G2.pb((seg){x.a,x.a-pos,1});
				if(x.sz>1)G2.pb((seg){x.a+x.k,x.k,x.sz-1});
			}else{
				G2.pb(x);
			}
			pos=x.a+x.k*(x.sz-1);
		}
		if(i>1&&s[i-1]==s[i])G2.pb((seg){i-1,i-1-pos,1}),pos=i-1;
		G2.pb((seg){i,i-pos,1});
		
		G.clear();
		seg cur=G2[0];
		rep(_,1,SZ(G2)-1){
			auto&x=G2[_];
			if(cur.k==x.k){
				cur.sz+=x.sz;
			}else{
				G.pb(cur);
				cur=x;
			}
		}
		G.pb(cur);
		_G[i]=G;
	}
}
int res;
void solve1(int l,int r){
	ULL ret;
	{
		int lb=0,rb=SZ(_G[r])-1,pos=0;
		if(_G[r][0].a<l){
			while(lb<=rb){
				int mid=(lb+rb)>>1;
				auto&x=_G[r][mid];
				if(x.a+(x.sz-1)*x.k>=l){
					pos=mid;
					rb=mid-1;
				}else{
					lb=mid+1;
				}
			}
		}
		auto&x=_G[r][pos];
		int t=(l-x.a+x.k-1)/x.k;
		ret=ghs(x.a+t*x.k,r);
	}
	if(!mp[ret]++)++res;
}
void solve2(int l,int r){
	ULL ret;
	{
		int lb=0,rb=SZ(_iG[n+1-l])-1,pos=0;
		if(_iG[n+1-l][0].a>r){
			while(lb<=rb){
				int mid=(lb+rb)>>1;
				auto&x=_iG[n+1-l][mid];
				if(x.a-(x.sz-1)*x.k<=r){
					pos=mid;
					rb=mid-1;
				}else{
					lb=mid+1;
				}
			}
		}
		auto&x=_iG[n+1-l][pos];
		int t=(x.a-r+x.k-1)/x.k;
		ret=ghs(l,x.a-t*x.k);
	}
	if(!--mp[ret])--res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
#endif
	pw[0]=1;
	rep(i,1,maxQ-1)pw[i]=pw[i-1]*B;
	rd(Q);
	rep(tc,1,Q){
		scanf("%s",opt);
		if(opt[1]=='u'){
			qs[tc]=1;
			char c;
			while(!islower(c=getchar()));
			s[++n]=c;
		}else{
			qs[tc]=0;
		}
	}
	rep(i,1,n)hs[i]=hs[i-1]*B+s[i]-'a'+1;
	
	reverse(s+1,s+n+1);
	gen(_iG);
	
	rep(i,1,n){
		each(x,_iG[i]){
			x.a=n+1-x.a;
		}
	}
	
	reverse(s+1,s+n+1);
	gen(_G);
	
	int ql=1,qr=0;
	rep(tc,1,Q){
		if(qs[tc]==1){
			++qr;
			solve1(ql,qr);
		}else{
			solve2(ql,qr);
			++ql;
		}
		printf("%d\n",res);
	}
	
	return 0;
}