#include <cstdio>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
char s[12];
il void test(){
	scanf("%s",s+1);
	int ans=10,cnt[2]={0,0};
	for(int i=1; i<ans; ++i){
		if(s[i]!='0'){
			if(s[i]=='1')
				++cnt[i&1];
			else
				(i&1)&&(++cnt[1]);
		}
//		printf("%d:(%d,%d)\n",i,cnt[0],cnt[1]);
		if(cnt[1]-cnt[0]>(11-i)/2){
			ans=i;
			break;
		}
	}
	cnt[0]=cnt[1]=0;
	for(int i=1; i<ans; ++i){
		if(s[i]!='0'){
			if(s[i]=='1')
				++cnt[i&1];
			else
				(i&1)||(++cnt[0]);
		}
//		printf("%d:(%d,%d)\n",i,cnt[0],cnt[1]);
		if(cnt[0]-cnt[1]>(10-i)/2){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
}
int main(){
	int t;
	for(scanf("%d",&t); t; test(),--t);
	return 0;
}