#include <cstdio>
#include <cstring>
#define cs const
#define il __inline__ __attribute__((always_inline))
using namespace std;
typedef cs int& ci;
typedef long long ll;
char s[100002];
ll ton[256];
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	ll ans=0;
	for(char c='a'; c<='z'; ++c){
		int cnt=0;
		for(int i='a'; i<='z'; ++i)
			ton[i]=0;
		for(int i=1; i<=n; ++i){
			ton[s[i]]+=cnt;
			if(s[i]==c)
				++cnt;
		}
		for(int i='a'; i<='z'; ++i)
			if(ton[i]>ans)
				ans=ton[i];
		if(cnt>ans)
			ans=cnt;
	}
	printf("%lld\n",ans);
	return 0;
}