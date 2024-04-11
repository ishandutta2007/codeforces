#include <cstdio>
#include <algorithm>
#include <cstring>

typedef long long lli;
const lli mod=1e9+7;
int n;
lli cache[2][5011],s[2][5011];
int main() {
	scanf("%d",&n);
	char ch;
	scanf(" %c",&ch);
	
	cache[0][1]=s[0][1]=1;
	int mx=1,cur=1,pr=0;
	lli sum=1;
	for(int i=1;i<n;i++) {
		for(int j=1;j<=n+5;j++) cache[cur][j]=s[cur][j]=0;
		if(ch=='s') {
			for(int j=1;j<=mx;j++) cache[cur][j]=(s[pr][mx]-s[pr][j-1])%mod;
		}
		else {
			cache[cur][1]=0;
			for(int j=1;j<=mx;j++) cache[cur][j+1]=cache[pr][j];
			mx++;
		}
		for(int j=1;j<=mx;j++) s[cur][j]=(s[cur][j-1]+cache[cur][j])%mod;
		std::swap(pr,cur);
		scanf(" %c",&ch);
	}
	lli res=s[pr][mx];
	while(res<0) res+=mod;
	printf("%lld\n",res%mod);
	return 0;
}