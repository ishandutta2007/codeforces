#include <stdio.h>
typedef long long ll;
char s[233333]; int m,n;
int main() {
	scanf("%d%d%s",&n,&m,s+1);
	ll ans=n*(ll)(m-1);
	for(int i=1;i<n;++i) if(s[i]!=s[i+1]) ans+=n*(ll)(m-1);
	for(int i=1;i<n;++i) if(s[i]!=s[i+1]) {
		int I=i;
		while(i+2<=n&&s[i+2]==s[i]) ++i;
		ans-=(i-I+1)*(ll)(i-I+2)/2;
	}
	printf("%lld\n",ans);
}