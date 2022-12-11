#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define cs const
#define il __inline__ __attribute__((always_inline))
typedef cs int& ci;
typedef long long ll;
constexpr int max_n=100000;
char str[max_n+2];
il bool cnt(int p){
	if(str[p]=='a')
		return str[p+1]=='b'&&str[p+2]=='c';
	if(str[p]=='b')
		return str[p-1]=='a'&&str[p+1]=='c';
	return str[p-1]=='b'&&str[p-2]=='a';
}
il void test(){
	int n,q;
	scanf("%d%d",&n,&q);
	scanf("\n%s",str+1);
	str[0]=str[n+1]='\0';
	int ans=0;
	for(int i=1,now=1; i<=n; ++i){
		if(str[i]==96+now)
			++now;
		else
			now=(str[i]=='a')+1;
		if(now==4)
			now=1,++ans;
	}
	for(int x; q; --q){
		char ch;
		scanf("%d %c",&x,&ch);
		ans-=cnt(x);
		str[x]=ch;
		ans+=cnt(x);
		printf("%d\n",ans);
	}
}
int main(){
	test();
//	int t;
//	for(scanf("%d",&t); t; test(),--t);
	return 0;
}