#include <cstdio>
#include <unordered_map>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef unsigned int uint;
typedef cs uint& cu;
typedef long long ll;
typedef unsigned long long ull;
typedef cs ull& cull;
#define max_size 1048576
#define max_n 300000
uint f[max_size+1][3],g[max_size+1];
ull a[max_n+1];
unordered_map<uint,uint>mp;
il uint mex(cu x){
	return x?0:1;
}
uint mex(cu x,cu y){
	return x?(y?0:(x==1?2:1)):(y==1?2:1);
}
uint mex(cu x,cu y,cu z){
//	printf("mex(%u,%u,%u)\n",x,y,z);
	return x?(y?(z?0:(x==1?(y==2?3:2):(y==1?(x==2?3:2):1))):(x==1?(z==2?3:2):(z==1?(x==2?3:2):1))):(y==1?(z==2?3:2):(z==1?(y==2?3:2):1));
}
uint sg(cu x,cu y){
//	printf("sg(%d,%u,%u)\n",int(x),y,z);
	return int(x)>0?f[x][y]:0;
}
uint sg(cull x,cu y,cu st,cu ed){
//	printf("sg(%d,%u,%u,%u,%u)\n",x,y,z,st,ed);
	return ll(x)>0?(x<=ed?f[x][y]:f[(x-st)%(ed-st)+st][y]):0;
}
il void test(){
	uint n,x,y,z;
	scanf("%u%u%u%u",&n,&x,&y,&z);
	cs uint m=max(max(x,y),z);
//	printf("%u\n",m);
	mp.clear();
	mp[0]=0;
	uint st,ed;
//	puts("aaa");
	g[0]=0;
//	printf("mex(%u,%u,%u)=%u\n",0,1,2,mex(0,1,2));
	for(uint i=1; ; ++i){
		f[i][0]=mex(sg(i-x,0),sg(i-y,2),sg(i-z,1)),
		f[i][1]=mex(sg(i-x,0),sg(i-y,2)),
		f[i][2]=mex(sg(i-x,0),sg(i-z,1));
//		printf("%u: %u %u %u\n",i,f[i][0],f[i][1],f[i][2]);
		g[i]=(f[i][2]<<4)|(f[i][1]<<2)|f[i][0];
//		printf("%u\n",g[i]);
		uint now=g[i];
		for(uint j=min(m,i); --j; )
			now|=ull(g[i-j]<<(j*6));
//		printf("%ull\n",now);
		if(mp.count(now)){
			st=mp[now],ed=i;
			break;
		}
		mp[now]=i;
	}
//	printf("st:%u ed:%u\n",st,ed);
//	puts("ready");
	uint sum=0;
	for(uint i=1; i<=n; ++i){
		scanf("%llu",a+i);
		sum^=sg(a[i],0,st,ed);
	}
//	printf("sum %u\n",sum);
	uint ans=0;
	for(uint i=1; i<=n; ++i){
		uint now=sum^sg(a[i],0,st,ed);
//		printf("%u\n",now);
		if(!(now^sg(a[i]-x,0,st,ed)))
			++ans/*,printf("%da\n",i)*/;
		if(!(now^sg(a[i]-y,2,st,ed)))
			++ans/*,printf("%db\n",i)*/;
		if(!(now^sg(a[i]-z,1,st,ed)))
			++ans/*,printf("%dc\n",i)*/;
	}
//	printf("ans: ");
	printf("%u\n",ans);
}
int main(){
	uint t;
	for(scanf("%u",&t); t; test(),--t);
	return 0;
}