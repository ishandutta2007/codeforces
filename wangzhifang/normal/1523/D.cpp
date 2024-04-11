#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;
#define max_n 200000
#define max_m 60
bool a[max_n+1][max_m+1];
int cnt[max_m+1],b[max_m+1];
unsigned val[max_n+1];
int d[max_m+1];
int t[32768];
bool otp[max_m+1];
int main(){
	srand(time(0));
	int n,m,p;
	scanf("%d%d%d",&n,&m,&p),memset(cnt,0,sizeof(cnt));
	for(int i=1; i<=n; ++i)
		for(int j=1,x; j<=m; ++j){
			scanf("%1d",&x);
			a[i][j]=x;
			if(x)
				++cnt[j];
		}
	int k=0;
	for(int i=1,lim=(n+1)/2; i<=m; ++i)
		if(cnt[i]>=lim)
			b[++k]=i;
	if(!k){
		for(int i=m; i; --i,putchar('0'));
		return 0;
	}
	bool flg=1;
	for(int i=1; i<=n; ++i){
		unsigned v=0;
		for(int j=k; j; --j)
			v=v<<1|unsigned(a[i][b[j]]);
		val[i]=v;
		if(v&&v!=(1u<<k)-1)
			flg=0;
	}
	if(flg){
		unsigned ans=(1<<k)-1;
		memset(otp,0,sizeof(otp));
		for(; ans; ans&=ans-1)
			otp[b[__builtin_ctz(ans)+1]]=1;
		for(int i=1; i<=m; ++i)
			putchar(otp[i]?'1':'0');
		return 0;
	}
	random_shuffle(val+1,val+n+1);
	unsigned ans=0;
	int tot=0;
	for(int i=min(n,50); i; --i){
		unsigned v=val[i];
//		printf("%d\n",v);
		if(!v)
			continue;
		int cnt=0;
		for(unsigned x=v; x; x&=x-1,++cnt)
			d[__builtin_ctz(x)]=cnt;
		memset(t,0,sizeof(t));
		for(int i=1; i<=n; ++i){
			unsigned x=v&val[i];
			if(x){
				unsigned tmp=0;
				for(; x; x&=x-1)
					tmp|=1<<d[__builtin_ctz(x)]/*,printf("*%d\n",__builtin_ctz(x))*/;
//				printf("&%u\n",tmp);
				++t[tmp];
			}
		}
		for(int l=1<<cnt,i=1; i<l; i<<=1)
			for(int*a=t+l-i,*b=t+l; a>t; a-=i-1,b-=i-1)
				for(int*c=a; (--a,--b)>=c; *a+=*b);
		for(int i=1<<cnt,lim=(n+1)/2; --i; )
			if(t[i]>=lim){
				int p=__builtin_popcount(i);
//				printf("%d(%d):%d\n",i,p,t[i]);
				if(p>tot){
					unsigned x=v,y=i,pos=0;
					for(; x; x&=x-1,y>>=1){
						unsigned lb=x&(-x);
						if((y&1))
							pos|=lb;
					}
//					printf("&&%d\n",pos);
					tot=p,ans=pos;
				}
			}
	}
	memset(otp,0,sizeof(otp));
	for(; ans; ans&=ans-1)
		otp[b[__builtin_ctz(ans)+1]]=1;
	for(int i=1; i<=m; ++i)
		putchar(otp[i]?'1':'0');
	return 0;
}