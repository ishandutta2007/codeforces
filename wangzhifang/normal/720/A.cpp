#include <cstdio>
#include <cstring>
#define max_n 10000
#define max_m 10000
#define max_siz 10001//max(n+m)
#define cs const
using namespace std;
typedef cs int& ci;
int a[max_siz+1],b[max_siz+1];
int nxt[max_siz+2];
int findnxt(ci u){
	return (nxt[u]==u)?u:(nxt[u]=findnxt(nxt[u]));
}
#define deal(i,j){\
				if((tmp=findnxt(dis1=i+j))>siz){\
					if(i+(eny2-j)>now){\
						puts("NO");\
						return;\
					}\
					if(!--b[now])\
						while(!b[--now]);\
					continue;\
				}\
				(--a[tmp])||(nxt[tmp]=tmp+1);\
			}
void test(){
	int n,m,eny2,k,l,siz;
	scanf("%d%d%d",&n,&m,&k),memset(a,0,sizeof(a)),memset(b,0,sizeof(b));
	eny2=m+1,siz=n+m;
	for(int i=0,x; ++i<=k; ++a[(x>siz)?siz:x]){
		scanf("%d",&x);
		if(x<2){
			for(; ++i<=k; scanf("%*d"));
			scanf("%d",&l);
			for(++l; --l; scanf("%*d"));
			puts("NO");
			return;
		}
	}
	scanf("%d",&l);
	for(int i=0,x; ++i<=l; ++b[(x>siz)?siz:x]){
		scanf("%d",&x);
		if(x<2){
			for(; ++i<=l; scanf("%*d"));
			puts("NO");
			return;
		}
	}
	int now=siz;
	for(; !b[now]; --now);
	nxt[siz+1]=siz+1,b[0]=1;
	for(int i=siz+1; --i; nxt[i]=(a[i]?i:nxt[i+1]));
	if(n>m){
		for(int d=n,ed=n-m; --d>=ed; )
			for(int i=d,j=1,dis1,tmp; ++i<=n; ++j)deal(i,j)
		for(int d=n-m; --d; )
			for(int i=d+1,j=0,dis1,tmp; ++j<=m; ++i)deal(i,j)
		for(int d=-1; ++d<m; )
			for(int i=1,j=d,dis1,tmp; ++j<=m; ++i)deal(i,j)
		puts("YES");
	}
	else{
		for(int d=n; --d; )
			for(int i=d,j=1,dis1,tmp; ++i<=n; ++j)deal(i,j)
		for(int d=-1,ed=m-n; ++d<=ed; )
			for(int i=0,j=d+1,dis1,tmp; ++i<=n; ++j)deal(i,j)
		for(int d=m-n; ++d<m; )
			for(int i=1,j=d,dis1,tmp; ++j<=m; ++i)deal(i,j)
		puts("YES");
	}
}
int main(){
//	freopen("cinema.in","r",stdin);
//	freopen("cinema.out","w",stdout);
	int t=1;
//	scanf("%d",&t);
	for(++t; --t; test());
	return 0;
}