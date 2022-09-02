// author: xay5421
// created: Fri Sep 10 22:50:30 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=200005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n,L;
struct node{
	LL t,x,y;
}a[N];
int main(){
	rd(n),rd(L);
	rep(i,1,n)rd(a[i].t),rd(a[i].x),rd(a[i].y);
	rep(i,1,n){
		if((((a[i].x-a[i-1].x)+(a[i].y-a[i-1].y))&1)!=((a[i].t-a[i-1].t)&1)||abs(a[i].x-a[i-1].x)+abs(a[i].y-a[i-1].y)>a[i].t-a[i-1].t){
			puts("NO"),exit(0);
		}
	}
	sort(a+1,a+1+n,[&](const node&x,const node&y){return x.t%L!=y.t%L?x.t%L<y.t%L:x.t<y.t;});
	LL vx=0,vy=0;
	bool flg=0;
	auto xay_div=[&](auto k1,auto k2){
		auto cur=lldiv(k1,k2);
		if(cur.rem!=0)puts("NO"),exit(0);
		return cur.quot;
	};
	auto xay_assert=[&](auto flg){
		if(!flg){
			puts("NO"),exit(0);
		}
	};
	rep(i,0,n-1){
		if(a[i].t%L==a[i+1].t%L){
			LL dt=(a[i+1].t-a[i].t)/L;
			if(flg==0){
				flg=1;
				vx=xay_div(a[i+1].x-a[i].x,dt);
				vy=xay_div(a[i+1].y-a[i].y,dt);
			}else{
				xay_assert(vx==xay_div(a[i+1].x-a[i].x,dt));
				xay_assert(vy==xay_div(a[i+1].y-a[i].y,dt));
			}
		}
	}
	auto sol=[&](auto vx,auto vy){
		string s;
		rep(i,1,n){
			if(a[i].t%L>a[i-1].t%L){
				LL dt=a[i].t%L-a[i-1].t%L;
				LL dx=(a[i].x-(a[i].t/L)*vx)-(a[i-1].x-(a[i-1].t/L)*vx);
				LL dy=(a[i].y-(a[i].t/L)*vy)-(a[i-1].y-(a[i-1].t/L)*vy);
				xay_assert(abs(dx)+abs(dy)<=dt);
				while(dt--){
					if(dx>0)s+="R",--dx;
					else if(dx<0)s+="L",++dx;
					else if(dy>0)s+="U",--dy;
					else s+="D",++dy;
				}
			}
		}
		if(SZ(s)<L){
			LL dt=L-SZ(s);
			LL dx=vx-(a[n].x-(a[n].t/L)*vx);
			LL dy=vy-(a[n].y-(a[n].t/L)*vy);
			xay_assert(abs(dx)+abs(dy)<=dt);
			while(dt--){
				if(dx>0)s+="R",--dx;
				else if(dx<0)s+="L",++dx;
				else if(dy>0)s+="U",--dy;
				else s+="D",++dy;
			}
		}
		cout<<s<<endl,exit(0);
	};
	if(flg){
		sol(vx,vy);
	}
	struct node{
		LL x,y,k,tot;
	};
	vector<node>lims;
	auto deal=[&](auto A,auto B){
		bool rev=0;
		if(A.t<B.t)swap(A,B),rev=1;
		LL k=(A.t-B.t)/L;
		LL tot=(A.t-B.t)%L;
		LL x_=A.x-B.x;
		LL y_=A.y-B.y;
		if(k==0){
			xay_assert((tot&1)==((x_+y_)&1));
			xay_assert(abs(x_)+abs(y_)<=tot);
		}else{
			lims.push_back((node){x_,y_,k,tot});
		}
	};
	auto special_deal=[&](auto A){
		LL k=(A.t+L-1)/L;
		LL tot=k*L-A.t;
		lims.push_back((node){A.x,A.y,k,tot});
	};
	rep(i,1,n){
		deal(a[i],a[i-1]);
	}
	special_deal(a[n]);
	if(lims.empty()){
		sol(0,L&1);
	}
	auto div_floor=[&](LL x,LL y){
		return (LL)floor((double)x/y);
	};
	auto div_ceil=[&](LL x,LL y){
		return (LL)ceil((double)x/y);
	};
	{
		LL w0=-L;
		for(auto cur:lims){ // x+y>=w0
			w0=max(w0,div_ceil(cur.x+cur.y-cur.tot,cur.k));
		}
		LL w1=L; // x+y<=w1
		for(auto cur:lims){
			w1=min(w1,div_floor(cur.x+cur.y+cur.tot,cur.k));
		}
		LL w2=-L; // x-y>=w2
		for(auto cur:lims){
			w2=max(w2,div_ceil(cur.x-cur.y-cur.tot,cur.k));
		}
		LL w3=L; // x-y<=w3
		for(auto cur:lims){
			w3=min(w3,div_floor(cur.x-cur.y+cur.tot,cur.k));
		}
		rep(x_,w0,w1)if((x_&1)==(L&1)){
			rep(y_,w2,w3)if((y_&1)==(L&1)){
				sol((x_+y_)/2,(x_-y_)/2);
			}
		}
		puts("NO"),exit(0);
	}
	return 0;
}