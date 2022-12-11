#include <cstdio>
using namespace std;
typedef long long ll;
#define max_n 1716
int num[max_n+1];
ll ans[13];
int main(){
	int cnt=0;
	for(int i=(1<<6)-1; i<(1<<13); ){
		num[++cnt]=i;
		int x=i&(-i);
		int y=i+x;
		i=y|(((i&(~y))/x)>>1);
	}
	int n;
	scanf("%d",&n);
	for(int i=0; i<13; ++i){
		int cnt=0;
		for(int j=1; j<=n; ++j)
			if((num[j]&(1<<i)))
				++cnt;
		if(cnt){
			putchar('?');
			printf(" %d",cnt);
			for(int j=1; j<=n; ++j)
				if((num[j]&(1<<i)))
					printf(" %d",j);
			putchar('\n');
			fflush(stdout);
			scanf("%lld",ans+i);
		}
		else
			ans[i]=0;
	}
	putchar('!');
	for(int i=1; i<=n; ++i){
		ll pi=0;
		for(int j=0; j<13; ++j)
			if(!(num[i]&(1<<j)))
				pi|=ans[j];
		printf(" %lld",pi);
	}
	putchar('\n');
	fflush(stdout);
	return 0;
}