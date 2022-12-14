#include <cstdio>
#include <cstring>
#include <algorithm>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
const int rev1[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
int rev[100];
il void test(){
	int h,m;
	scanf("%d%d",&h,&m);
	int a,b;
	scanf("%02d:%02d",&a,&b);
	while(1){
		if(rev[a]>=0&&rev[a]<m&&rev[b]>=0&&rev[b]<h){
			printf("%02d:%02d\n",a,b);
			return;
		}
		if(++b==m)
			b=0,a=(a+1)%h;
	}
}
int main(){
	for(int i=0; i<10; ++i)
		for(int j=0; j<10; ++j)
			if((~rev1[i])&&(~rev1[j]))
				rev[i*10+j]=rev1[j]*10+rev1[i];
			else
				rev[i*10+j]=-1;
//	test();
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}