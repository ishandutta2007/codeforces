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
int n,lim,a[N],b[N];
LL chk(LL mid){
	//D("chk %lld\n",mid);
	LL sb=0;
	rep(i,1,n){
		int l=1,r=a[i];
		b[i]=0;
		while(l<=r){
			int w=(l+r)>>1;
			if(-3LL*(1LL*w*w+w)+a[i]-1>mid){
				b[i]=w;
				l=w+1;
			}else r=w-1;
		}
		sb+=b[i];
	}
	return sb;
}
priority_queue<pair<LL,int> >q;
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(lim);
	rep(i,1,n)rd(a[i]);
	LL l=-4e18,r=1e10,ans=-1;
	while(l<=r){
		LL mid=(l+r)>>1;
		if(chk(mid)<=lim){
			ans=mid,r=mid-1;
		}else{
			l=mid+1;
		}
	}
	LL cur=chk(ans);
	auto push=[&](int i){
		if(b[i]<a[i]){
			q.emplace(-3LL*(1LL*b[i]*b[i]+b[i])+a[i]-1,i);
		}
	};
	rep(i,1,n)push(i);
	auto upup=[&](){
		int k1,k2;
		tie(k1,k2)=q.top();
		q.pop();
		++b[k2];
		push(k2);
	};
	rep(i,cur+1,lim){
		upup();
	}
	/*rep(i,1,n)if(b[i]<a[i]&&cur<lim&&-3LL*(1LL*b[i]*b[i]+b[i])+a[i]-1==ans){
		++b[i];
	}*/
	rep(i,1,n)pt(b[i],i==n?'\n':' ');
	return 0;
}