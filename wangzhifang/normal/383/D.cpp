//CF383D
#include <cstdio>
#include <cstring>
using namespace std;
#define mod 1000000007
#define max_suma 10000
int sum1[max_suma<<1|1],tmp1[max_suma<<1|1];
void madd(int&x,const int&y){
	(x+=y)>=mod&&(x-=mod);
}
int main(){
	int n,m,*sum=sum1+max_suma,*tmp=tmp1+max_suma;
	scanf("%d",&n),m=0;
	memset(sum1,0,sizeof(sum1)),memset(tmp1,0,sizeof(tmp1));
	int ans=0;
	for(int x; n; --n){
		memset(tmp1,0,sizeof(tmp1)),++sum[0]==mod&&(sum[0]=0);
		scanf("%d",&x);
		for(int i=-m,y; i<=m; ++i)
			if((y=sum[i]))
				madd(tmp[i-x],y),madd(tmp[i+x],y);
		memcpy(sum1,tmp1,sizeof(tmp1));
		m+=x,madd(ans,sum[0]);
	}
	printf("%d\n",ans);
	return 0;
}