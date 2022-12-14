#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
#define max_n 10000
bool a[max_n+1];
il void test(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1,x; i<=n; ++i){
		scanf("%1d",&x);
		a[i]=x;
	}
	int lft=1,rgt=n;
	while(!a[lft])
		if(++lft>n){
			for(int i=n; i; --i,putchar('0'));
			putchar('\n');
			return;
		}
	for(; !a[rgt]; --rgt);
	if(lft<=k)
		for(int i=1; i<lft; ++i)
			a[i]=1;
	else
		for(int i=lft-k; i<lft; ++i)
			a[i]=1;
	if(rgt>=n-k)
		for(int i=n; i>rgt; --i)
			a[i]=1;
	else
		for(int i=rgt+k; i>rgt; --i)
			a[i]=1;
	for(int i=lft,now=0; ++i<=rgt; ){
		if(a[i]){
			if(now<=2*k){
				for(int j=i-now; j<i; ++j)
					a[j]=1;
				if((now&1))
					a[i-((now+1)>>1)]=0;
			}
			else{
				for(int l=i-now,j=i-now+k; --j>=l; )
					a[j]=1;
				for(int j=i-k; j<i; ++j)
					a[j]=1;
			}
			now=0;
		}
		else
			++now;
	}
	for(int i=1; i<=n; ++i)
		putchar(a[i]?'1':'0');
	putchar('\n');
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}