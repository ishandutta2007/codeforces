#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using LL=long long;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,K,Q,f[105][55];
LL ans[100005],x[105];
int sgn(LL x){return x==0?0:x<0?-1:1;}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(K);
	rep(i,1,n)rd(x[i]);
	rep(i,1,n)rep(j,1,K)rd(f[i][j]);
	rd(Q);
	vector<tuple<LL,int,int> >qs;
	rep(_,1,Q){
		int pos;
		LL t;
		rd(pos),rd(t);
		qs.eb(t,pos,_);
	}
	sort(qs.begin(),qs.end());
	reverse(qs.begin(),qs.end());
	x[0]=~INFLL;
	auto deal=[&](int opt){
		static LL F[105];
		rep(i,1,n){
			x[i]+=sgn(f[i][opt]);
			F[i]=f[i][opt];
			if(i>1){
				if(x[i]==x[i-1]+1){
					F[i]+=F[i-1];
				}else if(x[i]==x[i-1]){
					if(sgn(F[i-1])!=sgn(F[i-1]+F[i])){
						int j;
						LL cur;
						for(j=i-1,cur=x[i-1];x[j]==cur;--j){
							x[j]=--cur;
						}
						if(j>=1&&x[j]==cur-1){
							F[i-1]+=F[j];
						}
						F[i]+=F[i-1];
					}else{
						x[i]+=1;
						F[i]+=F[i-1];
					}
				}else if(x[i]+1==x[i-1]){
					if(F[i-1]+F[i]>0){
						x[i]+=2;
						F[i]+=F[i-1];
					}else if(F[i-1]+F[i]==0){
						x[i]+=1;
						int j;
						LL cur;
						for(j=i-1,cur=x[i-1];x[j]==cur;--j){
							x[j]=--cur;
						}
						if(j>=1&&x[j]==cur-1){
							F[i-1]+=F[j];
						}
						F[i]+=F[i-1];
					}else{
						int j;
						LL cur;
						for(j=i-1,cur=x[i-1];x[j]==cur;--j){
							x[j]=--cur;
						}
						if(j>=1&&x[j]==cur-1){
							F[i-1]+=F[j];
						}
						if(F[i-1]+F[i]>0){
							x[i]+=1;
							F[i]+=F[i-1];
						}else{
							for(j=i-1,cur=x[i-1];x[j]==cur;--j){
								x[j]=--cur;
							}
							if(j>=1&&x[j]==cur-1){
								F[i-1]+=F[j];
							}
						}
					}
				}
			}
		}
	};
	auto work=[&](LL ll,LL rr){
		while(ll<rr){
			deal((ll++)%K+1);
		}
	};
	LL lst=0;
	while(!qs.empty()){
		LL t;
		int pos,id;
		tie(t,pos,id)=qs.back();
		if(t-lst<=K){
			qs.pop_back();
			work(lst,t);
			lst=t;
			ans[id]=x[pos];
		}else{
			static LL x_[105];
			rep(i,1,n)x_[i]=x[i];
			work(lst,lst+K);
			lst+=K;
			LL tt=(t-lst+K-1)/K;
			rep(i,1,n-1){
				LL w=x_[i+1]-x_[i]-(x[i+1]-x[i]);
				if(w>0){
					tt=min(tt,(x[i+1]-x[i]-K*2)/w);
				}else if(w<0&&x[i+1]-x[i]<=K*2){
					tt=0;
				}
			}
			if(tt<0)tt=0;
			if(tt>=1)--tt;
			rep(i,1,n){
				x[i]+=1LL*tt*(x[i]-x_[i]);
			}
			lst+=tt*K;
		}
	}
	rep(i,1,Q)printf("%lld\n",ans[i]);
	return 0;
}