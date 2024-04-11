#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
constexpr int max_n=100000,max_m=100000,max_s=200000;
typedef long long ll;
int a[max_n+1];
int b[max_m+1];
int l[max_m+2];
int c[max_s+1];
pair<int,int>bb[max_m+1];
bool ans[max_s+1];
int f[max_m+1],g[max_m+1];
il void test(){
	int n,m,s;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%d",a+i);
	s=0;
	for(int i=1,k; i<=m; ++i){
		scanf("%d",&k);
		ll sum=0;
		l[i]=s+1;
		for(int j=1; j<=k; ++j){
			++s;
			scanf("%d",c+s);
			sum+=c[s];
		}
//		printf("b %d: %d\n",i,b[i]);
		bb[i].first=b[i]=(sum-1)/k+1,bb[i].second=i;
		for(int j=0; j<k; ++j)
			c[s-j]=(sum-c[s-j]-1)/(k-1)+1;
//		for(int j=l[i]; j<=s; ++j)
//			printf("c %d(%d): %d\n",j,i,c[j]);
	}
	l[m+1]=s+1;
	sort(a+1,a+n+1);
	sort(bb+1,bb+m+1);
	f[0]=g[0]=0;
	for(int i=1,j=0,k=0; i<m; ++i){
		if(++j>n){
			for(int j=s; j; --j)
				putchar('0');
			putchar('\n');
			return;
		}
		if(a[j]<bb[i].first){
			while(++j<=n&&a[j]<bb[i].first);
			k=j-1;
		}
		f[i]=j,g[i]=k;
//		printf("fg %d: %d %d\n",i,f[i],g[i]);
	}
	for(int i=s; i; --i)
		ans[i]=0;
	int now=a[f[m-1]<n?n:g[m-1]];
	for(int i=l[bb[m].second],ed=l[bb[m].second+1]; i<ed; ++i)
		if(c[i]<=now)
			ans[i]=1;
//	printf("%d: %d\n",bb[m].second,now);
	for(int i=m,j=n,k=0; i>1; --i){
		if(!j||bb[i].first>a[j]){
			if(k)
				k=0;
			else
				break;
		}
		else{
			if(k||j==1||a[j-1]<bb[i].first)
				--j;
			else{
				k=j;
				j-=2;
			}
		}
		if(j<f[i-2]-bool(k))
			break;
		int now=0;
		if(j==f[i-2]-bool(k))
			now=a[g[i-2]];
		else{
			if(k)
				now=a[k];
			else
				now=a[j];
		}
//		printf("%d %d\n",j,k);
//		printf("%d: %d\n",bb[i-1].second,now);
		for(int j=l[bb[i-1].second],ed=l[bb[i-1].second+1]; j<ed; ++j)
			if(c[j]<=now)
				ans[j]=1;
	}
	for(int i=1; i<=s; ++i)
		putchar(ans[i]|'0');
	putchar('\n');
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
//	test();
	return 0;
}