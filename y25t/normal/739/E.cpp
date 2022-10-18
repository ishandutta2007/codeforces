#include<cstdio>
#include<algorithm>
#define pii std::pair<int,int>
#define mp std::make_pair
#define fir first
#define sec second
#define lf long double
#define eps 1e-11
#define N 2005

int n,a,b;

lf p[N],q[N];

inline std::pair<pii,lf> dp(lf x,lf y){
	static lf f[N];
	static int ca[N],cb[N];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		ca[i]=ca[i-1];
		cb[i]=cb[i-1];
		if(f[i]<f[i-1]+p[i]-x+eps){
			f[i]=f[i-1]+p[i]-x;
			ca[i]=ca[i-1]+1;
			cb[i]=cb[i-1];
		}
		if(f[i]<f[i-1]+q[i]-y+eps){
			f[i]=f[i-1]+q[i]-y;
			ca[i]=ca[i-1];
			cb[i]=cb[i-1]+1;
		}
		if(f[i]<f[i-1]+p[i]+q[i]-p[i]*q[i]-x-y+eps){
			f[i]=f[i-1]+p[i]+q[i]-p[i]*q[i]-x-y;
			ca[i]=ca[i-1]+1;
			cb[i]=cb[i-1]+1;
		}
	}
	return mp(mp(ca[n],cb[n]),f[n]+x*a+y*b);
}

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for(int i=1;i<=n;i++)
		scanf("%LF",&p[i]);
	for(int i=1;i<=n;i++)
		scanf("%LF",&q[i]);
	lf L=0,R=1,l,r;
	while(L+eps<R){
		lf Mid=(L+R)/2;
		l=0,r=1;
		while(l+eps<r){
			lf mid=(l+r)/2;
			if(dp(Mid,mid).fir.sec<b)
				r=mid;
			else
				l=mid;
		}
		if(dp(Mid,l).fir.fir<a)
			R=Mid;
		else
			L=Mid;
	}
	printf("%.4LF\n",dp(L,l).sec);
}