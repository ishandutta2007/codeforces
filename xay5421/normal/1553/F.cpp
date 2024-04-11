// author: xay5421
// created: Thu Jul 22 23:52:49 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int B=650;
const int N=300005;
namespace ds{
	int bel[N],bl[N/B+5],br[N/B+5];
	LL sum0[N/B+5],sum1[N];
	int cnt0[N/B+5],cnt1[N];
	void init(){
		memset(bl,-1,sizeof(bl));
		rep(i,0,N-1){
			bel[i]=i/B+1;
			if(bl[bel[i]]==-1)bl[bel[i]]=i;
			br[bel[i]]=i;
		}
	}
	void add(int x){
		per(i,x,bl[bel[x]])sum1[i]+=x,++cnt1[i];
		per(i,bel[x]-1,1)sum0[i]+=x,++cnt0[i];
		//per(i,x,0)sum1[i]+=x,++cnt1[i];
	}
	LL asksum(int x){ // >=x
		return sum1[x]+sum0[bel[x]];
	}
	int askcnt(int x){
		return cnt1[x]+cnt0[bel[x]];
	}
	
}
int n,a[N];
LL w[B+5],w2[B+5];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	LL res=0;
	ds::init();
	rep(i,1,n){
		//if(i%1000==0)D("i=%d\n",i);
		rd(a[i]);
		if(a[i]<=B){
			res+=w[a[i]];
			++w2[a[i]];
		}else{
			int cnt_=0;
			LL sum_=0;
			per(x,300000/a[i],0){
				// [a[i]*x,a[i]*(x+1))
				int cnt=ds::askcnt(a[i]*x);
				LL sum=ds::asksum(a[i]*x);
				res+=(sum-sum_)-1LL*(cnt-cnt_)*x*a[i];
				cnt_=cnt,sum_=sum;
			}
			rep(j,1,B){
				res+=1LL*w2[j]*(a[i]%j);
			}
			cnt_=ds::askcnt(B+1),sum_=ds::asksum(B+1);
			for(int l=B+1,r;l<=a[i];l=r+1){
				r=a[i]/(a[i]/l);
				int cnt=ds::askcnt(r+1);
				LL sum=ds::asksum(r+1);
				res+=1LL*(cnt_-cnt)*a[i]-1LL*(sum_-sum)*(a[i]/l);
				cnt_=cnt,sum_=sum;
			}
			res+=1LL*cnt_*a[i];
			//rep(j,1,i-1)res+=a[i]%a[j];
		}
		rep(j,1,B)w[j]+=a[i]%j+j%a[i];
		ds::add(a[i]);
		pt(res,' ');
	}
	return 0;
}